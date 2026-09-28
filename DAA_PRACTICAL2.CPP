#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Linear Search
int linearSearch(vector<int> numbers, int value)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == value)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search
int binarySearch(vector<int> numbers, int value)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (numbers[middle] == value)
        {
            return middle;
        }
        else if (numbers[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    int size = 100000;

    // Create array
    vector<int> numbers(size);

    // Store numbers from 1 to 100000
    for (int i = 0; i < size; i++)
    {
        numbers[i] = i + 1;
    }

    // Get value from user
    int value;

    cout << "Enter element to search: ";
    cin >> value;

    int result;

    // =========================
    // Linear Search
    // =========================

    auto start = chrono::high_resolution_clock::now();

    result = linearSearch(numbers, value);

    auto stop = chrono::high_resolution_clock::now();

    cout << "\nLinear Search\n";

    if (result >= 0)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found\n";
    }

    cout << "Time Taken : "
         << chrono::duration_cast<chrono::microseconds>
            (stop - start).count()
         << " microseconds\n";


    // =========================
    // Binary Search
    // =========================

    start = chrono::high_resolution_clock::now();

    result = binarySearch(numbers, value);

    stop = chrono::high_resolution_clock::now();

    cout << "\nBinary Search\n";

    if (result >= 0)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found\n";
    }

    cout << "Time Taken : "
         << chrono::duration_cast<chrono::microseconds>
            (stop - start).count()
         << " microseconds\n";

    return 0;
}