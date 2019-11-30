#include<bits/stdc++.h>
using namespace std;
#define ull double 
 //iterative O(Log y) function
 // taken from gfg;
 //link https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
double  power(ull  x, ull y) 
{ 
    return y*log10(x);
} 
double divide(ull x, ull y)
{
    return log10(x)-log10(y);
}
bool check(string s )
{
    if(s.length()<=2)
    {
        if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')||(s[1]=='a'||s[1]=='e'||s[1]=='i'||s[1]=='o'||s[1]=='u')) return true;
        else return false ;
    }
    int win=3;
    for(int i=0;i<=s.size()-win;i++)
    {
        int vowel =0;
        for(int k=i;k<i+3;k++)
        {
            if(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u') vowel++;
            else vowel--;
        }
        if(vowel<0) return false ;
    }
    return true;
}
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
	   vector<string> alice , bob;
	   ull alicecount[26]={0};
	   ull bobcount[26]={0};
	   ull alicechar[26]={0};
	   ull bobchar[26]={0};
	   bool flag ;
	    int ii;
	   for( ii=0;ii<n;ii++)
	   {   
	            string s;
	            cin>>s;
	            flag = true;
	            flag =check(s);
             if(flag) alice.push_back(s);
	         else
	         bob.push_back(s);
        }
	    /*for(auto x:alice) cout<<"alice --> "<<x<<endl;
	    for(auto x:bob) cout<<"bob   --> "<<x<<endl;
	    cout<<endl;
	    cout<<endl;*/
	    if(bob.size()==0)
	    {
	       cout<<"Infinity"<<"\n";
	       continue;
	    }
	    if(alice.size()==0)
	    {
	        cout<<"0.0000000"<<"\n";
	        continue;
	    }
	    for(int i=0;i<alice.size();i++)
	    {
	        bool temp[26]={false};
	        for(int j=0;j<alice[i].length();j++)
	        {
	            temp[alice[i][j]-'a']=true;
	            alicecount[alice[i][j]-'a']++;
	        }
	        for(int m=0;m<26;m++)
	        {
	           if(temp[m]) alicechar[m]++;
	        }
	    }
	     for(int i=0;i<bob.size();i++)
	    {
	        bool temp[26]={false};
	        for(int j=0;j<bob[i].length();j++)
	        {
	            temp[bob[i][j]-'a']=true;
	            bobcount[bob[i][j]-'a']++;
	        }
	        for(int m=0;m<26;m++)
	        {
	           if(temp[m]) bobchar[m]++;
	        }
	    }
	   	    
	   	    double  alicenum = 0 ,bobdenum = 0;
	    for(int i=0;i<26;i++)
	    {
	        if(alicechar[i]!=0){
	    	alicenum = alicenum + log10(alicechar[i]) - (alice.size()*log10(alicecount[i]));
	    	//cout<<alicenum<<" alice "<<endl;
	        }
	        if(bobchar[i]!=0)
	        bobdenum = bobdenum + log10(bobchar[i]) - (bob.size()*log10(bobcount[i]));
	    }
	   // cout<<alicenum<<" "<<bobdenum<<endl;
		double rio = (alicenum) - (bobdenum);
		//cout<<rio<<endl;
		rio = exp(rio*log(10));
		//cout<<rio<<endl;
		if(rio>10000000) cout<<"Infinity"<<"\n";
		else 
		cout<<fixed<<setprecision(7)<<rio<<"\n";
	}
	return 0;
}
