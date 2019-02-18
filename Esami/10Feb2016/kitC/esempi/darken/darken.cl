#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void darken(__global unsigned char* I, 
                     __global unsigned char* O, 
                     int h, int w) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;

    unsigned pixel = (I[IDX(x,y,w)] / 2);
    if (pixel > 255) pixel = 255;
    O[IDX(x,y,w)] = pixel;
}

