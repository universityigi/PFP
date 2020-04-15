#define IDX(x,y,w) ((y)*(w)+(x))
// prendo un esempio e copio il kernel tolgo cosa non serve dal qui sotto
//e aggiungo ciò che mi serve es grigio 
__kernel void shear45(__global unsigned char* in,
                      __global unsigned char* out,
                      int h, int w, unsigned char gray) {

    int x = get_global_id(0);
    int y = get_global_id(1);
// metto a dormire i pixel di cui non ho bisogno 
// li definisco grazie allo shear45 .c che mi da le dimensioni della mtrice di out 
    if (x >= w+h || y >= h) return;
//prendo il corpo del ciclo del main e lo porto nel kernel ricordati di modificar in e out a seconda di come li hai definiti nel kernel  e ricordati di cambiare nome al kernel ora apri il .c
    out[IDX(x, y, w+h)] = (x < y || x >= w+y) ? gray : in[IDX(x-y, y, w)];
}
