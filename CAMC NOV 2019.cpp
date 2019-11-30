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
	  int m,n;
	  cin>>n>>m;
	  int arr[n];
	   set<int> st[m];
	  for(int i=0;i<n;i++)
	  {
	   cin>>arr[i];
	   st[i%m].insert(arr[i]);
	  }
	   vector<pair<int,int>>help;
	   for(int i=0;i<m;i++)
	   {
	    //sort(st[i].begin(),st[i].end());
	   	auto it = st[i].begin();
	   	help.push_back({*it,i});
	   }  
	   int ans = INT_MAX;
	   bool flag = true;
	   while(flag)
	   {
	       int bara=INT_MIN ,index,chota =INT_MAX;
	   	for(auto x: help)
	   	{
	   	    if(x.first<chota) chota =x.first,index=x.second;
	   	    if(x.first>bara) bara=x.first;
	   	}
	       int currdiff = bara-chota;
	       ans = min(ans,currdiff);
	       auto itr =st[index].find(chota);
	       if(itr!=st[index].end())
	       itr++;
	       if(itr==st[index].end())
	       {
	       	flag = false;
	       	continue;
		   }
	       else 
		   {
		       pair <int,int> p;
		       p.first=chota;
		       p.second=index;
		       auto it =find(help.begin(),help.end(),p);
		       help.erase(it);
		   	    p.first=(*itr);
		   	help.push_back(p);
		   }
		   
	      //for(auto x: sst) cout<<" set "<<x<<endl;
	       //if(currdiff>abs(*sst.rbegin()-*sst.begin())) flag =false;
	       //else
	     /*  for(auto x: help)
	   	{
	   	    if(x.first<chota) chota =x.first,index=x.second;
	   	    if(x.first>bara) bara=x.first;
	   	}
	       int currdiff2 = (bara - chota);
	       if(currdiff2>currdiff) flag =false;
	       ans = min(ans,currdiff2);
	       
	       //cout<<ans<<endl;*/
	   }
	   cout<<ans<<endl;
	}
	return 0;
}