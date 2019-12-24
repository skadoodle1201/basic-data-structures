#include<iostream>
using namespace std;

int main()
{	
	int T;
	cin>>T;

	int C1,C2,C3,C4,n,m,R[1005],C[1005],mini;
	int rickcost=0,cabcost=0;

	while(T--)
	{
		cin>>C1>>C2>>C3>>C4;
		cin>>n>>m;
		for(int i=0; i<n ; i++)
				cin>>R[i];
		for(int j=0; j<m ; j++)
				cin>>C[j];
		for(int k=0;k<n;k++)
				rickcost+= min(C1*R[k],C2);
	    rickcost=min(rickcost,C3);
		for(int l=0;l<m;l++)
            cabcost+=min(C1*C[l],C2);
        cabcost=min(cabcost,C3);
		mini=min(C4,rickcost+cabcost);
		cout<<"The min amount spent is :"<<mini;
		cout<<endl;
	}
}
