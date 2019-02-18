// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2018 --
//  License:        See the end of this file for license information
//  Created:        December 18, 2018
 
//  Last changed:   $Date: 2018/12/17 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <stdio.h>
#include <stdlib.h>

#include "pgm.h"
#include "shear45.h"

#define IMAGE_DIR       "images/"
#define RESULT_DIR      "results/"
#define IMAGE_FILE      "Colosseo"
#define IMAGE_EXT       ".pgm"
#define PROG_NAME       "shear45.cl"
#define DEFAULT_GRAY    80
#define MAX_LEN         1024
#define DEBUG           0
#define IDX(x,y,w)      ((y)*(w)+(x))


// ---------------------------------------------------------------------
// equal
// ---------------------------------------------------------------------
// compare two matrices

int equal(unsigned char* a, unsigned char* b, int ah, int aw, int bh, int bw) {
    int y, x, res = 1;
    if (ah != bh || aw != bw) return 0;
    for (y=0; y<ah; y++)
        for (x=0; x<aw; x++) 
            if (a[IDX(x,y,aw)] != b[IDX(x,y,aw)]) {
                #if DEBUG
                printf("a[y][x] - b[y][x]=%d\n", a[IDX(x,y,aw)]-b[IDX(x,y,aw)]);
                #endif
                res = 0;
            }
    return res;
}


// ---------------------------------------------------------------------
// shear45_host
// ---------------------------------------------------------------------
// sequential CPU version executed on host

void shear45_host(unsigned char* in, unsigned char** out, 
                  int h, int w, int* oh, int* ow, 
                  unsigned char gray, double* t) {

    int x, y;

    // set size of output matrix
    *ow = w+h;
    *oh = h;

    // allocate output matrix
    *out = malloc((*oh)*(*ow)*sizeof(unsigned char));
    if (*out == NULL)
		clut_panic("failed to allocate output matrix on host");

    // get initial time
    double start = clut_get_real_time();

    // set pixels of output image
    for (y=0; y < *oh; ++y)
        for (x=0; x < *ow; ++x)
            (*out)[IDX(x, y, w+h)] = (x < y || x >= w+y) ? gray : in[IDX(x-y, y, w)];

    // get elapsed time
    *t = clut_get_real_time() - start;
}


// ---------------------------------------------------------------------
// run_test
// ---------------------------------------------------------------------
// perform shear transformation test on input matrix

void run_test(unsigned char* in, unsigned char** out, 
              int h, int w, int* oh, int* ow, unsigned char gray,
              clut_device* dev, char* msg) {

    double t, td;
    unsigned char* out_ok;
    int oh_ok, ow_ok;

    // compute transformation on host
    shear45_host(in, &out_ok, h, w, &oh_ok, &ow_ok, gray, &t);

    // compute transformation on device
    shear45(in, out, h, w, oh, ow, gray, &td, dev);

    // validate our results
    printf("%s\n", msg);
    printf("    CPU took %.3f msec\n", t*1E03);
    printf("    Device took %.3f msec\n", td*1E03);
    printf("    Correctness test: %s\n", equal(*out, out_ok, *oh, *ow, oh_ok, ow_ok) ? 
										 "PASSED" : "FAILED");

    // cleanup
	free(out_ok);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    clut_device     dev;                // device structure
    unsigned char*  in;                 // input matrix on host
    unsigned char*  out;                // output matrix on host
    unsigned char   gray;               // gray level of background
    char*           img_file;			// image file name
    int             h, w;               // num rows and columns of input
    int             oh, ow;             // num rows and columns of output
    int             err;                // misc vars
    char            in_path[MAX_LEN];   // pathname of input image file
    char            out_path[MAX_LEN];  // pathname of output image file

    // set image file name
    if (argc > 1) img_file = argv[1];
    else          img_file = IMAGE_FILE;

    // set background color
    if (argc > 2) gray = atoi(argv[2]);
    else          gray = DEFAULT_GRAY;

    // open device
    clut_open_device(&dev, PROG_NAME);

    // build pathname of input image file
    sprintf(in_path, "%s%s%s", IMAGE_DIR, img_file, IMAGE_EXT);

    // load image file in pgm format
    printf("Open image file: %s\n", in_path);
    err = pgm_load(&in, &h, &w, in_path);
    if (err) clut_panic("failed to load input image file");
    else     printf("Loaded %dx%d image\n", w, h);

    // print device info
    clut_print_device_info(&dev);

    // run test
    run_test(in, &out, h, w, &oh, &ow, gray,
                 &dev, "Running test");

    // build pathname of output image file
    sprintf(out_path, "%s%s%s", 
                RESULT_DIR, img_file, IMAGE_EXT);

    // save output image
    printf("    Saving image: %s\n", out_path);
    err = pgm_save(out, oh, ow, out_path);
    if (err) clut_panic("failed to save output image file");

    // cleanup
    free(in);
    free(out);
    clut_close_device(&dev);
    
    return 0;
}


// Copyright (C) 2018 Camil Demetrescu
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA
