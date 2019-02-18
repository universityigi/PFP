// =====================================================================
//  finds.h
// =====================================================================

//  Author:         (c) 2016 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        January 13, 2016

//  Last changed:   $Date: 2016/01/09 15:13:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#ifndef __FINDS__
#define __FINDS__

#include "clut.h"

void finds(const char* pattern, const char* text, char* out, int n,  
           clut_device* dev, double* t);

#endif


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
