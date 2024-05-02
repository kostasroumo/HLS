#include <iostream>
#include <random>
#include <ctime>
#include "mc_scverify.h"


template<int N>
void CCS_BLOCK(compute_row_sum)(short a[N][N], short row_sum[N]) {
  short sum;
  ROW: for (int i=0; i < N; i++) {
    sum=0;
    // row_sum[i] = 0;
    SUM: for (int j=0; j <N; j++) {
    //   row_sum[i] += a[i][j];
    sum+=a[i][j];
    }
    row_sum[i]=sum;
  }
}



CCS_MAIN (int argc, char* argv[]) {
  
  const int N = 3;
  
  short a[N][N];
  short row_sum[N];
  
  
  // Seed RNG
  srand(time(NULL));
  
  // Run Multiple Tests
  const int TESTS = 100;
  for (int t=0; t < TESTS; t++) {
    std::cout << "~~~~~ Test #" << t << " ~~~~~" << std::endl;
    
    // Initialize Array a[N][N]
    for (int i=0; i < N; i++) {
      for (int j=0; j < N; j++) {
        a[i][j] = rand();
      }
    }
    
    // Call DUT
    compute_row_sum<N>(a, row_sum);
    
    // Compute expected result
    short golden[N];
    for (int i=0; i < N; i++) {
      golden[i] = 0;
      for (int j=0; j < N; j++) {
        golden[i] += a[i][j];
      }
    }
    
    // Print out the computed sums and compare to golden
    for (int i = 0; i < N; i++) {
      std::cout << "Row " << i;
      std::cout << ": Expected Sum= " << golden[i];
      std::cout << ", Actual Sum= " << row_sum[i];
      if (golden[i] == row_sum[i]) {
        std::cout << ". CORRECT!" << std::endl;
      } else {
        std::cout << ". WRONG!" << std::endl;
      }
    }
  }
  
  CCS_RETURN(0);
}
