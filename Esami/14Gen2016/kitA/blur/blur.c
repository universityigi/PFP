// =====================================================================
//  blur.c
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 13, 2016

//  Last changed:   $Date: 2016/01/13 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <stdio.h>
#include "blur.h"

#define M(mat,i,j,rows) ((mat)[(i)*(rows)+(j)])
#define MIN7 3
#define MAX7 4


// ---------------------------------------------------------------------
// blur
// ---------------------------------------------------------------------
void blur(const unsigned char* A, unsigned char* B, size_t w, size_t h) {
    int i, j, ii, jj;
    for (i=0; i<h; i++)
        for (j=0; j<w; j++) {
            // calcola somma dei toni di grigio nella finestra 7x7
            // centrata nel pixel (i,j)
            int cnt = 0, sum = 0;
            for (ii=i-MIN7; ii<i+MAX7; ii++)
                for (jj=j-MIN7; jj<j+MAX7; jj++)
                    if (ii>=0 && jj>=0 && ii<h && jj<w) {
                        cnt++;
                        sum += M(A,ii,jj,w);
                    }
            // ...e la assegna al pixel (i,j)
            M(B,i,j,w) = sum/cnt;
        }
}



// ---------------------------------------------------------------------
// blur_mt
// ---------------------------------------------------------------------
void blur_mt(const unsigned char* A, unsigned char* B, size_t w, size_t h) {
	// da completare usando pthread...
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
