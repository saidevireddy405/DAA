#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// ================= MAX HEAP =================

void maxHeapify(vector<int>& a, int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && a[left] > a[largest])
        largest = left;

    // Check right child
    if (right < n && a[right] > a[largest])
        largest = right;

    // If parent is not largest, swap
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // Fix the heap again
        maxHeapify(a, n, largest);
    }
}

// Max Heap Sort
void maxHeapSort(vector<int>& a)
{
    int n = a.size();

    // Create Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    // Move largest element to the end
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);

        // Restore heap
        maxHeapify(a, i, 0);
    }
}


// ================= MIN HEAP =================

void minHeapify(vector<int>& a, int n, int i)
{
    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && a[left] < a[smallest])
        smallest = left;

    // Check right child
    if (right < n && a[right] < a[smallest])
        smallest = right;

    // If parent is not smallest, swap
    if (smallest != i)
    {
        swap(a[i], a[smallest]);

        // Fix the heap again
        minHeapify(a, n, smallest);
    }
}

// Min Heap Sort
void minHeapSort(vector<int>& a)
{
    int n = a.size();

    // Create Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    // Move smallest element to the end
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);

        // Restore heap
        minHeapify(a, i, 0);
    }

    // Reverse to get ascending order
    reverse(a.begin(), a.end());
}


// ================= MAIN =================

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Create original array
    vector<int> original(n);

    // Generate random numbers
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        original[i] = rand() % 100000;
    }

    // Make two copies
    vector<int> maxArray = original;
    vector<int> minArray = original;


    // ================= MAX HEAP TIME =================

    auto startMax = high_resolution_clock::now();

    maxHeapSort(maxArray);

    auto endMax = high_resolution_clock::now();


    // ================= MIN HEAP TIME =================

    auto startMin = high_resolution_clock::now();

    minHeapSort(minArray);

    auto endMin = high_resolution_clock::now();


    // ================= MAX HEAP TIME =================

    auto maxNano =
        duration_cast<nanoseconds>(endMax - startMax);

    auto maxMicro =
        duration_cast<microseconds>(endMax - startMax);

    auto maxMilli =
        duration_cast<milliseconds>(endMax - startMax);

    duration<double> maxSecond = endMax - startMax;


    // ================= MIN HEAP TIME =================

    auto minNano =
        duration_cast<nanoseconds>(endMin - startMin);

    auto minMicro =
        duration_cast<microseconds>(endMin - startMin);

    auto minMilli =
        duration_cast<milliseconds>(endMin - startMin);

    duration<double> minSecond = endMin - startMin;


    // ================= DISPLAY RESULT =================

    cout << "\n========== MAX HEAP SORT ==========\n";

    cout << "Nanoseconds  : "
         << maxNano.count() << " ns\n";

    cout << "Microseconds : "
         << maxMicro.count() << " us\n";

    cout << "Milliseconds : "
         << maxMilli.count() << " ms\n";

    cout << "Seconds      : "
         << maxSecond.count() << " s\n";


    cout << "\n========== MIN HEAP SORT ==========\n";

    cout << "Nanoseconds  : "
         << minNano.count() << " ns\n";

    cout << "Microseconds : "
         << minMicro.count() << " us\n";

    cout << "Milliseconds : "
         << minMilli.count() << " ms\n";

    cout << "Seconds      : "
         << minSecond.count() << " s\n";


    return 0;
}