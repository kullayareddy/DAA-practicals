#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search Function
int binarySearch(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;

    int result;

    auto start = high_resolution_clock::now();

    if (choice == 1)
        result = linearSearch(arr, key);
    else if (choice == 2)
        result = binarySearch(arr, key);
    else
    {
        cout << "Invalid Choice!" << endl;
        return 0;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}