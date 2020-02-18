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
const int N = 3e+5 + 5;
 
ll a[N],vis[N];
ll n,m,k,x,u,v;
vector <pair<ll,ll>> adj[N];
set <ll> ans;
string s;
queue <pair<ll,ll>> q;
 
//<<-----Implement Functions Here---->>//
void bfs(){
    while(!q.empty()){
        ll i = q.front().first;
        ll j = q.front().second;
        q.pop();
        if(!vis[i]){
            vis[i] = 1;
            for(auto it: adj[i]){
                if(it.first == j) continue;
                //cout<<it.first<<" "<<vis[it.first]<<endl;
                if(vis[it.first] == 0)
                    q.push({it.first,i});
                else
                    ans.insert(it.second);
            }
        }
    }
}

//<<-----Start of Main--------------->>//
void MAIN(){
	cin>>n>>m>>k;
	s[0]=s[n+1]=string(m+2,'#');
    for(ll i=1; i<=n; i++){
        for(j=1;j<=m;j++){
        	cin>>x;
        	if(x == 0)s[i][j] = '#';
        	else if(x == 1)s[i][j] = '.';
        	else s[i][j] = '*';
    	}
    	s[i] = '#' + s[i] + "#";
	}

    for(ll i=1; i<=n; i++){
        for(j=1;j<=m;j++){
        	if(s[i][j] == '*')q.push({i,j});

    bfs();
    cout<<ans.size()<<endl;
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;

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