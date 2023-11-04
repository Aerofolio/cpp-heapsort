#include <iostream>
#include <time.h>
#include <chrono>

#define ARRAY_SIZE 15
#define MAX_NUMBER 100

void initArray(int * arr);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void printArray(int * arr);

int main(){
    srand (time(NULL));

    int randomNumberArray[ARRAY_SIZE];
    initArray(randomNumberArray);
    printArray(randomNumberArray);

    heapSort(randomNumberArray, ARRAY_SIZE);
    printArray(randomNumberArray);

    return 0;
}

void initArray(int * arr){
    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % MAX_NUMBER + 1;
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time to generate array of size " << ARRAY_SIZE << ":" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds." << std::endl;
}

void heapify(int arr[], int N, int i)
{
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N){
    auto start = std::chrono::steady_clock::now();

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
 
        // Move current root to end
        std::swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time to sort array of size " << ARRAY_SIZE << ":" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds." << std::endl;
}

void printArray(int * arr){
    std::cout << arr[0];
    for(int i = 1; i < ARRAY_SIZE; i++)
        std::cout << ", " << arr[i];

    std::cout << std::endl;
}