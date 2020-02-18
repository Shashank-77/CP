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
ll n;
string s;
string s1;
//<<-----Implement Functions Here---->>//
ll mult(ll x,ll y){return (x*y)%MOD;}
ll fastModInv(ll x){
    ll res=1;
    ll y=MOD-2;
    while(y){
        if(y&1)res=mult(res,x);
        y>>=1;x=mult(x,x);
    }
    return res;
}


//<<-----Start of Main--------------->>//
void MAIN(){
		cin>>n>>s;
		ll count2 = 0;
		ll nc = 0,no = 0;ll j = 0;
		for (ll i = 0; i < n; i++)  
        {
        	ll nc = 0;ll no = 0;ll count1 = 0;
        	for (ll len = 1; len <= n - i; len++) 
   			  {
     				s1 = s.substr(i, len);
     				if(s1[len-1] == '*')continue;
     				else if(s1[len-1] == '(')no++;
     				else nc++;
     				if(nc>no)
     				{
     					nc--;no++;
     					count1++;
     				}
     				count2 += count1;
     				j++;
   			}
   		}
   		//cout<<count2<<endl;
   		

   		/*for(ll i=0;i<j;i++)
   		{
   			ll len = s1[i].size();
   			nc = 0;no = 0;
   			for(ll k = 0;k<len;k++)
   			{
   				if(s1[i][k] == '*')continue;
   				else if(s1[i][k] == '(')no++;
   				else nc++;
   				if(nc>no)
   				{
   					nc--;no++;
   					count1++;
   				}
   			}
   		}*/
   		cout<<(count2*fastModInv(n*(n+1)/2))%MOD<<endl;


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