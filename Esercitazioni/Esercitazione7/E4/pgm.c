// =====================================================================
//  pgm.c
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        May 27, 2013

//  Last changed:   $Date: 2013/05/27 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "pgm.h"


// ---------------------------------------------------------------------
// __read_line
// ---------------------------------------------------------------------
static int __read_line(FILE* fp, char* line, size_t size) {
    do {
        if (fgets(line, size, fp) == NULL) return -1;
    }
    while (strchr(line, '#') != NULL);
    return 0;
}


// ---------------------------------------------------------------------
// pgm_load
// ---------------------------------------------------------------------
int pgm_load(unsigned char** img, int* rows, int* cols, char* filename) {
    
    char line[LINE_MAX];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    // read magic code -- must be P2
    if (__read_line(fp, line, sizeof(line))) goto err;
    if (strcmp(line, "P2\n") != 0) goto err;

    // read image width and height
    if (__read_line(fp, line, sizeof(line))) goto err;
    *cols = atoi(strtok(line, " "));
    *rows = atoi(strtok(NULL, " "));

    // read max val and skip it
    if (__read_line(fp, line, sizeof(line))) goto err;

    // allocate matrix
    *img = malloc(*rows**cols);
    if (*img == NULL) goto err;

    // load matrix
    int i;
    for (i=0; i < *rows**cols; i++) {
        if (__read_line(fp, line, sizeof(line))) goto err;
        (*img)[i] = atoi(line);
    }

    fclose(fp);
    return 0;

err:
    fclose(fp);
    return -1;
}


// ---------------------------------------------------------------------
// pgm_save
// ---------------------------------------------------------------------
int pgm_save(unsigned char* img, int rows, int cols, char* filename) {
    
    int i;
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) return -1;

    fprintf(fp, "P2\n");
    fprintf(fp, "# CREATOR: convolution program\n");
    fprintf(fp, "%d %d\n", cols, rows);
    fprintf(fp, "255\n");

    for (i=0; i<rows*cols; i++)
        fprintf(fp, "%u\n", img[i]);

    fclose(fp);

    return 0;
}


// Copyright (C) 2013 Camil Demetrescu

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
