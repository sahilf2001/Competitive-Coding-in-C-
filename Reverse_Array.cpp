#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the no. of elements:";
	cin>>n;
	int A[n],i;
	for(i=0;i<n;i++){
		cout<<"Enter "<<i+1<<" array element:";
		cin>>A[i];
	}
	cout<<"***Array in orginal order***"<<endl;
	for(i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	int temp;
	for(i=0;i<n/2;i++){
		temp = A[i];
		A[i] = A[n-(i+1)];
		A[n-(i+1)]=temp;
	}
	
	cout<<"***Array in reverse order***"<<endl;
	for(i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	
}
