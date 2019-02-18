// =====================================================================
//  clut.c
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        May 26, 2013

//  Last changed:   $Date: 2013/05/26 13:01:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "clut.h"

#define MAX_SOURCE_SIZE 65536
#define MAX_STR_LEN     1024


// prototypes of private functions
static cl_program __clut_load_program(clut_device* dev, 
                                      char* program_name);


// ---------------------------------------------------------------------
// clut_open_device
// ---------------------------------------------------------------------
void clut_open_device(clut_device* dev, char* program_name) {

    int err;

    // connect to a compute device
    err = clGetPlatformIDs(1, &dev->platform_id, NULL);
    clut_check_err(err, "no OpenCL platform available");

    // try to connect to a GPU
    err = clGetDeviceIDs(dev->platform_id, 
                         CL_DEVICE_TYPE_GPU, 1, 
                         &dev->device_id, NULL);

    if (err != CL_SUCCESS) {

        // if no GPU is available, use CPU
        err = clGetDeviceIDs(dev->platform_id, 
                             CL_DEVICE_TYPE_CPU, 1, 
                             &dev->device_id, NULL);

        clut_check_err(err, "no CPU or GPU device available");
    }

    // create a compute context 
    dev->context = clCreateContext(0, 1, &dev->device_id, NULL, NULL, &err);
    clut_check_err(err, "failed to create device context");

    // create a command queue with profiling enabled
    dev->queue = clCreateCommandQueue(dev->context, dev->device_id, 
                                      CL_QUEUE_PROFILING_ENABLE, &err);
    clut_check_err(err, "failed to create a command queue");

    // load OpenCL C program to be executed on device
    dev->program = __clut_load_program(dev, program_name);
}


// ---------------------------------------------------------------------
// clut_close_device
// ---------------------------------------------------------------------
void clut_close_device(clut_device* dev) {
    clReleaseProgram(dev->program);
    clReleaseCommandQueue(dev->queue);
    clReleaseContext(dev->context);
}


// ---------------------------------------------------------------------
// clut_get_duration
// ---------------------------------------------------------------------
cl_double clut_get_duration(cl_event perf_event) {

    cl_ulong start = 0, end = 0;

	clGetEventProfilingInfo(perf_event, 
                            CL_PROFILING_COMMAND_START, 
                            sizeof(cl_ulong), &start, NULL);

    clGetEventProfilingInfo(perf_event, 
                            CL_PROFILING_COMMAND_END, 
                            sizeof(cl_ulong), &end, NULL);

    return (cl_double)(end - start)*(cl_double)(1e-09);
}


// ---------------------------------------------------------------------
// clut_get_real_time
// ---------------------------------------------------------------------
double clut_get_real_time() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// clut_print_device_info
// ---------------------------------------------------------------------
void clut_print_device_info(clut_device* dev) {

    int err;
    char opencl_version[MAX_STR_LEN]; // opencl version string
    char vendor[MAX_STR_LEN];         // vendor string
    char deviceName[MAX_STR_LEN];     // device name    
    cl_uint numberOfCores;            // number of cores of on a device
    cl_long amountOfMemory;           // amount of memory on a device
    cl_uint clockFreq;                // clock frequency of a device
    cl_ulong maxAllocatableMem;       // maximum allocatable memory
    cl_ulong localMem;                // local memory for a device
    cl_bool available;                // tells if device is available
    size_t device_wg_size;            // max number of work items in a 
                                      // work group

    int f = 23;

    // scan in device information
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_NAME");

    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_VENDOR");

    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_OPENCL_C_VERSION, sizeof(opencl_version),
                          opencl_version, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_OPENCL_C_VERSION");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numberOfCores), 
                          &numberOfCores, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_MAX_COMPUTE_UNITS");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(amountOfMemory), 
                          &amountOfMemory, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_GLOBAL_MEM_SIZE");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(clockFreq), 
                          &clockFreq, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_MAX_CLOCK_FREQUENCY");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(maxAllocatableMem), 
                          &maxAllocatableMem, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_MAX_MEM_ALLOC_SIZE");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_LOCAL_MEM_SIZE, sizeof(localMem), 
                          &localMem, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_LOCAL_MEM_SIZE");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_AVAILABLE, sizeof(available), 
                          &available, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_AVAILABLE");
    
    err = clGetDeviceInfo(dev->device_id, 
                          CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(device_wg_size), 
                          &device_wg_size, NULL);
    clut_check_err(err, "failed to retrieve CL_DEVICE_MAX_WORK_GROUP_SIZE");

    // print out device info
    printf("Device info:\n");
    printf("    %-*s %s\n", f, "Name:", deviceName);
    printf("    %-*s %s\n", f, "Vendor:", vendor);
    printf("    %-*s %s\n", f, "OpenCL version:", opencl_version);
    printf("    %-*s %s\n", f, "Available:", available ? "Yes" : "No");
    printf("    %-*s %u\n", f, "Compute units:", numberOfCores);
    printf("    %-*s %u MHz\n", f, "Clock frequency:", clockFreq);
    printf("    %-*s %0.00f MB\n", f, "Global memory:", (double)amountOfMemory/1048576);            
    printf("    %-*s %0.00f MB\n", f, "Max allocatable memory:", (double)maxAllocatableMem/1048576);
    printf("    %-*s %u KB\n", f, "Local memory:", (unsigned int)localMem);
    printf("    %-*s %u\n", f, "Max work group size:", (unsigned int)device_wg_size);    
}


// ---------------------------------------------------------------------
// clut_err_msg
// ---------------------------------------------------------------------
void clut_err_msg(char* msg){
    fprintf(stderr, "Error: %s\n", msg);
}


// ---------------------------------------------------------------------
// clut_panic
// ---------------------------------------------------------------------
void clut_panic(char* msg) {
    clut_err_msg(msg);
    exit(1);    
}


// ---------------------------------------------------------------------
// clut_check_err
// ---------------------------------------------------------------------
void clut_check_err(int err, char* msg) {
    if (err == CL_SUCCESS) return;
    clut_panic(msg);
}


// ---------------------------------------------------------------------
// __clut_load_program
// ---------------------------------------------------------------------
cl_program __clut_load_program(clut_device* dev, char* program_name) {
    
    int err;
    cl_program program = NULL;

    // load the kernel source code into the array source_str
    FILE*   fp;
    char*   source_str;
    size_t  source_size;

    // load source code from file
    fp = fopen(program_name, "r");
    if (fp == NULL) clut_panic("failed to load kernel");

    source_str  = malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    source_str[source_size] = 0;

    fclose(fp);

    // create the compute program from the source buffer
    program = clCreateProgramWithSource(dev->context, 1, 
                                        (const char**) &source_str, NULL, &err);
    clut_check_err(err, "failed to create program");

    // build the program executable
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {

        size_t len;
        char buffer[16384];

        clut_err_msg("failed to build program executable");

        // get OpenCL C compiler messages
        clGetProgramBuildInfo(program, dev->device_id, 
                              CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);

        // write OpenCL C compiler messages to stderr
        fwrite(buffer, len, 1, stderr);

        // bail out
        exit(1);
    }

    return program;
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
