#include <iostream>
#include "testing.cpp"
using namespace std;


template<int N,int M>
void compute_row_sum(short a[N][M],short row_sum[N]){
    for (int row=0;row<N;row++){
         int sum=0;
        for(int col=0;col<M;col++){
            sum=sum+ a[row][col];
        }
        row_sum[row]=sum;
    }
}



int main() {
     const int row=5;
     const int col=5;
     short my_arr[row][col]; // declare our 2-d array.
     short rowSums[row]; // declare array for storing sum of each row.
     fill_2d_array<row,col>(my_arr); // fill my_arr with random values.
     compute_row_sum<row,col>(my_arr,rowSums); // compute sum of each row, and store it to rowSums

    // Print the row sums
    std::cout << "Row Sums:" << std::endl;
    for (int i = 0; i < row; i++) {
        std::cout << "Row " << i << " Sum: " << rowSums[i] << std::endl;
        
    }
    std::cout << "######    ########";

    return 0;
}





