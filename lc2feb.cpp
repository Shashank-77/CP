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
ll x,n,k,i,sum1,j,sum2;
vector<string>v1;
vector<ll>v2;
map<string,ll>map1;
map<pair<char,ll>,ll>map2;
string s;
//<<-----Implement Functions Here---->>//
void permute(string str) 
{ 
    do
    { 
    	map1[str] = 0;v1.pb(str);    
    } while (next_permutation(str.begin(), str.end())); 
} 

//<<-----Start of Main--------------->>//
void MAIN(){
	cin >> n;char c;s.clear();v1.clear();map1.clear();v2.clear();sum1 =0;map2.clear();
	permute("ABCD");
	ll len = v1.size();
	for(i=0;i<n;i++)
	{
		cin>>c>>x;
		map2[{c,x}]++;
		if(x == 12)for(j=0;j<len;j++)if(v1[j][0] == c)map1[v1[j]]++;
		if(x == 3)for(j=0;j<len;j++)if(v1[j][1] == c)map1[v1[j]]++;
		if(x == 6)for(j=0;j<len;j++)if(v1[j][2] == c)map1[v1[j]]++;
		if(x == 9)for(j=0;j<len;j++)if(v1[j][3] == c)map1[v1[j]]++;
	}
	ll max = -1000000009,max1 = -1000000009;
	for(auto it:map1)if(it.second>max)max = it.second;

	for(i=0;i<len;i++)
	{
		
		//if(map1[v1[i]] == max)
		{
			v2.clear();s.clear();
			sum1 = 0;
			s = v1[i];
			v2.pb(map2[{s[0],12}]);v2.pb(map2[{s[1],3}]);
			v2.pb(map2[{s[2],6}]);v2.pb(map2[{s[3],9}]);
	
			sort(all(v2));
			sum1 = 100*v2[3]+75*v2[2]+50*v2[1]+v2[0]*25;
			for(j=0;j<4;j++)if(v2[j] == 0)sum1-=100;
			if(max1<sum1)max1 = sum1;
		}
	}

	cout<<max1<<endl;sum2+=max1;
}

int main(){
	fastio;randomINIT;

	cin>>t;
	while(t--){
		MAIN();
	}
	cout<<sum2;
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}