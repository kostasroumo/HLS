#include <iostream>
#include <random>
using namespace std;

// a .cpp file for testing our functions 

// function for generating random numbers between two limits
template<typename T>

T generateRandomNumber(T min, T max) {
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<T> dist(min, max);
//     if (std::is_floating_point<T>::value) {
//         std::uniform_real_distribution<T> dist(min, max);
//         return dist(gen);
//     } else {
//         std::uniform_int_distribution<T> dist(min, max);
//         return dist(gen);
//     }
// }


    return dist(gen);}

// fill a 2-d array with random numbers
template<int row,int col>

void fill_2d_array(short myArray[row][col]){

    int numRows=row;
    int numCols=col;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            myArray[i][j] = generateRandomNumber(1, 10);
        }
    }

    // Print the random 2D array
    std::cout << "#######  ######\n";
    std::cout << "Random 2D Array:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
}


// fill 1-d array with random number
template<int N>
void fill_1d_array(int array[N]){

    int row=N;
    // fill the array
    for(int i=0;i<row;i++){
        array[i]=generateRandomNumber(1,20);
    }
    // print array's elemets 
    std::cout << "###################\n";
    std::cout << "Random 1-D array.\n";
    for(int i=0;i<row;i++){
        std::cout <<array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "###################\n ";
}