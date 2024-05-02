#include <iostream>
#include "mc_scverify.h"


template<int N>
void CCS_BLOCK(fibonacci)(int fib[N]) { 
 
    int a = 1;
    int b = 1;

    fib[0] = a;
    fib[1] = b;

    FIB_LOOP: for (int i = 2; i < N; i++) {
        int c = a + b;
        a = b;
        b = c;
        fib[i] = c;
    }
}







CCS_MAIN (int argc, char* argv[]) {
  
  const int N = 5;
  
  int fib[N];
  int golden[N];
  
  if (N == 1) {
    golden[0] = 1;
  } else if (N == 2) {
    golden[0] = golden[1] = 1;
  } else {
    golden[0] = golden[1] = 1;
    for (int i = 2; i < N; i++) {
      golden[i] = golden[i-1] + golden[i-2];
    }
  }
  
  fibonacci<N>(fib);
  
  bool correct = true;
  
  std::cout << "Expected: ";
  for (int i = 0; i < N; i++) {
    std::cout << golden[i] << " ";
  }
  std::cout << std::endl;
  
  std::cout << "Actual:   ";
  for (int i = 0; i < N; i++) {
    std::cout << fib[i] << " ";
    if (fib[i] != golden[i]) {
      correct = false;
    }
  }
  std::cout << std::endl;
  
  std::cout << ((correct) ? "CORRECT!" : "WRONG!") << std::endl;
    
  
  CCS_RETURN(0);
}
