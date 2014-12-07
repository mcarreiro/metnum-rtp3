#include "pixel.cpp"
#include <vector>
#include <cmath>

typedef unsigned int nat;

using namespace std;

class HighQuality{

public:
    HighQuality(){};

    void hacer(vector<vector<Pixel > >& imagen){

        Bilineal bilineal = Bilineal();
        bilineal.hacer(imagen);
        
        double correccion, correccionRojo, correccionAzul, correccionVerde;
		int ant;
        int width = imagen.size();
        int height = imagen[0].size();
        for(int i=2; i< width-2; i++) {
            for(int j=2; j< height-2; j++) {
                //i COLUMNA
                //j FILA
                correccion = correccionRojo = correccionVerde = correccionAzul =  0;
                if (i %2 == 0 && j % 2 == 0){ //ACA HAY AZUL
                    correccion += imagen[i][j-2].azul/8.0;
                    correccion += imagen[i-2][j].azul/8.0;
                    correccion += imagen[i][j+2].azul/8.0;
                    correccion += imagen[i+2][j].azul/8.0;
                    correccion = imagen[i][j].azul/2.0 - correccion;
                    if(correccion <0) correccion = 0;
                    imagen[i][j].verde += correccion;
                }else if (i %2 == 1 && j % 2 == 1){ //ACA HAY ROJO
                    correccion += imagen[i][j-2].rojo/8.0;
                    correccion += imagen[i-2][j].rojo/8.0;
                    correccion += imagen[i][j+2].rojo/8.0;
                    correccion += imagen[i+2][j].rojo/8.0;
                    correccion = imagen[i][j].rojo/2.0 - correccion;
                    if(correccion <0) correccion =0;
                    imagen[i][j].verde += correccion;         
                }
                
                if(imagen[i][j].verde > 255)
					 imagen[i][j].verde = 255;
            }
        }

    };

};
