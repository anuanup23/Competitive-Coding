#include<bits/stdc++.h>
using namespace std;
int main()
 {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int T;
	cin>>T;
	while(T--)
	{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	int max=0,count=0;
	   for(int i=n-1;i>=max;i--)
	   {
	       count=0;
	       if(arr[n-1]==1)
			   max=n-1;
			 else if(arr[i]==1)
			   count=i;
	                else
	                 {
	                    bool flag=false;
	                    for(int j=n-1;j>i;j--)
	                    {
	                         if(arr[i]%arr[j]==0)
	                          flag=true;
	                    }
	                    if(!flag)
	                    {
	                       for(int k=i-1;k>=0;k--)
	                        if(arr[k]%arr[i]==0)
	                        count++;
	                    }
	                 }
	           if(count>max) 
			   max=count;
	   }
	   	     cout<<max<<"\n"; 
	}
	return 0;
}