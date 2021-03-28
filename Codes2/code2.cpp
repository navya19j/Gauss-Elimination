#include <iostream>
using namespace std;
#include <string>
#include<math.h>
#include <fstream>
#include<iomanip>

int main(){
    int n; //number of rows of matrix.
    ifstream inFile;
    inFile.open("input2.txt");
    if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
    }
    int i;
    double k;
    i = 0;
    inFile >> n;
    double arr[n][n+1];

    while (inFile){
        for (int i=0 ; i<n ; i++){
            for (int j=0; j<n+1 ; j++){
                inFile>>arr[i][j];
            }
    }
    inFile.close();
    }

    double identity[n][n];
    for (int i=0;i<n;i++){
        for (int j=0; j<n ; j++){
            if (i==j){
                identity[i][j] = 1;
            }
            else{
                identity[i][j] = 0;
                }
            }
        }

    double err = pow(10,-10); // permissible error value
    for (int i =0; i < n ; i++){
        double pivot = arr[i][i];
        int pivot_row = i;
        if (abs(arr[i][i]) < err){
            for (int j= i+1; j<n; j++ ){
                if (abs(arr[j][i]) > abs(arr[i][i]) && abs(arr[j][i]) >= abs(pivot)){
                    pivot = arr[j][i];
                    pivot_row = j;
                }
            }
            for (int k =0 ; k<n+1 ; k++){
                double temp = arr[i][k];
                arr[i][k] = arr[pivot_row][k];
                arr[pivot_row][k] = temp;
                if (k!=n){
                    double temp = identity[i][k];
                    identity[i][k] = identity[pivot_row][k];
                    identity[pivot_row][k] = temp;
                }
            }
        }
        for (int j=0; j<=n;j++){
            arr[i][j] = arr[i][j]/pivot;
        }
        for (int j=0; j<n;j++){
            identity[i][j] = identity[i][j]/pivot;
        }

        for (int k=0; k<n ; k++){
            if (k!=i){
                double alpha = arr[k][i];
                for (int p=0; p <=n; p++){
                    arr[k][p] = arr[k][p] - (arr[i][p]*alpha);
                }   
                for (int p=0; p <n; p++){
                    identity[k][p] = identity[k][p] - (identity[i][p]*alpha);
                }
            }
        }
    }

        // for (int i=0 ; i<n ; i++){
        //     for (int j=0; j<n+1 ; j++){
        //         if (abs(arr[i][j]) < err){
        //             arr[i][j] = 0; //approximate values to 0 when close to error
        //         }
        //         cout << arr[i][j] << " ";
            
        //     }
        //     cout << endl;
        // }

        ofstream myfile_1;
        myfile_1.open("output2.txt");
        if (myfile_1.is_open()){
        myfile_1 << "Solutions to the given set of equations: "<< endl;
        double solns[n];
        for (int i =0; i<n ; i++){
            solns[i] = arr[i][n];
            myfile_1 << solns[i] <<endl;
            
        }
        ifstream inFile1;
        inFile1.open("input2.txt");
        inFile1 >> n;
        double arr1[n][n+1];
        while (inFile1){
        for (int i=0 ; i<n ; i++){
            for (int j=0; j<n+1 ; j++){
                inFile1>>arr1[i][j];
            }
    }
    inFile1.close();
    }
    //Verifying A*A-1 = I
        double res[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                res[i][j] = 0;
                for (int k=0;k<n;k++){
                    res[i][j] += arr1[i][k]*identity[k][j];
                }
            }
        }
        ofstream myfile;
        myfile.open("output3.txt");
        if (myfile.is_open()){
        myfile << n << endl;
        // myfile << res << endl ;

        for (int i=0;i<n;i++){
            for (int j=0; j<n;j++){
                    myfile << res[i][j]<< " ";
                }
            myfile << endl;
            }
        }
        }   
    }




