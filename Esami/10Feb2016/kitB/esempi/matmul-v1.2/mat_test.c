/* ============================================================================
 *  mat_test.c
 * ============================================================================

 *  Author:         (c) 2013-2015 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        April 27, 2013

 *  Last changed:   $Date: 2015/12/04 10:11:10 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.00 $
*/

#include "mat.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef N
#define N 10000
#endif

#define SEED1 9361
#define SEED2 1731
#define MAX 100


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv){

    int n = N, v = 0, t = 0;

    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) v = atoi(argv[2]);
    if (argc > 3) t = atoi(argv[3]);

	// allocate matrices
	mat* a = mat_new(n);
	mat* b = mat_new(n);
	mat* c = mat_new(n);

	// initialize matrices
	mat_init(a, SEED1, MAX);
	mat_init(b, SEED2, MAX);

	printf("\n[mat] multiplying matrices (version %d - %s)\n", 
        v, mat_mul_get_desc(v));

    // perform matrix product
	mat_mul(a, b, c, v);

    if (t) {
		printf("[mat] -- checking result\n");
        if (mat_mul_check(a, b, c)) 
        	 printf("[mat] -- test passed\n");
        else printf("[mat] -- ***test failed***\n");
	}

	// deallocate matrices
    mat_delete(a);
    mat_delete(b);
    mat_delete(c);

    return 0;
}


/* Copyright (C) 2013-2015 Camil Demetrescu

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
