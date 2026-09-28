#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;


// ================= BUBBLE SORT =================

void bubbleSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


// ================= SELECTION SORT =================

void selectionSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }

        swap(a[i], a[smallest]);
    }
}


// ================= INSERTION SORT =================

void insertionSort(vector<int>& a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}


// ================= MERGE SORT =================

void merge(vector<int>& a, int left, int middle, int right)
{
    vector<int> temp;

    int i = left;
    int j = middle + 1;

    // Compare both parts
    while (i <= middle && j <= right)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    // Copy remaining left elements
    while (i <= middle)
    {
        temp.push_back(a[i]);
        i++;
    }

    // Copy remaining right elements
    while (j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }

    // Copy sorted values back
    for (int k = 0; k < temp.size(); k++)
    {
        a[left + k] = temp[k];
    }
}


void mergeSort(vector<int>& a, int left, int right)
{
    if (left >= right)
        return;

    int middle = (left + right) / 2;

    // Sort left part
    mergeSort(a, left, middle);

    // Sort right part
    mergeSort(a, middle + 1, right);

    // Combine both parts
    merge(a, left, middle, right);
}


// ================= QUICK SORT =================

int partition(vector<int>& a, int low, int high)
{
    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}


void quickSort(vector<int>& a, int low, int high)
{
    if (low >= high)
        return;

    int pivot = partition(a, low, high);

    // Sort left side
    quickSort(a, low, pivot - 1);

    // Sort right side
    quickSort(a, pivot + 1, high);
}


// ================= MAIN =================

int main()
{
    const int n = 100;

    vector<int> original(n);
    vector<int> a;

    // Generate random numbers
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        original[i] = rand() % 1000;
    }

    cout << "Number of Elements = " << n << "\n\n";


    // ---------- BUBBLE SORT ----------

    a = original;

    auto start = high_resolution_clock::now();

    bubbleSort(a);

    auto stop = high_resolution_clock::now();

    cout << "Bubble Sort Time    : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";


    // ---------- SELECTION SORT ----------

    a = original;

    start = high_resolution_clock::now();

    selectionSort(a);

    stop = high_resolution_clock::now();

    cout << "Selection Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";


    // ---------- INSERTION SORT ----------

    a = original;

    start = high_resolution_clock::now();

    insertionSort(a);

    stop = high_resolution_clock::now();

    cout << "Insertion Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";


    // ---------- MERGE SORT ----------

    a = original;

    start = high_resolution_clock::now();

    mergeSort(a, 0, n - 1);

    stop = high_resolution_clock::now();

    cout << "Merge Sort Time     : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";


    // ---------- QUICK SORT ----------

    a = original;

    start = high_resolution_clock::now();

    quickSort(a, 0, n - 1);

    stop = high_resolution_clock::now();

    cout << "Quick Sort Time     : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";


    return 0;
}