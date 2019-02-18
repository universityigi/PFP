// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 10, 2016

//  Last changed:   $Date: 2016/02/10 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "findstr.h"


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// panic
// ---------------------------------------------------------------------
void panic(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);    
}


// ---------------------------------------------------------------------
// findstr_seq
// ---------------------------------------------------------------------
// sequential CPU version

void findstr_seq(const char* pattern, const char* text, 
                 char* out, int n) {

    int p = strlen(pattern);
    int i, m = n - p + 1;

    for (i=0; i<m; i++)
        out[i] = memcmp(text+i, pattern, p) == 0;

    for (; i<n; i++) out[i] = 0;
}


// ---------------------------------------------------------------------
// count_non_zero
// ---------------------------------------------------------------------
// count number of non-zeros

int count_non_zero(const char* str, int n) {
    int i, s = 0;
    for (i=0; i<n; i++) s += str[i] != 0;
    return s;
}


// ---------------------------------------------------------------------
// get_file_size
// ---------------------------------------------------------------------
// compute file size

int get_file_size(FILE* f){
    int size;
    int curr_pos = ftell(f);
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, curr_pos, SEEK_SET);
    return size;
}


// ---------------------------------------------------------------------
// run_test
// ---------------------------------------------------------------------
// perform test

void run_test(const char* pattern, const char* text, int n, char* msg) {

    double start, t, t_ok;
    
    char* out    = malloc(n);
    char* out_ok = malloc(n);
    if (out_ok == NULL || out == NULL) panic("out of memory");

    // compute sequentially
    start = get_real_time();
    findstr_seq(pattern, text, out_ok, n);
    t_ok = get_real_time() - start;

    // compute in parallel
    start = get_real_time();
    findstr(pattern, text, out, n);
    t = get_real_time() - start;

    // validate our results
    printf("%s\n", msg);
    printf("    CPU took %.3f msec\n",    t_ok*1E03);
    printf("    Device took %.3f msec\n", t*1E03);
    printf("    Pattern \"%s\" found %d times sequentially\n", 
                    pattern, count_non_zero(out_ok, n));
    printf("    Pattern \"%s\" found %d times in parallel\n", 
                    pattern, count_non_zero(out, n));
    printf("    Correctness test: %s\n",  
                    memcmp(out, out_ok, n)==0 ? 
					"PASSED" : "FAILED");

    // cleanups
	free(out);
	free(out_ok);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    char*        in_path;           // input image pathname
    char*        pattern;           // string pattern
    char*        text;              // input text
    int          n;                 // input text size

    // args count check
    if (argc < 3) {
        printf("Usage: %s <input-file> <pattern-string>\n", argv[0]);
        return 1;
    }

    // set parameters
    in_path   = argv[1];
    pattern   = argv[2];
    
    if (strlen(pattern) == 0) panic("empty pattern");

    // load text file
    printf("Opening text file: %s\n", in_path);
    FILE* f = fopen(in_path, "rb");
    if (f == NULL) panic("failed to load input text file");
    n = get_file_size(f);
    text = malloc(n);
    if (text == NULL) panic("failed to allocate text block");
    if (n != fread(text, 1, n, f)) panic("failed to read text");
    printf("Loaded text file of %d bytes\n", n);
    fclose(f);

    // print text excerpt
    printf("------\n");
    fwrite(text, 1, 256, stdout);
    printf(" [...] \n------\n");

    // run test
    run_test((const char*)pattern, (const char*)text, n, 
             "Running test");
    
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
