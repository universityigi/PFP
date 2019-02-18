/* ============================================================================
 *  mat.h
 * ============================================================================

 *  Author:         (c) 2013 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        April 27, 2013

 *  Last changed:   $Date: 2013/04/27 13:23:37 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.00 $
*/

#ifndef __MAT__
#define __MAT__

typedef struct mat mat;

mat*  mat_new(unsigned n);
void  mat_delete(mat* m);
void  mat_init(mat* a, int seed, int max);
int   mat_mul_check(mat* a, mat* b, mat* c);
int   mat_mul(mat* a, mat* b, mat* c, int ver);
char* mat_mul_get_desc(int ver);

#endif


/* Copyright (C) 2013 Camil Demetrescu

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
