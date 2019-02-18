// =====================================================================
//  vpref.c
// =====================================================================

//  Author:         (c) 2016 -- --
//  License:        See the end of this file for license information
//  Created:        Feb 10, 2016

//  Last changed:   $Date: 2016/01/04 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

#include "vpref.h"
#include <immintrin.h>
int vpref(const char* a, const char* b, int na, int nb) {
	int i = 0, n = na < nb ? na : nb;
    for (i=0; i+15<n; i+=16) {
        __m128i va  = _mm_loadu_si128((const __m128i*)(a+i));
        __m128i vb  = _mm_loadu_si128((const __m128i*)(b+i));
        __m128i res = _mm_cmpeq_epi8(va, vb);
        if (!_mm_test_all_ones(res)) return 0;
    }
    for (; i<n; i++) if (a[i] != b[i]) return 0;
    return 1;
}
//~ int vpref_ok(const char* a, const char* b, int na, int nb) {
    //~ int i, n = na < nb ? na : nb;
    //~ for (i=0; i<n; i++) if (a[i] != b[i]) return 0;
    //~ return 1;
//~ }



// Copyright (C) 2016 -- --

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
