// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 13, 2016

//  Last changed:   $Date: 2016/01/13 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blur.h"
#include "pgm.h"


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char* argv[]) {

    int res, w, h;
    unsigned char *in, *out, *out_ok;
    double t;

    if (argc < 3) {
        printf("Usage: %s in-file out-file\n", argv[0]);
        return 1;
    }

    // load input image
    res = pgm_load(&in, &h, &w, argv[1]);
    if (res) 
        exit((fprintf(stderr, "Can't open input file %s\n", argv[1]),1));

    // allocate output image
    out = malloc(h*w);
    out_ok = malloc(h*w);
    if (out == NULL || out_ok == NULL) 
        exit((fprintf(stderr, "Can't allocate memory\n"),1));

    // compute output image -- sequential version
    printf("Computing image - sequential version...\n");
    t = get_real_time();
    blur((const unsigned char*)in, out_ok, w, h);
    printf("-- Operation took: %1.5f sec\n", get_real_time()-t);

    // compute output image -- parallel version
    printf("Computing image - pthread version...\n");
    t = get_real_time();
    blur_mt((const unsigned char*)in, out, w, h);
    printf("-- Operation took: %1.5f sec\n", get_real_time()-t);

    // compare results
    printf("Correctness check: %s\n", 
        memcmp(out, out_ok, w*h) ? "FAILED" : "PASSED");

    // save output image
    res = pgm_save(out, h, w, argv[2]);
    if (res) 
        exit((fprintf(stderr, "Can't open output file %s\n", argv[2]),1));

    // free memory
    free(in);
    free(out);
    free(out_ok);

    return 0;
}

// Copyright (C) 2016 Camil Demetrescu

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
