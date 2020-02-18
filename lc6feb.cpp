#pragma GCC optimize("Ofast")   //Comment optimisations for lleractive problems (use endl)
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
const ll  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  1e+5+7;

vll adj[MAXN];ll visit[MAXN]={};
ll dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
ll t=1;
ll x,i,m,n,j;
vector<ll>v1,v2;
map<set<ll>,vector<ll>>map2;
set<ll>set1,set2;
ll count1;
//<<-----Implement Functions Here---->>//
#define MAXN 100020 
ll spf[MAXN]; 
void sieve() 
{ 
	spf[1] = 1; 
	for (ll i=2; i<MAXN; i++) spf[i] = i; 
	for (ll i=4; i<MAXN; i+=2) spf[i] = 2; 
	for (ll i=3; i*i<MAXN; i++) 
	{ 
		if (spf[i] == i) 
		{
			for (ll j=i*i; j<MAXN; j+=i)if(spf[j]==j)spf[j] = i; 
		} 
	} 
} 
void getFactorization(ll x) 
{ 
	ll i,j;
	vector<ll> ret;map<ll,ll>map1;set<ll>retu;
	ll temp = x;x = abs(x);if(x == 0)return;
	while (x != 1){ret.push_back(spf[x]); x=x/spf[x];} 
	ll len1 = ret.size();
	for(i=0;i<len1;i++)map1[ret[i]]++;
	for(auto it:map1)if(it.second%2)retu.insert(it.first);
	map2[retu].pb(temp);
} 
void func(vector<ll>v1,set<ll>set1)
{
	ll i,j,x;
	ll len1 = v1.size();
	for(i=0;i<len1;i++){x = v1[i];getFactorization(x);}

	for(auto it:map2)
	{
		ll len = it.second.size();
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				ll prod = it.second[i]*it.second[j];
				if(prod<0)
				{
					if(set1.find(sqrt(abs(prod)))!=set1.end())
						count1++;
					if(set1.find(-sqrt(abs(prod)))!=set1.end())
						count1++;
				}
			}
		}
	}
}
	



//<<-----Start of Main--------------->>//
void MAIN(){
	count1 = 0;
	ll i,j,n,m;
	map2.clear();v1.clear();v2.clear();set1.clear();set2.clear();
	cin >> n >> m;
	for(i=0;i<n;i++){cin>>x;v1.pb(x);set1.insert(x);}
	for(i=0;i<m;i++){cin>>x;v2.pb(x);set2.insert(x);}
	func(v1,set2);
	map2.clear();
	func(v2,set1);
	if(set1.find(0)!=set1.end()&&set2.find(0)!=set2.end())count1+=(m-1)*(n-1);
	else if(set1.find(0)!=set1.end())count1+=(n-1)*m;
	else if(set2.find(0)!=set2.end())count1+=(m-1)*n;
	cout<<count1<<endl;
}


int main(){
	fastio;randomINIT;

	cin>>t;
	sieve();
	while(t--){
		MAIN();

	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}