// =====================================================================
//  darken.c
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        May 27, 2013

//  Last changed:   $Date: 2013/05/27 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include "darken.h"

#define LOCAL_SIZE  8
#define KERNEL_NAME "darken"


// ---------------------------------------------------------------------
// darken
// ---------------------------------------------------------------------
// data-parallel GPU version

void darken(unsigned char* I, unsigned char* O, int h, int w,
            clut_device* dev, double* td) {

    int       err;      // error code
    cl_kernel kernel;   // execution kernel
    cl_mem    din;      // input matrix on device
    cl_mem    dout;     // output matrix on device
    cl_event  evt;      // performance measurement event

    // create the compute kernel
    kernel = clCreateKernel(dev->program, KERNEL_NAME, &err);
    clut_check_err(err, "failed to create kernel");

    // allocate input matrix on device as a copy of input matrix on host
    din = clCreateBuffer(dev->context, 
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, 
                         h*w*sizeof(unsigned char), I, NULL);
    if (!din) clut_panic("failed to allocate input matrix on device memory");

    // allocate output matrix on device
    dout = clCreateBuffer(dev->context, 
                          CL_MEM_WRITE_ONLY, 
                          h*w*sizeof(unsigned char), NULL, NULL);
    if (!dout) clut_panic("failed to allocate output matrix on device memory");

    // set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &din);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &dout);
    err |= clSetKernelArg(kernel, 2, sizeof(int), &h);
    err |= clSetKernelArg(kernel, 3, sizeof(int), &w);
    clut_check_err(err, "failed to set kernel arguments");

    // execute the kernel over the range of our 2D input data set
    size_t local_dim[]  = { LOCAL_SIZE, LOCAL_SIZE };
    size_t global_dim[] = { w, h };
    global_dim[0] = ((global_dim[0]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up
    global_dim[1] = ((global_dim[1]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up

    err = clEnqueueNDRangeKernel(dev->queue, kernel, 2, 
                                 NULL, global_dim, local_dim, 0, NULL, &evt);
    clut_check_err(err, "failed to execute kernel");

    // copy result from device to host
    err = clEnqueueReadBuffer(dev->queue, dout, CL_TRUE, 0, 
                              h*w*sizeof(unsigned char), O, 0, NULL, NULL);
    clut_check_err(err, "failed to read output result");

    // return kernel execution time
    *td = clut_get_duration(evt);

    // cleanup
    clReleaseMemObject(din);
    clReleaseMemObject(dout);
    clReleaseKernel(kernel);
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
