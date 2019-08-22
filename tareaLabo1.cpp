#include <iostream>

using namespace std;
/*------------------------------------------------------------------------------------------------------------------
-----------------------------------------------EJERCICIO 1----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------
*/
/**
 *Suma 2 matrices de 3x3 y lo guarda en otra
 *matrA y matrB son las matrices a sumar
 * matrC es una matriz con 0s quemada donde se guarda el resultado
 * row es la posicion en filas de las matrices
 * col es la posicion en columnas de las matrices
*/
void sumMatrRecursive(int matrA[][3], int matrB[][3], int matrC[][3], int row, int col){
    if(row==2 && col==2){
        matrC[row][col]=matrA[row][col] + matrB[row][col];
        cout << matrC[row][col] <<" ";
        
    } else {
        if(col > 2){
            row++;
            col = 0;
            cout<<endl;
        }else{
            matrC[row][col]=matrA[row][col] + matrB[row][col];
                
            cout << matrC[row][col] <<" ";
            
            col++;
        }
        //Aquí está la recursividad
        sumMatrRecursive(matrA,matrB,matrC,row,col);
    }
}

void sumarMatrices(int A[][3], int B[][3]){
    int C[][3] = {{0,0,0},{0,0,0},{0,0,0}};
    sumMatrRecursive(A,B,C,0,0);
}

//-------------------------------------------------------------------------------------------------------------------
//------------------------------------------EJERCICIO 2--------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
int potenciaRecursiva(int base, int n){
    if(n==1){
        return base;
    }else if(n > 1){
        return potenciaRecursiva(base, n-1) * base;
    }
}

/*-------------------------------------------------------------------------------------------------------------------
----------------------------------------------EJERCICIO 3------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------
*/

/**
*Calcula el minimo valor de un arreglo de forma recursiva
*Arreglo[] Es el arreglo o vector a utilizar
* pos es la posicion del arreglo a utilizar debe comenzar en la longuitud del arreglo-1
* min es la variable del valor minimo donde se va guardando y comienza en el último elemento del Arreglo
*/
int minRecursivo(int Arreglo[], int pos, int min){
    if(pos<0){
        return min;
    }else{
        if(Arreglo[pos]<min){
            min=Arreglo[pos];
        }
        minRecursivo(Arreglo,pos-1,min);
    }
}







int main()
{
    //Ejemplo de Elevar un numero a una potencia de forma recursiva
    cout <<"Ejemplo 5^9"<<endl;
    cout << potenciaRecursiva(5,9) << "\n";
    cout << endl;
        
    //Ejemplo de encontrar el valor mínimo dentro de un Arreglo
    cout << "Valor minimo de el arreglo: {1,4,5,8,2,6}:  ";
    int arr[] = {1,4,5,8,2,6};
    cout << minRecursivo(arr,5,arr[5])<<endl;
    cout << endl;
    
    //Ejemplo de suma de matrices
    cout<<"Suma de matrices\n 1 2 3\n 4 5 6\n 7 8 9 \n+\n 9 8 7\n 6 5 4\n 3 2 1"<<endl;
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matriy[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    sumarMatrices(matrix,matriy);
    return 0;
}
