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
	long long int n,k;
	cin>>n>>k;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
	    long long int z;
	    cin>>z;
	    arr[i]=z;
	}
	if(k<=n)
	{
		for(long long int i=0;i<k;i++)
	{
	    long long int a , b;
	    a=arr[i%n];
	    b=arr[n-(i%n)-1];
	    arr[i%n]=a^b;
	}
	for(long long int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	}
	else
	{
		 vector<long long int> ans ;
		for(long long int i=0;i<3*n;i++)
	  	{
	    long long int a ,b;
	    a=arr[i%n];
	    b=arr[n-(i%n)-1];
	    arr[i%n]=a^b;
	    ans.push_back(arr[i%n]);
		}
     long long int q,r,rq;
     q=k/n;
     rq=q%3;
	 r=k%n;     
	 if(r==0)
	 {
	 	if(rq==0)
	 	{
	 	for(long long int i=2*n;i<3*n;i++)
	 		cout<<ans[i]<<" ";
	 	}
	 	if(rq==1)
	 	{
	 		for(long long int i=0;i<n;i++)
	 		cout<<ans[i]<<" ";
		}
		if(rq==2)
	 	{
	 		for(long long int i=n;i<n*2;i++)
	 		cout<<ans[i]<<" ";
		}
	 }
	 else
	 {
	 	if(rq==0)
	 	{
	 	for(long long int i=0;i<r;i++)
	 	  cout<<ans[i]<<" ";
	 	  for(long long int i=n*2+r;i<n*3;i++)
	 	  cout<<ans[i]<<" ";
	   }
	   if(rq==2)
	 	{
	 	for(long long int i=2*n;i<2*n+r;i++)
	 	  cout<<ans[i]<<" ";
	 	  for(long long int i=n+r;i<n*2;i++)
	 	  cout<<ans[i]<<" ";
	   }
	   if(rq==1)
	 	{
	 	for(long long int i=n;i<n+r;i++)
	 	  cout<<ans[i]<<" ";
	 	  for(long long int i=r;i<n;i++)
	 	  cout<<ans[i]<<" ";
	   }
	 }
	}
	cout<<endl;
	
	}
	return 0;
}