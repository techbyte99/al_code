#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int bubsort(int [],int);
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
	counter=bubsort(A,n);
	cout<<"\nThe sorted array is:";
	for(int i=0;i<n;++i)
		cout<<A[i]<<"\t";
	cout<<"\nThe number of comparisons are: "<<counter;
	//getch();
}
int bubsort(int A[],int n)
{
	int temp,counter=0;
//counter for no. of comparisons
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				counter++;
			 }
			else
				counter++;
		}
	}
	return counter;
}
