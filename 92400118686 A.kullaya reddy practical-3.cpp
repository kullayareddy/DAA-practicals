#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

// Max Heap Adjustment
void createMaxHeap(vector<int> &a, int size, int root)
{
    int max = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && a[l] > a[max])
        max = l;

    if (r < size && a[r] > a[max])
        max = r;

    if (max != root)
    {
        swap(a[root], a[max]);
        createMaxHeap(a, size, max);
    }
}

// Min Heap Adjustment
void createMinHeap(vector<int> &a, int size, int root)
{
    int min = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && a[l] < a[min])
        min = l;

    if (r < size && a[r] < a[min])
        min = r;

    if (min != root)
    {
        swap(a[root], a[min]);
        createMinHeap(a, size, min);
    }
}

// Heap Sort using Max Heap
void heapSortMax(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        createMaxHeap(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        createMaxHeap(a, i, 0);
    }
}

// Heap Sort using Min Heap
void heapSortMin(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        createMinHeap(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        createMinHeap(a, i, 0);
    }

    // Manual reverse
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> data(n), maxData, minData;

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++)
        data[i] = rand() % 100000;

    maxData = data;
    minData = data;

    auto start1 = high_resolution_clock::now();
    heapSortMax(maxData);
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    heapSortMin(minData);
    auto stop2 = high_resolution_clock::now();

    cout << "\nMax Heap Sort Time: "
         << duration_cast<microseconds>(stop1 - start1).count()
         << " microseconds";

    cout << "\nMin Heap Sort Time: "
         << duration_cast<microseconds>(stop2 - start2).count()
         << " microseconds";

    return 0;
}