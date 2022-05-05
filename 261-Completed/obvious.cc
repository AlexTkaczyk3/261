#include "inst_compact.h"
#include <iostream>
using namespace std;


const int matrixSize = 10;
const int blockingFactor = 5;
int a[matrixSize][matrixSize];
int b[matrixSize][matrixSize];
int c[matrixSize][matrixSize];

int main() {
    int i, j, k, jj, kk, r;
    // Initialise the matrices arbitrarily
    for (i=0; i < matrixSize; i++){
        for (j=0; j < matrixSize; j++) {
            b[i][j] = i + j; 
            c[i][j] = i - j; 
            a[i][j] = 0;
        }
    }
    
    // More obvious code for matrix multiplication
    for (i = 0; i < matrixSize; i ++) {
	for (j = 0; j < matrixSize; j++) {
	    for (k = 0; k < matrixSize; k++) {
		INST_R(b[i][k]);
		INST_R(c[k][j]);
		INST_R(a[i][j]);
	        a[i][j] += b[i][k] * c[k][j];
	   	INST_W(a[i][j]);
	    }
       	}
    }

    // Display the product
    //for (i=0; i < matrixSize; i++) {
    //    for (j=0; j < matrixSize; j++){
    //        cerr << a[i][j] << ' ';
    //    }
    //    cerr << endl;
    //}
    return 0;
}
