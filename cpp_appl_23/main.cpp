#include <iostream>
#include<Windows.h>
#include <ctime>

using namespace std;

int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double findAvg(int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int Action(int* arrA, int* arrB, int size, int (*func)(int*, int)) {
    return func(arrA, size) > func(arrB, size) ? func(arrA, size) : func(arrB, size);
}

int main() {
    const int size = 4;
    int A[size];
    int B[size];

    srand(time(0));
    cout << "Array A: ";
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < size; ++i) {
        B[i] = rand() % 100;
        cout << B[i] << " ";
    }
    cout << endl;

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Max" << endl;
    cout << "2. Min" << endl;
    cout << "3. Avg" << endl;
    cin >> choice;

    int (*functionPointer)(int*, int) = nullptr;

    if (choice == 1) {
        functionPointer = findMax;
    }
    else if (choice == 2) {
        functionPointer = findMin;
    }
    else if (choice == 3) {
        functionPointer = (int (*)(int*, int))findAvg;
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    int result = Action(A, B, size, functionPointer);
    cout << "Result: " << result << endl;

    return 0;
}