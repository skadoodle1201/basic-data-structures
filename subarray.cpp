//subarray and maximum sum of subarray




#include<iostream>
using namespace std;

int main()
{
	int A[5]={1,-2,3,4,5};
	int crsum=0,mxsuum=0;
	int left=-1,right=-1;

	for(int i=0;i<5;i++)
	{
		for(int j=i;j<5;j++)
		{
			if(j!=i)
			{	
				crsum=0;
				for(int k=i;k<=j;k++)
				{
					cout<<A[k]<<",";
					crsum=crsum+A[k];
					if(crsum>mxsuum)
					{	
						mxsuum=crsum;
						left=i;
						right=j;
					}
				}

			}
			cout<<endl;
		}

	}
	cout<<mxsuum<<"\t max sum \n "<<"left and right \t"<<left<<" \t"<<right<<"\n";
	for (int e=left;e<=right;e++)
		cout<<A[e]<<",";

	return (0);
}