#pragma GCC optimize("Ofast")   //Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  newl           cout<<"\n"
#define  pb             push_back
#define  mp             make_pair
#define  s              second
#define  f              first
#define  dline          cerr<<"///REACHED///\n";
#define  deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define  deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define  deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  1e+5+7;

vll adj[MAXN];ll visit[MAXN]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
ll n,i,j,c;
string s;
vector<pair<char,ll>>v;
ll dp[10000];
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
	cin>> n >> s;
	for(i=0;i<n;i++)dp[i] = -1;
	for(i=0;i<n;i++)v.pb({s[i],i});
	sort(all(v));
	c = 0;
	for(i=0;i<n;i++)
	{
		if(dp[v[i].second] == -1)
		{
			dp[v[i].second] = 1;
			for(j=c;j<v[i].second;j++)dp[j] = 0;
			c = v[i].second+1;
		}
	}
	ll flag = 0;
	//for(i=0;i<n;i++)cout<<dp[i];cout<<endl;
	for(i=0;i<n-1;i++)
	{
		ll a = dp[i];
		for(j=i+1;j<n;j++)
		{
			if(dp[j] == a)if(s[i]<=s[j])continue;
			else {flag = 1;break;}
		}
		if(flag == 1)break;
	}
	if(!flag)
	{
		cout<<"YES"<<endl;
		for(i=0;i<n;i++)cout<<dp[i];cout<<endl;
	}
	else cout<<"NO"<<endl;
	


}

int main(){
	fastio;randomINIT;

	//cin>>t;
	while(t--){
		MAIN();
	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}