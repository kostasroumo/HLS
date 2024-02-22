#include <iostream>
#include "testing.cpp"

using namespace std;


template<int N>
void wave_sort(int a[N]){
  // bubble sort
  for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap if the current element is greater than the next
                std::swap(a[j],a[j + 1]);
            }
        }
    }
//      // insertion sort 
//      for(int i=1;i<N;i++){
//         int key=a[i];
//         int j=i-1;

//         while(key<a[j] && j>=0){
//             a[j+1]=a[j];
//             j--;
//         }
//         a[j+1]=key;
//      }

     // compare elements by 2
     // 1- if element<before_ele --> swap both 
     for(int j=0;j<N;j+=2){
        if(j>0 && a[j]<a[j-1]){
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
        // 2- if ele<ele_after --> swap both
        if(j<N-1 && a[j]<a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
     }




}

int main() {

  const int row=6;
  int array[row];
  
  

return 0;
}





   