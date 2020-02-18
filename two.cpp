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
ll q=1;
map<char,ll>map1,map2,map3;

ll i,j;
vector<map<char,ll>>v(200007);
ll counter;

//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){

}

int main(){
	fastio;randomINIT;

	cin>>q;
	while(q--){
		vector<set<ll>>v1(27);
		ll flag = 0;string s,t;map1.clear();counter = 0;
		
		s.clear();t.clear();
		ll ans = 0;
		cin >> s >> t;
		ll n = s.size();
		ll m = t.size();
		for(i=n-1;i>=0;i--){map1[s[i]]++;v1[s[i]-97].insert(i);}

		for(i=0;i<m;i++)
		{
			if(map1[t[i]] == 0){flag =1;break;}
		}
		


		if(flag){cout<<-1<<endl;continue;}
		
		//cout<<v1.size();
		for(i=0;i<m;i++)
		{
		
			if(v1[t[i]-97].lower_bound(counter)!=v1[t[i]-97].end()){counter = *v1[t[i]-97].lower_bound(counter)+1;continue;}
			else {ans++;counter = 0;counter = *v1[t[i]-97].lower_bound(counter)+1;}
		}
		
		cout<<ans+1<<endl;
		
	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif


}