// bubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



void printArray(int arr[], int size) {
    
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        
        cout << arr[i] << " ";
    }

}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size-i-1; j++)
        {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                printArray(arr, size);
            }
        }
        
    }


}


int main()
{
    int arr[] = {5,4,3,7,9,1};
    int size;
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Before sorting:"<<endl;
    
    printArray(arr, size);
    std::cout << endl;
    std::cout << "After sorting:"<<endl;
    bubbleSort(arr, size);
    
    printArray(arr, size);

   // std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
