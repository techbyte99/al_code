#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<limits.h>
using namespace std;
int counter=0;
int partition (int A[], int l, int h)
{
    int x = A[h];
    int i = (l - 1);
    for (int j = l; j <= h-1;j++)
    {
	if (A[j] <= x)
	{
	    i=i+1;
	    if(i!=j)
	    {
		A[i]=A[i]+A[j];
		A[j]=A[i]-A[j];
		A[i]=A[i]-A[j];
	    }
	}
	counter++;
    }
    if(i+1!=h)
    {
	A[i+1]=A[i+1]+A[h];
	A[h]=A[i+1]-A[h];
	A[i+1]=A[i+1]-A[h];
    }
    return (i + 1);
}
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
	int p = partition(A, l, h);
	quickSort(A, l, p - 1);
	quickSort(A, p + 1, h);
    }
}
int main()
{

	int *A;
	int n;
	cout<<"\nEnter the size of array: ";
	cin>>n;
	A=new int[n];
	cout<<"\nEnter the elements of array:\n";
	for(int i=1;i<=n;++i)
		cin>>A[i];
	quickSort(A,1,n);
	cout<<"\nThe sorted array is:";
	for( int i=0;i<n;++i)
		cout<<A[i]<<"\t";
	cout<<"\nThe number of comparisons are: "<<counter;

}
