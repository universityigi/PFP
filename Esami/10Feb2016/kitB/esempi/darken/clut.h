// =====================================================================
//  clut.h
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        May 26, 2013

//  Last changed:   $Date: 2013/05/26 13:01:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#ifndef __CLUT__
#define __CLUT__

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

typedef struct clut_device {
    cl_platform_id   platform_id;    // platform id
    cl_device_id     device_id;      // compute device id 
    cl_context       context;        // compute context
    cl_command_queue queue;          // compute command queue
    cl_program       program;        // OpenCL C program
} clut_device;

void        clut_open_device        (clut_device* dev, char* program_name);
void        clut_close_device       (clut_device* dev);
cl_double   clut_get_duration       (cl_event perf_event);
double      clut_get_real_time      ();
void        clut_print_device_info  (clut_device* dev);
void        clut_err_msg            (char* msg);
void        clut_panic              (char* msg);
void        clut_check_err          (int err, char* msg);

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
