//kadanes algorithm for maximum sum of subarray

#include<iostream>
using namespace std;

int main()
{
	int A[5]={1,2,3,-10,8};
	int csum=0;
	int msum=0;

	for(int i=0;i<5;i++)
	{
		if(csum+A[i]<0)
			csum=0;
		else
			{	
				csum=csum+A[i];
		    		if(csum>msum)
			   			msum=csum;
			}
	}
	cout<<"maximum sum of a subarray is : \t"<<msum<<endl;

	return(0);

}
