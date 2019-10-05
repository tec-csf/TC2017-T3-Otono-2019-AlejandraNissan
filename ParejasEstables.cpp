//No se incluyen acentos para no intervenir en el funcionamiento del programa

//Problema no.4 Las parejas estables
//La tecnica del algoritmo es avida, ya que eligue la opción más optima en la situación en la que esta. 
//Considerando la restriccion, que las parejas sean estables.
//El algoritmo esta basado en el algoritmo Gale Shapley
//Complejidad: su complejidad es O(n^2), ya que incluye un ciclo while que dentro contiene un ciclo for



#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

//Esto es necesario para poder crear el arreglo 2d con variable
#define N 4 



//Funcion prefiere
bool prefiere(int preferencias[2*N][N], int mujer, int hombre, int hombreComprometido){
    //Va a iterar en las preferencias de la mujer para ver a quien prefiere 
    for(int i=0; i <N; i++){
        if(preferencias[mujer][i]== hombreComprometido){
            return true;
        }//Regresa que si true si prefiere al hombre con el que ya esta comprometido
        if(preferencias[mujer][i]==hombre){
            return false;
        }//Regresa false si prefiere estar con el nuevo hombre
    }//End of for
}//End of function prefiere

void crearParejas(int preferencias [2*N][N]){
    int i=0, j=0;
    //Dice que hombre es pareja de que mujer
    int parejasDeMujeres[N];
    
    //Dice si los ombres estan libres
    bool disponibilidadHombres[N];

    //Aqui se inicializan los valores
    for(int i = 0; i<N; i++){
        parejasDeMujeres[i]=-1;
        disponibilidadHombres[i]= false;
    }//End of for
    
    int contadorLibres = N;
    
    while(contadorLibres>0){
        int hombre;
        //Aqui se revisa cuál es el primer hombre libre
        for(hombre=0; hombre<N; hombre++){
            if(disponibilidadHombres[hombre]==false){
                break;}
        }
        //Checar posibilidad con cada mujer y preferencias de hombre
        for(i=0; i<N && disponibilidadHombres[hombre] == false; i++){
            int mujer = preferencias[hombre][i];

            //Aqui se revisa si no tiene pareja
            if(parejasDeMujeres[mujer-N]==-1){
                parejasDeMujeres[mujer-N] = hombre;
                disponibilidadHombres[hombre]= true;
                contadorLibres--;
            }//End of if

            else{
                int hombreComprometido = parejasDeMujeres[mujer-N];

                //Checa si prefiere al otro hombre, esto es para garantzar estabilidad
                
                if(prefiere(preferencias, mujer, hombre, hombreComprometido)==false){
                    parejasDeMujeres[mujer-N]=hombre;
                    disponibilidadHombres[hombre]=true;
                    disponibilidadHombres[hombreComprometido]=false;
                }//End of if
            }//End of else
        }//End of for
    }//End of while

    //Impresión de resultados    
    for(int i=0; i<N; i++){
        cout<<"Mujer "<<i+N<<" con el hombre: "<<parejasDeMujeres[i]<<endl;
    }//End of for

    //Impresion de la solucion
    
}




int main(){
    //Los hombres son 1, 2, 3, 4
    //Las mujeres son 5, 6, 7, 8

    int preferencias [N*2][N] ={{7, 5, 6, 4}, {7, 6, 4, 5}, {5, 4, 6, 7}, {5, 6, 6, 4},{3, 1, 2, 0},{0, 2, 3, 1},{0, 1, 2, 3},{3, 2, 1, 0}};
    crearParejas(preferencias);

    return 0;
}//End of main

//Se revisaron las siguientes fuentes y se baso el codigo en eso
//https://www.geeksforgeeks.org/stable-marriage-problem/
//https://www.youtube.com/watch?v=Qcv1IqHWAzg
//https://www.youtube.com/watch?v=LtTV6rIxhdo