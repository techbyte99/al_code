#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

int selsort(int [],int);
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
	counter=selsort(A,n);
	cout<<"\nThe sorted array is:";
	for(int i=0;i<n;++i)
		cout<<A[i]<<"\t";
	cout<<"\nThe number of comparisons are: "<<counter;

}
int selsort(int A[],int n)
{
	int pos,temp,counter=0;
//pos to store current pos of min element ,counter for no. of comparisons
	for(int i=0;i<n-1;++i)
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(A[j]<A[pos])
			{
				pos=j;
				counter++;
			}
			else
				counter++;
		}
		temp=A[i];
		A[i]=A[pos];
		A[pos]=temp;
	}
	return counter;
}
