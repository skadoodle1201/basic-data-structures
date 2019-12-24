#include<iostream>
using namespace std;

int main()
{	
	int T;
	cout<<"No. of test cases: ";
	cin>>T;

	int C1,C2,C3,C4,n,m,R[n],C[m],mini;
	int A =0,Q=0;

	while(T--)
	{
		cout<<"Enter the cost of each type of ticket: ";
		cin>>C1>>C2>>C3>>C4;
		cout<<"Enter the no.  of rickshaw  to be used:";
		cin>>n;
		cout<<"Enter the no. of cabs to be used: ";
		cin>>m;
		for(int i=0; i<n ; i++)
			{
				cout<<"Enter the no. of times to use rickshaws :";
				cin>>R[i];

			}
		for(int i=0; i<m ; i++)
			{
				cout<<"Enter the no. of times to use cabs :";
				cin>>C[i];

			}
		for(int j=0;j<n;j++)
			{
				A=A+min(R[j]*C1,C2);
			}
		A=min(A,C3);
		for(int j=0;j<n;j++)
			{
				Q=Q+min(C[j]*C1,C2);
			}
		Q=min(Q,C3);
		mini=min(C4,A+Q);
		cout<<"The min amount spent is :"<<mini;
		cout<<endl;
	}
}
