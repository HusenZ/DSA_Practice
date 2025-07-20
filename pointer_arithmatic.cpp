#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // arr[0] ka address

    cout << "Original pointer (arr[0]): " << *p << endl;

    // Pointer increment
    p++; // ab p points to arr[1]
    cout << "After p++ (arr[1]): " << *p << endl;

    // Pointer addition
    p = p + 2; // ab p points to arr[3]
    cout << "After p + 2 (arr[3]): " << *p << endl;

    // Pointer decrement
    p--; // ab p points to arr[2]
    cout << "After p-- (arr[2]): " << *p << endl;

    // Pointer subtraction (difference between pointers)
    int *start = arr;   // arr[0]
    int *end = &arr[4]; // arr[4]
    int diff = end - start;
    cout << "Difference (end - start): " << diff << " elements" << endl;

    return 0;
}

/*
note points
Pointer arithmetic works with contiguous memory (like arrays).

Pointer increment/decrement depends on data type size.

Use pointer arithmetic carefully to avoid undefined behavior (e.g., going out of bounds).
*/