
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
ll x,y;
vector<ll>v;
ll max1,min1;
ll flag,n,i,j,p,z,k;

//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
	cin >> n >> p;v.clear();
	for(i=0;i<n;i++)cin>>x,v.pb(x);
	ll flag = 0;
	for(i=0;i<n;i++)if(p%v[i] != 0){flag = 1;break;}
	if(flag)
	{
		cout<<"YES"<<" ";
		for(j=0;j<n;j++)
		{
			if(j == i)cout<<p/v[i]+1<<" ";else cout<<0<<" ";
		}
		cout<<endl;
		return;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(__gcd(v[i],v[j])!=v[i]&&__gcd(v[i],v[j])!=v[j]){flag = 1;break;}
		}
		if(flag)break;
	}
	if(flag)
	{
		max1 = max(v[i],v[j]);min1 = min(v[i],v[j]);
		x = p/max1-1;y = p - x*max1;
		z = y/min1 + 1;
		cout<<"YES"<<" ";
		for(k=0;k<n;k++)
		{
			if(v[k] == v[i])
			{
				if(v[i] == max(v[i],v[j]))cout<<x<<" ";else cout<<z<<" ";
			}
			else if(v[k] == v[j])
			{
				if(v[j] == max(v[i],v[j]))cout<<x<<" ";else cout<<z<<" ";
			}
			else cout<<0<<" ";
		}
		cout<<endl;
		return;
	}
	else cout<<"NO"<<endl;


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