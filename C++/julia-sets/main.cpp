/* A very basic raytracer example.

from Scratchapixel at 
https://www.scratchapixel.com/code.php?id=3

Instructions to compile this program:
c++ -o raytracer -O3 -Wall raytracer.cpp */
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <cassert>

float c1 = -0.8025, c2 = 0.156;

float calc(float x, float y, float c1, float c2, float M, int N) {
    int j = 0;
    float a, b;
    while(true){
        if(j >= N)
            return 1;
        if(x*x + y*y >= M*M)
            return float(j)/N;
        a = x*x - y*y + c1;
        b = 2*x*y + c2;
        x = a; y = b;
        j++;
    }
}


void render() {
    float c1 = -0.8025, c2 = 0.156;
    float M = (1 + sqrt(1+4*(c1*c1 + c2*c2)))/2;
    int K = 5000;
    float a = -1.5, b = 1.5;
    float c = -1.5, d = 1.5;

    float *image = new float[K*K], *pixel = image;
    int count = 0;
    for (unsigned y = 0; y < K; ++y, count++) {
        if(count % 100 == 0)
            std::cout << float(count) / K << '\n';
        for (unsigned x = 0; x < K; ++x, ++pixel) {
            float xa = a + x*(b-a)/K;
            float ya = c + y*(d-c)/K;
            *pixel = calc(xa, ya, c1, c2, M, 800);
        }
    }
    // Save result to a PPM image
    std::ofstream ofs("./plot1000.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << K << " " << K << "\n255\n";
    for (unsigned i = 0; i < K * K; ++i) {
        ofs << (unsigned char)(image[i] * 255) <<
               (unsigned char)(image[i] * 255) <<
               (unsigned char)(image[i] * 255);
    }
    ofs.close();
    delete [] image;
}

int main() {
    render();

    /*float c1 = -0.8;
    float c2 = 0.156;
    float M = (1 + sqrt(1 + 4*(c1*c1 + c2*c2)))/2.;
    std::cout << calc(0.325, 0.35, c1, c2, M, 800) << std::endl;*/

}
