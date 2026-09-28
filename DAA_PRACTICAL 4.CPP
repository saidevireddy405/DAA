#include <iostream>
#include <chrono>
using namespace std;

// Iterative factorial
unsigned long long factorialIterative(int n)
{
    unsigned long long result = 1;

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

// Recursive factorial
unsigned long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Start time for iterative
    auto start1 = chrono::high_resolution_clock::now();

    unsigned long long result1 = factorialIterative(n);

    auto end1 = chrono::high_resolution_clock::now();

    // Start time for recursive
    auto start2 = chrono::high_resolution_clock::now();

    unsigned long long result2 = factorialRecursive(n);

    auto end2 = chrono::high_resolution_clock::now();

    // Calculate time
    auto time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);
    auto time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    cout << "\n--- Results ---" << endl;

    cout << "Factorial = " << result1 << endl;

    cout << "\nIterative:" << endl;
    cout << "Result = " << result1 << endl;
    cout << "Time = " << time1.count() << " ns" << endl;

    cout << "\nRecursive:" << endl;
    cout << "Result = " << result2 << endl;
    cout << "Time = " << time2.count() << " ns" << endl;

    return 0;
}