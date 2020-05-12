/* A very basic raytracer example.

from Scratchapixel at 
https://www.scratchapixel.com/code.php?id=3

Instructions to compile this program:
c++ -o raytracer -O3 -Wall raytracer.cpp */
#include <cstdlib>
#include <cstdio>
#include <cmath>
// #include <vector>
#include <fstream>
#include <iostream>
#include <cassert>


#include "cmap.h"

#define SILENT false

struct vec2 { float x, y; };

struct FractConf {
    float c1, c2; 
    int M, N;
};

struct SeneConf{
    int width;
    float left, right, top, bottum;

    const int height() {
        return width*abs(top-bottum)/abs(right-left);
    }
};

vec2 xsqr(vec2 v) {
    return (vec2){ v.x*v.x - v.y*v.y, 2*v.x*v.y };
}
vec2 xpow(vec2 v, int p) {
    float a, x = v.x, y = v.y;

    int i = __builtin_clz(p) + 1;
    int k = 1 << (sizeof(int)*8-i-1);
    for (;i < sizeof(int)*8;++i) {
        a = x*x - y*y;  y = 2*x*y; x = a;
        if (p & k > 0) { a = x*v.x - y*v.y; y = x*v.y + v.x*y; x = a; }
        k = k >> 1;
    }

    return (vec2){ x, y };
}




void xsqr(float &a, float &x, float &y) {
    a = x*x - y*y; y = 2*x*y; x = a;
}


void xpow(float &a, float &b, float &c, int &t1, int &t2, float &x, float &y, int p) {
    b = x; c = y;

    t1 = __builtin_clz(p) + 1;
    t2 = 1 << (sizeof(int)*8-t1-1);
    for (;t1 < sizeof(int)*8;++t1) {
        a = x*x - y*y;  y = 2*x*y; x = a;
        if (p & t2 > 0) { a = x*b - y*c; y = x*c + b*y; x = a; }
        t2 = t2 >> 1;
    }
}

float CalcPixl(FractConf f, float x, float y) {
    int p = 3;

    int j=0, i, k; float a, xa, ya;
    for(; x*x + y*y < f.M*f.M && j < f.N; ++j){
        // v = xsqr( v );  v.x += f.c1; v.y += f.c2;

        // printf("%f\n", v.x);
        // xsqr(a,x,y); x+=f.c1; y+=f.c2;
        xpow(a,ya,xa, i, k ,x,y, p); x+=f.c1; y+=f.c2;

    
        //a = x*x - y*y + f.c1;
        //b = 2*x*y + f.c2;
        //x = a; y = b;
    }
    return float(j)/f.N;
}

float* CalcSeen(FractConf f, SeneConf s) { 
    int h = s.height();
    float dx = (s.right-s.left)/s.width, dy = (s.bottum-s.top)/h;

    float *dat = new float[s.width*h], *pixel = dat;
    for (unsigned y = 0; y < h; ++y) {
        // if(y % 100 == 0) 
        printf("%f\n", 100. * y / h);
        for (unsigned x = 0; x < s.width; ++x, ++pixel) {
            
            *pixel = CalcPixl(f, s.left + x*dx, s.top + y*dy);
        }
    }
    return dat;

}

void SaveAsPPM(const char* nam, const float* img, int w, int h, const unsigned char* cmap) {
    std::ofstream ofs(nam, std::ios::out | std::ios::binary);

    unsigned k;
    ofs << "P6\n" << w << " " << h << "\n255\n";
    for (unsigned i = 0; i < w*h; ++i) {
	    k = (unsigned char)(img[i]*255);
	    ofs << cmap[k*3+0] << cmap[k*3+1] << cmap[k*3+2];
    }
    ofs.close();
}


int main() {
    
    // float c1 = -0.8, c2 = 0.156;
    // FractConf fractA = { c1, c2,  (1 + sqrt(1+4*(c1*c1 + c2*c2))), 800 };

    float c1 = -0.8025, c2 = 0.156;
    FractConf fract = { c1, c2, (1 + sqrt(1+4*(c1*c1 + c2*c2))), 800 };

    SeneConf seen = { 1000, -1.5, 1.5, 1.5, -1.5 };

    float* dat = CalcSeen(fract, seen);

    std::cout << "Saving fig" << std::endl;
    SaveAsPPM("plot_INFERNO.ppm", dat, seen.width, seen.height(), INFERNO_DATA);
    // render("plot_MAGMA.ppm",   dat, K, K, MAGMA_DATA);
    // render("plot_PLASMA.ppm",  dat, K, K, PLASMA_DATA);
    // render("plot_CUBE.ppm",    dat, K, K, CUBE1);
    delete [] dat;
}
