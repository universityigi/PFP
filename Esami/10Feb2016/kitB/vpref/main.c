// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 10, 2016

//  Last changed:   $Date: 2016/01/04 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

#include <stdio.h>
#include <string.h>
#include "vpref.h"

  
// ---------------------------------------------------------------------
// vpref_ok
// ---------------------------------------------------------------------
int vpref_ok(const char* a, const char* b, int na, int nb) {
    int i, n = na < nb ? na : nb;
    for (i=0; i<n; i++) if (a[i] != b[i]) return 0;
    return 1;
}


// ---------------------------------------------------------------------
// test
// ---------------------------------------------------------------------
void test(char* msg, const char* a, const char* b) {
    int na = strlen(a);
    int nb = strlen(b);
    printf("%s:\n   a = %s\n   b = %s\n", msg, a, b);
    int res    = vpref(a, b, na, nb);
    int res_ok = vpref_ok(a, b, na, nb);
    printf("   --- Calcolato: %d\n", res);
    printf("   --- Corretto:  %d\n", res_ok);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char* argv[]) {

    test("Test 1", 
         "Questo e' un primo test per verificare la correttezza",
         "Questo e' un primo test");

    test("Test 2", 
         "Questo e' un secondo test",
         "Questo e' un secondo test per verificare la correttezza");

    test("Test 3", 
         "Questo e' un Terzo test",
         "Questo e' un terzo test per verificare la correttezza");

    test("Test 4", 
         "Questo e' un quarto test per verificare la correttezza",
         "Questo e' un quarto test per verificare la correttezza");

    test("Test 5", 
         "Questo e' un quinto test per verificare la correttezza",
         "Questo e' un quinto test per verificare la correttezzA");

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
