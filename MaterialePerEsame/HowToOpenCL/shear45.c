// =====================================================================
//  shear45.c
// =====================================================================

//  Author:         (c) 2018 --
//  License:        See the end of this file for license information
//  Created:        December 18, 2018
 
//  Last changed:   $Date: 2018/12/18 17:00:00 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

//stessa cosa copio e incollo da un esempio e cambio il nome del kernel qui 
#include "shear45.h"

#define LOCAL_SIZE  8
#define KERNEL_NAME "shear45"
//stile row_major     
void shear45(unsigned char* in, unsigned char** out, 
             int h, int w, int* oh, int* ow,
             unsigned char gray,
             double* t, clut_device* dev) {
//lascio cosi
    int       err;      // error code
    cl_kernel kernel;   // execution kernel
    cl_mem    din;      // input matrix on device
    cl_mem    dout;     // output matrix on device
    cl_event  evt;      // performance measurement event
//qui copio e incollo il codice del main che alloca lo spazio ricorda di vedere i parametri sono giusti 
    // set output matrix size
    *oh = h;
    *ow = w+h;

    // allocate output matrix
    *out = malloc((*oh)*(*ow)*sizeof(unsigned char));
    if (!*out) clut_panic("failed to allocate output matrix on host memory");
//lascio cosi
    // create the compute kernel
    kernel = clCreateKernel(dev->program, KERNEL_NAME, &err);
    clut_check_err(err, "failed to create kernel");
//cambio le dimensioni se necessario e il parametro in cambio con i se necessario 
    // allocate input matrix on device as a copy of input matrix on host
    din = clCreateBuffer(dev->context, 
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, 
                         h*w*sizeof(unsigned char), in, NULL);
    if (!din) clut_panic("failed to allocate input matrix on device memory");
//modificare size con ow 
    // allocate output matrix on device
    dout = clCreateBuffer(dev->context, 
                          CL_MEM_WRITE_ONLY, 
                          (*oh)*(*ow)*sizeof(unsigned char), NULL, NULL);
    if (!dout) clut_panic("failed to allocate output matrix on device memory");
// vedo se sono passati tutti i parametri se si e sono corretti lascio così 
//se manca qualcosa aggiungo 
    // set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &din);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &dout);
    err |= clSetKernelArg(kernel, 2, sizeof(int), &h);
    err |= clSetKernelArg(kernel, 3, sizeof(int), &w);
    err |= clSetKernelArg(kernel, 4, sizeof(unsigned char), &gray);
    clut_check_err(err, "failed to set kernel arguments");
//modifico solo le global dim con le dim della matrice out 
    // execute the kernel over the range of our output matrix
    size_t local_dim[]  = { LOCAL_SIZE, LOCAL_SIZE };
    size_t global_dim[] = { *ow, *oh };
    global_dim[0] = ((global_dim[0]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up
    global_dim[1] = ((global_dim[1]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up

    err = clEnqueueNDRangeKernel(dev->queue, kernel, 2, 
                                 NULL, global_dim, local_dim, 0, NULL, &evt);
    clut_check_err(err, "failed to execute kernel");
//stessa cosa qui modifico nel sizeof le dimensioni ow oh  e ricontrolla parametri es out *out
    // copy result from device to host
    err = clEnqueueReadBuffer(dev->queue, dout, CL_TRUE, 0, 
                              (*oh)*(*ow)*sizeof(unsigned char), *out, 0, NULL, NULL);
    clut_check_err(err, "failed to read output result");

    // return kernel execution time
    *t = clut_get_duration(evt);

    // cleanup
    clReleaseMemObject(din);
    clReleaseMemObject(dout);
    clReleaseKernel(kernel);
}
 
