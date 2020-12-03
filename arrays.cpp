// Arrays.cpp
// By: Sophia Moore
// Created on: 10/27/20

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    // hints for the tasks: 
    // all that needs to be in here is simple calls the functions, like these: 
    // in addition to, some print to std.out statements.
    // 
    // Your main() will ideally look clean and uncluttered and be made up
    // mostly of function calls.
    // 
    // Example:
    // ...
    // printArray(array, size);
    // max = maxArray(array, size);
    // min = minArray(array, size);
    // ...
    // ...etc...
    

    // PUT MISSING CODE HERE

    print_array(array, size);
    cout << "Max = " << maxArray(array, size) << endl;
    cout << "Min = " << minArray(array, size) << endl;
    cout << "Sum = " << sumArray(array, size) << endl;
    evensArray(array, size);
    primesArray(array, size);
    AllSearches(array, size);

    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE

void print_array(int arr[], int asize)
{
    for (int i = 0; i < asize; i++)
    {
        if (i == asize-1)
        {
            cout << arr[i] << endl;
        }

        else // if the loop reches the last item in the array
        {
            cout << arr[i] << ", ";
        }
    }
    return;
}

int maxArray(int arr[], int asize)
{
    int bigNumber = arr[0]; // setting the largest number to the first

    for (int i = 0; i < asize; i++)
    {
        if (arr[i] >= bigNumber) // ifnext # is larger, it is now bigNumber
        {
            bigNumber = arr[i];
        }
    }
    return bigNumber;
}

int minArray(int arr[], int asize) // same format as maxArray
{
    int smallNumber = arr[0];

    for (int i = 0; i < asize; i++)
    {
        if (arr[i] <= smallNumber)
        {
            smallNumber = arr[i];
        }
    }
    return smallNumber;
}

int sumArray(int arr[], int asize)
{
    int sumNumbers = 0; // setting the sum to 0, then adding each item

    for (int i = 0; i < asize; i++)
    {
        sumNumbers += arr[i];

    }
    return sumNumbers;
}

void evensArray(int arr[], int asize)
{
    cout << "Evens: ";

    for (int i = 0; i < asize; i++)
    {
        if (arr[i] % 2 == 0) // if it's evenly divisible by 2, it's even
        {
            cout << arr[i] << ", ";
        }
    }

    cout << "end" << endl;

    return;
}

void primesArray(int arr[], int asize)
{
    cout << "Primes: ";

    for (int i = 0; i < asize; i++)
    {
        // variables within the for loop, so they reset every new "i"
        int j = 2;
        bool primeNumber = true;

        while ( (j <= arr[i]) && (primeNumber == true) )
        {
            if (arr[i] % j == 0)
            {
                primeNumber = false;
            } 

            else
            {
                j++; // put this in else otherwise it would add as the loop is exited
            }
        }

        // the while loop will iterate for a prime number until j is the prime number
        // and arr[i] % j == 0 aka primeNumber is false
        if (arr[i] == j) 
        {
            cout << arr[i] << ", "; 
        }
    }
    cout << "end" << endl;

    return;
}

int SeqSearch(int arr[], int array_size, int target)
{
    for (int i = 0; i < array_size; i++)
    {
        if (arr[i] == target)
        { 
            return i;
        }
    }

    return -1; // if it loops through and nothing is found, return -1
}

void AllSearches(int array[], int array_size)
{
    cout << "Searches:\n";

    for (int i = 0; i < NSEARCHES; i++)
    {
        cout << "Looking for " << SEARCHES[i] << ". ";
        int resultIndex = SeqSearch(array, array_size, SEARCHES[i]);

        if (resultIndex != -1)
        {
            cout << "Found at index: " << resultIndex << endl;
        }
        else // resutIndex == -1
        {
            cout << "Not Found!\n";
        }
    }
    return;
}

