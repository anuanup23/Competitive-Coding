#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int M = 1000000007;
#define pb push_back
#define fs first
#define sc second
#define forn(i,k,n) for(int i = k; i < n; ++i)
#define nfor(i,n,k) for(int i = n; i >= k; --i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pait<int,int>>>
#define all(arr) arr.begin(), arr.end()
#define endl '\n'
#define dbgarr(V,n) forn(i,0,n) cout << V[i] << " "; cout << endl;
#define dbgarrrev(V,n) nfor(i,n,0) cout << V[i] << " "; cout << endl;
#define dbgmaze(V) for(auto x: V) {for(auto y : x) cout << y <<  " ";cout << endl;}
#define dbg2d(V,n,m) forn(i,0,n) {forn(j,0,m) cout << V[i][j] <<  " ";cout << endl;}
#define inf 1000000000
string board[105];
int dp[205][105][105], w, h;
void solve(){
	cin >> w >> h;
	forn(i,0,h) cin >> board[i];
	dp[0][0][0] = (board[0][0] == '*' ? 1 : 0);
	forn(k,1,h + w - 1){
		forn(i,0,w){
			forn(j,0,w){
				dp[k][i][j] = -inf;
				if(i > k || j > k || k - i >= h || k - j >= h) continue;
				if(board[k - i][i] == '#' || board[k - j][j] == '#') continue;
				if(i > 0 && j > 0) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j - 1]);
				if(k - j > 0 && i > 0) dp[k][i][j] = max(dp[k - 1][i - 1][j], dp[k][i][j]);
				if(k - i > 0 && j > 0) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j - 1]);
				if(k - i > 0 && k - j > 0) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
				dp[k][i][j] += (board[k - i][i] == '*');
				dp[k][i][j] += (board[k - j][j] == '*');
				dp[k][i][j] -= (i == j && board[k - i][i] == '*');
			}
		}
	}
	cout << dp[h + w - 2][w - 1][w - 1] << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) solve();
    return 0;
}
/*THE PROBLEM IS HARD .. BUT WORTH SOLVING THROUGH BOTTOM UP */
