// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 13, 2016

//  Last changed:   $Date: 2016/01/04 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

#include <stdio.h>
#include <string.h>
#include "decode.h"

#define STR "Tjit#lkbsdr{ jv hrfh uogwwcrf> {ov#ccn!uefitwrkbvwe\"iu#apd0rr\"mp" \
            "gihy!lt\"uoget uke\"tfumu pi vhf#GPU!Oeusfu Ieohrcl!SudljfLkcfqsg " \
            "bv rucoiuhfg dy!whg Gueg Trfvwbue\"Fpxnfaulop;!hivhfu xesviqn!5.3 " \
            "pi vhf#Lkcfqsg,!rr\"(bw {ovu qpulop)!dn{ mdtgr!yetsjrn0"
    
// ---------------------------------------------------------------------
// decode_ok
// ---------------------------------------------------------------------
void decode_ok(const char* key, int m, char* str) {
    int i, n = strlen(str);
    for (i=0; i<n; i++) str[i] -= key[i % m];
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char* argv[]) {

	const char k1[] = { 0, 2, 0, 1, 3 };
	char s1[] = STR;
	char o1[] = STR;

	decode(k1, 5, s1);
	decode_ok(k1, 5, o1);

	printf("------- Calcolato: \n%s\n", s1);
	printf("------- Corretto: \n%s\n", o1);
	printf("------- Esito: %s\n", strcmp(s1,o1)==0 ? "OK":"ERRORE");

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
