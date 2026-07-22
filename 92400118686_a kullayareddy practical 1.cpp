#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &a)
{
    int n = a.size();

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &a)
{
    int n = a.size();

    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;

        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(vector<int> &a)
{
    int n = a.size();

    for(int i=1; i<n; i++)
    {
        int key = a[i];
        int j = i-1;

        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

// Merge Sort
void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> left(a.begin()+l, a.begin()+m+1);
    vector<int> right(a.begin()+m+1, a.begin()+r+1);

    int i=0,j=0,k=l;

    while(i<left.size() && j<right.size())
    {
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while(i<left.size())
        a[k++] = left[i++];

    while(j<right.size())
        a[k++] = right[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

// Quick Sort
int partition(vector<int> &a, int low, int high)
{
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

void display(vector<int> &a)
{
    for(int x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n, ch;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> a(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"\n1.Bubble\n2.Selection\n3.Insertion\n4.Merge\n5.Quick\n";
    cout<<"Enter Choice: ";
    cin>>ch;

    auto start = high_resolution_clock::now();

    if(ch==1)
        bubbleSort(a);
    else if(ch==2)
        selectionSort(a);
    else if(ch==3)
        insertionSort(a);
    else if(ch==4)
        mergeSort(a,0,n-1);
    else if(ch==5)
        quickSort(a,0,n-1);
    else
    {
        cout<<"Invalid Choice";
        return 0;
    }

    auto stop = high_resolution_clock::now();

    cout<<"\nSorted Array: ";
    display(a);

    auto duration = duration_cast<microseconds>(stop-start);
    cout<<"Execution Time: "<<duration.count()<<" microseconds"<<endl;

    return 0;
}