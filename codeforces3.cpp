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

vll adj[MAXN];ll visited[MAXN]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
string s,s1,s2;
ll flag = 0;
ll k,j,i,count1;
map<char,set<char>>v1;
//<<-----Implement Functions Here---->>//
void dfs(ll child,ll p)
{
	s2+=child;
	if(child == k)count1++;
	if(count1 ==  2)return;
	for(i=0;i<adj[child].size();i++)
	{
		if(adj[child][i] != p)dfs(adj[child][i],child);
	} 
}

//<<-----Start of Main--------------->>//
void MAIN(){
	cin >> s;ll n = s.size();s2.clear();
	for(i=97;i<=122;i++)v1[i].clear();flag = 0;
	for(i=0;i<n;i++)
	{
		if(i == 0){v1[s[i]].insert(s[i+1]);continue;}
		if(i == n-1){v1[s[i]].insert(s[i-1]);continue;}
		v1[s[i]].insert(s[i+1]);
		v1[s[i]].insert(s[i-1]);
	}
	for(i=97;i<=122;i++)
	{
		for(auto it:v1[i])adj[i].pb(it);if(v1[i].size() == 1)j = i;
		if(v1[i].size()>2)flag = 1;if(v1[i].size() == 2)k = i;
	}
	if(flag){cout<<"NO"<<endl;return;}
	if(k!=0)
	{
		dfs(k,k);
		for(i=0;i<s2.size();i++)visited[s[i]] = 1;
		for(i=97;i<=122;i++)if(!visited[i])s2+=i;
		for(i = 97;i<=122;i++)visited[i] = 0;
		
		if(s2.size() == 26)cout<<s2<<endl;
		else cout<<"NO"<<endl;
	}
	else if(j!=0)
	{
		dfs(j,j);
		for(i=0;i<s2.size();i++)visited[s[i]] = 1;
		for(i=97;i<=122;i++)if(!visited[i])s2+=i;
		cout<<s2<<endl;
	}
}

int main(){
	fastio;randomINIT;

	cin>>t;
	while(t--){
		MAIN();
	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}