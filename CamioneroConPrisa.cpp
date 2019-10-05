//No se incluyen acentos para no intervenir en el funcionamiento del programa

//Problema no. 1
//Camionero con prisa
//Se utilizo una tecnica avida para el diseño del algoritmo
//Su complejidad es lineal O(n), ya que su estructura contienene un ciclo while con condiciones dentro

#include<iostream>
#include<list>
#include <time.h>
#include<stdlib.h>
#include<iterator>
#include <bits/stdc++.h>

using namespace std;


void algoritmoAvido(int e [], int maxGasolineras, int distanciaDF_ACAPULCO, int distanciaSinParar){
   
    list<int> solucion;
    std:: list<int>::iterator it;

    int distanciaActual=0, recorrido=0, i = 0;
    bool pare = false;

    cout<<"Parara en las siguientes distancias: "<<endl;

    while(distanciaActual<distanciaDF_ACAPULCO && i<maxGasolineras){
        distanciaActual+= e[i];
        recorrido+= e[i];
        if(recorrido + e[i+1]> distanciaSinParar){
            solucion.push_back(e[i]);
            cout<<"Parada numero "<<i+1<<" habiendo recorrido "<<recorrido<<" km"<<endl;
            recorrido=0;
            pare=true;
        }//End of if
        else{
        }
        ++i;
    }//End of while

        if(distanciaActual<distanciaDF_ACAPULCO){
            cout<<"No se puede recorrer ese trayecto con ese tanque de gasolina"<<endl;
        }
        if(pare=false){
            cout<<"No fue necesario hacer paradas"<<endl;
        }
}//End of algoritmoAvido

int main(){
    //vars here
    int pesoMax = 0, numElementos=0, pesoElem=0;
    int distanciaSinParar=0, numGasolineras=0,  maxDistancia=0, num=0, distanciaDfAcapulco=380;
    //La distancia entre acapulco y el df es fija 

    cout<<"Distancia sin parar en km que puede recorrer el camion: "<<endl;
    cin>>distanciaSinParar;

    // cout<<"Cantidad de gasolineras existentes: "<<endl;
    // cin>>numGasolineras;

    // cout<<"Maxima distancia entre gasolineras"<<endl;
    // cin>>maxDistancia;

    // //Creando arreglo de elementos
    // int arr[numGasolineras];

    //Se crea el arreglo de distancias (inventadas), para garantizar que entre ellas sumen la distancia DF Acapulco
    //Aunque se puede descomentar la funcion random para aplicarlo a cualquier caso, tambien se debe descomentar la solicitud de numero de gasolineras y distancia maxima entre ellas
    int arr[12]= {45, 23, 41, 36, 19, 30, 9, 23, 19, 31, 52, 53};

    //Para facilitar el problema se crean distancias entre gasolineras random
    cout<<"Las distancias entre gasolineras son: "<<endl;
    //Creando elementos randomizados:
    //srand(time(NULL));
    for(int i=0; i<12; i++){
        //num= (rand()%maxDistancia);
        //arr[i] = num;
        cout<<arr[i]<<" ";
    }//End of for
    cout<<"\n"<<endl;
    
    algoritmoAvido(arr, 12, distanciaDfAcapulco, distanciaSinParar);
    return 0;

}//End of main