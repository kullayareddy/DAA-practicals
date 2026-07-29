#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Recursive Function
long long recFact(int x)
{
    if (x <= 1)
        return 1;
    return x * recFact(x - 1);
}

// Iterative Function
long long loopFact(int x)
{
    long long result = 1;

    while (x > 1)
    {
        result *= x;
        x--;
    }

    return result;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input!";
        return 0;
    }

    auto start1 = high_resolution_clock::now();
    long long iterativeAns = loopFact(n);
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    long long recursiveAns = recFact(n);
    auto stop2 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(stop1 - start1);
    auto time2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "\nIterative Factorial = " << iterativeAns;
    cout << "\nIterative Time = " << time1.count() << " ns";

    cout << "\n\nRecursive Factorial = " << recursiveAns;
    cout << "\nRecursive Time = " << time2.count() << " ns";

    return 0;
}