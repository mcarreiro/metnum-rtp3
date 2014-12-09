#include <iostream>
#include <fstream>
#include <vector>
#include "pixel.cpp"
#include "vecino.cpp"
#include "bilineal.cpp"
#include "highquality.cpp"
#include "spline.cpp"


#include <sys/time.h>


using namespace std;

typedef unsigned int nat;
timeval start,end_time;
void init_time(){
    gettimeofday(&start,NULL);
}

double get_time(){
    gettimeofday(&end_time,NULL);
    return (1000000*(end_time.tv_sec-start.tv_sec)+(end_time.tv_usec-start.tv_usec))/1000000.0;
}

int main(int argc, char* argv[]) {
    std::ifstream inputFile(argv[1]);

    int height, width;
    nat color;
    inputFile >> height >> width;

    //cout << "C++ altura: " << height << " ancho: " << width << flush << endl;

    vector<vector<Pixel> > imagen;

    imagen.resize(width);

    //Load data
    for(int i=0; i< width; i++) {
        imagen[i].resize(height);
        for (int j = 0; j < height; j++) {
            imagen[i][j] = Pixel();

            inputFile >> color;
            if(i%2 == 0) {
                if(j%2 == 0) {
                    imagen[i][j].azul = color;
                } else {
                    imagen[i][j].verde = color;
                }
            } else {
                if(j%2 == 0) {
                    imagen[i][j].verde = color;
                } else {
                    imagen[i][j].rojo = color;
                }
            }
        }
    }

    string metodo = argv[3];
	  init_time();
    if (metodo == "1"){
        Vecino metodo1 = Vecino();
        metodo1.hacer(imagen);
    }else if (metodo == "2"){
        Bilineal metodo2 = Bilineal();
        metodo2.hacer(imagen);
    }else if (metodo == "3"){
        HighQuality metodo3 = HighQuality();
        metodo3.hacer(imagen);
    }else{
        Spline metodo4 = Spline();
        metodo4.hacer(imagen);
    }
	cout << width << " " <<get_time();
    //cout << "Imprimiendo archivo!"<< flush << endl;

    string output = argv[2];
    ofstream myfile (output);

    for(int a=0; a< width; a++) {
        for (int b = 0; b < height; b++) {
            myfile << a << " " << b << " " << imagen[a][b].rojo << " " << imagen[a][b].verde << " " << imagen[a][b].azul << flush << endl;
        }
    }

    return 0;
}
