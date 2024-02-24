#include <iostream>
# include <random>
# include "mc_scverify.h"

using namespace std;

template<typename T>

T generateRandomNumber(T min, T max) {
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<T> dist(min, max);
    return dist(gen);
}

// WAVE SORT function
template<int N>		
//void wave_sort(int a[N]){
void CCS_BLOCK(wave_sort )(int a[N]){
 bubble_1: for (int i = 0; i < N - 1; i++) {
 bubble_2:       for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap if the current element is greater than the next
                std::swap(a[j],a[j + 1]);
            }
        }
    }

     // compare elements by 2
     // 1- if element<before_ele --> swap both 
   wave_loop:  for(int j=0;j<N;j+=2){
        if(j>0){
        if( a[j]<a[j-1]){
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
        // 2- if ele<ele_after --> swap both
        if(j<N-1){
         if( a[j]<a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
     }
}



}


CCS_MAIN(int argc,char *argv[]) {
 //int main(int argc,char *argv[]){
  const int row=6;
  int var;
  int array[row];
  int golden[row];  // initialize golden array

  // run for 15 iterations
  for(int iter=0;iter<15;iter++){

  int test[row];
 
  // create two random but equal arrays
  for(int i=0;i<row;i++){
    test[i]=generateRandomNumber(1,20);
    array[i]=test[i];
    golden[i]=test[i];
  }
   
   // print two arrays
   std::cout << "Array" << " :";
   for(int j=0;j<row;j++){
    std::cout<<array[j] << " " ;
   }
   std::cout << "Golden " << " :";
   for(int j=0;j<row;j++){
    std::cout<<golden[j] << " " ;
   }

  // wave sort of golden array
  for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (golden[j] > golden[j + 1]) {
                // Swap if the current element is greater than the next
                std::swap(golden[j],golden[j + 1]);
            }
        }
    }
    for(int j=0;j<row;j+=2){
        if(j>0 && golden[j]<golden[j-1]){
            int temp=golden[j];
            golden[j]=golden[j-1];
            golden[j-1]=temp;
        }
        // 2- if ele<ele_after --> swap both
        if(j<row-1 && golden[j]<golden[j+1]){
            int temp=golden[j];
            golden[j]=golden[j+1];
            golden[j+1]=temp;
        }
     }
    
   wave_sort<row>(array); // call  wave_sort fnc for array

  

  // print wave sorted arrays
  std::cout << "Sorted_wave Array" << " :";
   for(int j=0;j<row;j++){
    std::cout<<array[j] << " " ;
   }
   std::cout << "Sorted_wave Golden " << " :";
   for(int j=0;j<row;j++){
    std::cout<<golden[j] << " " ;
   }


  // Check 
  var=0;
  for(int num=0;num<row;num++){
    if (array[num]!=golden[num]){
    var+=1;
     
  }}

  if(var==0)
     std::cout << "  --> MATCH" << std::endl; 
    else
      std::cout << "  --> MISSMATCH" << std::endl; 
  
  



  }
  //return 0;
CCS_RETURN(0);
}