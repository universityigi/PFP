// =====================================================================
//  darken.h
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        May 27, 2013
 
//  Last changed:   $Date: 2013/05/27 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#ifndef __DARKEN__
#define __DARKEN__

#include "clut.h"

void darken(unsigned char* I, unsigned char* O, int h, int w,
            clut_device* dev, double* td);

#endif


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
