#include <iostream>
using namespace std;
#include <string>
#include<math.h>
#include <fstream>
#include<iomanip>

int main(){
    int n; //number of rows of matrix.
    ifstream inFile;
    inFile.open("input1.txt");
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
    double err = pow(10,-10); // permissible error value
    for (int i =0; i < n-1 ; i++){
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
            }
        }
        for (int j= i+1; j<n; j++ ){
            double alpha = -(arr[j][i])/(pivot);
            for (int k= 0; k < (n+1); k++){
                arr[j][k] = arr[j][k] + alpha*arr[i][k];
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

        double sols[n+1];
        ofstream myfile;
        myfile.open("output1.txt");
        
        for (int i = n-1; i>=0 ; i--){
            double summ = 0;
            for (int j=i+1; j<n ; j++){
                summ += arr[i][j]*sols[n-j];
            }
            sols[n-i] = (arr[i][n]-summ)/(arr[i][i]);               
            }
        if (myfile.is_open()){
        for (int i =1 ; i<=n; i++ ){
            myfile << sols[i] << endl;
            }  
        }
}     