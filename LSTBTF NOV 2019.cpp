#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
void stradd(int n)
{
	int ind = n-1;
	bool flag = false;
	while(arr[ind] != 1 && ind-1 >= 0)
	{
		if(arr[ind] < arr[ind-1])
		{
		 for(int i = ind; i <= n-1; i++){
		 	arr[i] = arr[ind-1];
		 }
	      flag = true;
	      break;
	    }
		 ind--;
	}
	if(!flag){
	int bit = 1 + arr[n-1];
	arr[n-1] = bit%10;
	int carry = bit/10;
	int index = n-2;
	while(carry)
	{               
		int bit2 = arr[index] + carry;
		carry = bit2/10;
		arr[index] = bit2%10;
		index--;
	}
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		//int arr[n];
		for(int i=0;i<n;i++) 
		arr[i]=1;
		int f = sqrt(n);
		if(f*f == n)
		{
		    string s = "";
		  	for(int i=0;i<n;i++)
		  		s += arr[i] + '0';
		  	cout<<s<<endl;
			continue;	
		}
	    bool flag = false;
	    int  sum = 0;
	    while(1)
	 	 {
	  		sum=0;
		  	for(int i = n-1;i >= 0;i--)
		  	{
		  		if(arr[i] == 0)
	  	  		{
	  				flag = true;
	  				break;
		  		}		   
		  		if(arr[i] == 1)
		  		{
		  			sum += i+1;
		  			break;
				}
		  	sum += arr[i] * arr[i];
		   }
		   if(flag)
		   {
		   		stradd(n);
		   		flag = false ;
		   		continue;
		   }
		    int k = sqrt(sum);
		   if(k*k == sum)
		   {
		  	string s = "";
		  	for(int i=0;i<n;i++) 
		  		s += arr[i] + '0';
		  	cout<<s<<endl;
		  	break;
		   }
		  else 
		  stradd(n);
	  }
	}
	return 0;
}