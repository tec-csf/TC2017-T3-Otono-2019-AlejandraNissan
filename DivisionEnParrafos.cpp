//No se incluyen acentos para no intervenir en el funcionamiento del programa

//Problema no. 2 La división en parrafos
//Usa programacion dinamica
//Su complejidad es O(n^2), ya que se utilizan dos ciclos anidados tanto para llenar la tabla como para revisar el costo y el resultado

#include <string>
#include<iostream>
#include <vector> 
#include <iterator>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void justificar(vector<string> palabras, int longitud){
    //VARS HERE
    int i=0, j=0;
    int matrizCostos [palabras.size()][palabras.size()];

    //Se llena la tabla
    for(i=0; i<palabras.size(); i++){
        matrizCostos[i][i] = longitud - palabras[i].size();
        for(j=i+1; j<palabras.size(); j++){
            matrizCostos[i][j] = matrizCostos[i][j-1] - palabras[j].length()-1;
        }//End of second for
    }//End of first for
    
    //Se unifican negativos
    for(i=0; i<palabras.size(); i++){
        for(j=i; j<palabras.size(); j++){
            if (matrizCostos[i][j]<0){
                matrizCostos[i][j] = INT_MAX; 
            }
            else{
                matrizCostos[i][j] = matrizCostos[i][j] * matrizCostos[i][j];
            }
        }//End of second for
    }//End of first for

    //Estos dos vectores ayudan a checar costo y resultado
    int minCosto[palabras.size()];
    int resultado[palabras.size()];

    for(i=palabras.size()-1; i>=0; i--){
        minCosto[i]= matrizCostos[i][palabras.size()-1];
        resultado[i] = palabras.size();
        for(j=palabras.size()-1; j>i; j--){
            if(matrizCostos[i][j-1]==INT_MAX){
                continue;
            }
            if (minCosto[i]>minCosto[j] + matrizCostos[i][j-1]){
                minCosto[i] = minCosto[j] + matrizCostos[i][j-1];
                resultado[i] = j;
            }
        }//End of second for
    }//End of first for
    
    // //ESTO FUE PARA IMPRIMIR Y REVISAR SI ESTA BIEN 
    // for(i=0; i<palabras.size(); i++){
    //     for(j=i; j<palabras.size(); j++){
    //        cout<<matrizCostos[i][j]<<" ";
    //     }//End of second for
    //     cout<<""<<endl;
    // }//End of first for

     vector<string> final;
    j=0;
    i=0;
    //Imprimiendo la manera más óptima
    
    cout<<"\nLa solucion mas optima tiene un costo de: "<<minCosto[0]<<endl;
    cout<<"La impresion es la siguiente: "<<endl;
    do{
        j = resultado[i];
        for(int k= i; k<j; k++){
            cout<<palabras[k]<<" ";
        }
        cout<<endl;
        i=j;
    }while(j<palabras.size());

   
}//End of justificar
 

int main(){
//Vars here
int numPalabras=0, i=0, longitud=0;
string word;

cout<<"Longitud del parrafo: "<<endl;
cin>>longitud;

cout<<"Cantidad de palabras: "<<endl;
cin>>numPalabras;
vector <string> palabras;

//Llenar arreglo de palabras
for(i=0; i<numPalabras; i++){
    cout<<"Palabra "<<i+1<<": "<<endl;
    cin>>word;
    palabras.push_back(word);
}

justificar(palabras, longitud);
return 0;
}

//El codigo se baso en el siguiente video que explica el algoritmo
//https://www.youtube.com/watch?v=RORuwHiblPc tambien se baso el codigo 
//que viene adjunto en la descripcion