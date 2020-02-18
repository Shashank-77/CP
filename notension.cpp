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
ll q;
ll n,m;
ll l,r,t;
ll i,j;
ll l1,l2,r1,r2,t1,t2;
ll min1,max1;
//vector<pair<ll,pair<ll,ll>>v1;
map<ll,pair<ll,ll>>map1;
map<ll,ll>map2;
//<<-----Implement Functions Here---->>//


//<<-----start of Main--------------->>//
void MAIN(){
	cin >> n >>m;
	for(i=0;i<n;i++)
	{
		cin>>t>>l>>r;map2[t]++;
		min1 = max(min1,l);
		max1 = min(max1,r);
		if(map2[t] == 1)
		{
			map1[t].first = -1e+9+7;
			map1[t].second = 1e+9+7;
		}
		map1[t].first = max(map1[t].first,l);
		map1[t].second = min(map1[t].second,r);
	}
	i =0;ll ach = 0;
	//cout<<max1<<" "<<min1;
	if(max1>min1){cout<<"NO"<<endl;return;}
	else
	{
		if(m >= max1)ach = max1;
		else if(m<=min1)ach = min1;
		else ach = m;
	}
	ll flag = 0,flag2 = 0;

	if(ach == m)flag = 0;
	else if(ach >m)flag = 1;
	else flag =2;
	//cout<<ach<<flag;
	if(flag == 0){cout<<"YES"<<endl;return;}
	ll dif = abs(ach-m);
	for(auto it:map1)
	{
		if(i == 0){i = 1;t1 = it.f;l1 = it.s.f;r1 = it.s.s;continue;}
		t2 = it.f;l2 = it.s.f;r2 = it.s.s;
		ll d = t2 - t1;
		min1 = max(l2,l1);
		max1 = min(r1,r2);
		
		if(flag == 1)
		{
			if(d+m-ach>0)m+=d;
			else {cout<<"YES"<<endl;return;}
		}
		if(flag == 2)
		{
			if(m-d-ach>0)m-=d;
			else {cout<<"YES"<<endl;return;}
		}

		if(m>=min1&&m<=max1){t1 = it.f;l1 = it.s.f;r1 = it.s.s;continue;}
		else {flag2 = 1;break;}

	}
	if(flag2)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;


}

int main(){
	fastio;randomINIT;

	cin>>q;
	while(q--){
		MAIN();
	}

    
}