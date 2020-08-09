#include <iostream>
#include <string>
#include "mmm.h"
#include <fstream>

using namespace std;
// implement your main program here..ZZ
int main()
{
    std::string input_filename, output_filename;
    std::cout << "\nPlease input the input filename: ";
    std::cin >> input_filename;
    std::cout << "\nPlease input the output filename: ";
    std::cin >> output_filename;
    std::cout << "\ninput file: " << input_filename << std::endl;
    std::cout << "\noutput file: " << output_filename << std::endl;
    //Excetion Hendle-----------------------
    ifstream fileInput;
    fileInput.open(input_filename, ios::in);
    if (!fileInput.is_open()) {
        cout << "sth wrong!!" << endl;
    }
    else {
        cout << "haha sucessful!!" << endl;
    }
    //-------------------------------------
    int nrA;
    fileInput >> nrA;
    int ncA;
    fileInput >> ncA;
    int nrB;
    fileInput >> nrB;
    int ncB;
    fileInput >> ncB;

    double *a = new double[nrA * ncA];

    double *b = new double[nrB * ncB];

    double *c = new double[nrA * ncB];

    //-------------------------------------
    for (int i = 0; i < nrA; i++) {
        for (int j = 0; j < ncA; j++) {
            fileInput >> a[i * ncA + j];
            //cout << a[i*ncA + j] << " ";
        }
        //cout << endl;
    }

    for (int i = 0; i < nrB; i++) {
        for (int j = 0; j < ncB; j++) {
            fileInput >> b[i * ncB + j];
            //cout << b[i*ncB + j] << " ";
        }
        //cout << endl;
    }

    fileInput.close();
    //-------------------------------------
    mmm(nrA, ncA, nrB, ncB, a, b, c);

    ofstream fileOutput;
    fileOutput.open(output_filename, ios::out);

    if (!fileOutput.is_open()) {
        cout << "sth wrong!!" << endl;
    }
    else {
        fileOutput << "c[" << nrA << "][" << ncB << "]"
                   << " = " << endl;

        for (int i = 0; i < nrA; i++) {
            for (int j = 0; j < ncB; j++) {
                fileOutput << c[i * ncB + j] << "\t";
            }
            fileOutput << endl;
        }
        fileOutput << endl;
        //number of floating-point operations, and number of memory references
        fileOutput << "Memory OP:" << endl;
        fileOutput << "Read: " << nrA * ncA + nrB * ncB << " elements" << endl;
        fileOutput << "write: " << nrA * ncB << " elements" << endl;
        fileOutput << endl;
        fileOutput << "Math OP:" << endl;
        fileOutput << nrA * ncA * ncB << " additions" << endl;
        fileOutput << nrA * ncA * ncB << " multiplications" << endl;
    }
    fileOutput.close();
    //-------------------------------------

    delete[] a;

    delete[] b;

    delete[] c;
    //-------------------------------------
    return 0;
}
