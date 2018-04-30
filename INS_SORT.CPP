#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int insertionsort(int [],int);
int main()
{

	int *A;
	int n,counter;
	cout<<"\nEnter the size of array: ";
	cin>>n;
	A=new int[n];
	cout<<"\nEnter the elements of array:\n";
	for(int i=0;i<n;++i)
		cin>>A[i];
	counter=insertionsort(A,n);
	printf("\nThe sorted array is:");
	for( int i=0;i<n;++i)
		cout<<A[i]<<"\t";
	cout<<"\nThe number of comparisons are: "<<counter;

}
int insertionsort(int A[],int n)
{
	int value,hole,counter=0;
//value to store current value,hole to store current pos,counter for no. of comparisons
	for(int i=1;i<n;++i)
	{
		value=A[i];
		hole=i;
		while(hole>0&&A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			hole--;
			counter++;
		}
		if(hole)
			counter++;
		A[hole]=value;
	}
	return counter;
}
