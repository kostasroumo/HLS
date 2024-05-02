#include <iostream>
#include <random>
#include <ctime>
#include "mc_scverify.h"


void CCS_BLOCK(two_loops)(int A[10], int B[100], int &res) {
  
 int sum_a = 0;
 int sum_b=0;

    loop_1: for (int i = 0; i < 100; i++) {
        if (i < 10) {
            sum_a += A[i];
            }
    }

    loop_2: for (int i=0;i<100; i++){

            sum_b += B[i];
        
    }
    

    res = sum_a+sum_b;
}


CCS_MAIN (int argc, char* argv[]) {
  
  int A[10];
  int B[100];
  int res;
  
  // Seed RNG
  srand(time(NULL));
  
  // Run Multiple Tests
  const int TESTS = 10;
  for (int t=0; t < TESTS; t++) {
    std::cout << "~~~~~ Test #" << t << " ~~~~~" << std::endl;
    
    // Initialize Arrays
    for (int i = 0; i < 10; i++) {
      A[i] = rand();
    }
    for (int i = 0; i < 100; i++) {
      B[i] = rand();
    }
      
    // Call DUT
    two_loops(A, B, res);
    
    int golden = 0;
    for (int i = 0; i < 10; i++) golden += A[i];
    for (int i = 0; i < 100; i++) golden += B[i];
    
    
    std::cout << "Expected= " << golden << ", Actual= " << res;
    std::cout << ((golden == res) ? ". CORRECT!" : ". WRONG!") << std::endl;
  }
  
  
  CCS_RETURN(0);
}
