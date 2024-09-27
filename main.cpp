/*-----------------------------------------------------
 * Dato de entrada:  filas, col (int)
 * Dato de Salida:  matriz
 *                  elMayor (int)
 -----------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

void llenarDatos(  int* *pMat, int filas, int col );
void imprimirMatriz( int * *pMat, int filas, int col);

int main()
{ int filas, col;
    int* * pMatriz=nullptr;

    srand(time(nullptr));
    cout << "Filas: "; cin >> filas;
    cout << "Columnas : "; cin >> col;
    //---- dimensionamos la matriz---
   pMatriz = new int*[filas];
   for(int f=0; f<filas; f++)
       pMatriz[f] = new int[col];

   llenarDatos(pMatriz, filas, col);
   imprimirMatriz(pMatriz, filas, col);
   //---- liberamos memoria del heap
   for(int f=0; f<filas; f++)
       delete []pMatriz[f];
   delete []pMatriz;
   pMatriz = nullptr;

    return 0;
}

void llenarDatos(  int* *pMat, int filas, int col )
{
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
            pMat[f][c] = rand() %100 + 1;
}

void imprimirMatriz( int * *pMat, int filas, int col)
{
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(5) << pMat[f][c];
        cout << "\n";
    }
}