//No se incluyen acentos para no intervenir en el funcionamiento del programa

//Problema no. 3 La subsecuencia comun maxima
//Se utilizo programacion dinamica
//La complejidad es de O(mn), depende del largo de los dos strings X y Y


#include<string>
#include <iostream>
#include<vector>
#include<bits/stdc++.h> 

using namespace std;

int max(int a, int b){
    if(b>a){
        return b;
    }
    else{
        return a;
    }
}//End of max


void funcionSubsecuenciaComunMax(char *x, char *y, int m, int n){
    int maxNum, k=0;
    int tablaDinamica[m+1][n+1];
    
    //Creando la tabla dinamica

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                tablaDinamica[i][j]= 0;
            }//End of if
            else if(x[i-1]==y[j-1]){
                tablaDinamica[i][j] = tablaDinamica[i-1][j-1] +1;
            }
            else{
                tablaDinamica[i][j] = max (tablaDinamica[i][j-1], tablaDinamica[i-1][j]);
            }
            
        }//End of second for
    }//End of first for

    //Para imprimir la tabla dinamica
    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=n; j++){
    //        cout<<tablaDinamica[i][j]<<" ";
    //     }//End of second for
    //     cout<<endl;
    // }//End of first for

    char subsecuencia[tablaDinamica[m-1][n-1]];
    k = tablaDinamica[m-1][n-1];
    int i=m, j=n;

    //Revisando cual es la subsecuencia
    while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                subsecuencia[k-1]=x[i-1];
                i--;
                j--;
                k--;
            }
            else if(tablaDinamica[i-1][j]> tablaDinamica[i][j-1]){
                i--;
            }
            else{
                j--;
            }
    }//End of first for

    cout<<"Subsecuencia maxima: "<<subsecuencia<<endl;


}//End of funcionSubsecuenciaComunMax


int main(){
    //Vars here
    int m=0, n=0;
    char x[]= "printing";
    char y[]= "springtime";

    m = strlen(x);
    n = strlen(y);
    
    funcionSubsecuenciaComunMax(x, y, m, n);

        
    return 0;
}

//Basado en el siguiente video https://www.youtube.com/watch?v=ZfL_z_01I4g
//Y en el siguiente código https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/