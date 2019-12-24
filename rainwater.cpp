#include <iostream>
using namespace std;
int main() 
{
    int build[10],left[10],right[10],water=0;
    
    for(int i=0;i<10;i++)
    	cin>>build[i];
    
    left[0]=build[0];
    right[9]=build[9];
    
    for(int i=8;i>=0;i--)
    	{
    		right[i] = max(build[i],right[i-1]);
    		cout<<right[i]<<"\t";
    	}
    cout<<endl;

    for(int i=1;i<10;i++)
    	{
    		left[i]= max(build[i],left[i-1]);
    		cout<<left[i]<<"\t";
    	}
    cout<<endl;

    for(int i=0;i<10;i++)
    	{
    		water=water+min(left[i],right[i])-build[i];
    		cout<<water<<"\t";
    	}
    	cout<<endl;
    	cout<<water<<"**";
    return(0);
}
