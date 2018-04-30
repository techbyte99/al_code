#include<iostream>
using namespace std;
// function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
//  function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    char key='q';
    do
    {
    int siz;

    cout<<"                      RADIX  SORT IMPLEMENTATION\n\n";
    cout<<"Enter the size of array to be sorted :";
    cin>>siz;
    int arr[siz];
    for(int i=0;i<siz;i++)
    {
        cout<<"Enter the "<<i<<" th elements : ";
        cin>> arr[i];
    }
     cout<<"Entered elements are :\n";
     for(int i=0;i<siz;i++)
    {
        cout<<i<<" th elements : ";
        cout<<arr[i];
        cout<<endl;
    }

    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    cout<<"The sorted array using radix sort is :";
    print(arr, n);

    cout<<"\nPress q to quit: ";
    cin>>key;
    }while(key!='q');
    return 0;
}

