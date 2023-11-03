#include <iostream>
#include <time.h>
#include <chrono>

#define ARRAY_SIZE 1000
#define MAX_NUMBER 5000

void initArray(int * arr);

int main(){
    srand (time(NULL));

    int randomNumberArray[ARRAY_SIZE];
    initArray(randomNumberArray);

    return 0;
}

void initArray(int * arr){
    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % MAX_NUMBER + 1;
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time to generate array of size " << ARRAY_SIZE << ":" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds.";
}