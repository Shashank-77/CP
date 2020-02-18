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
ll pre[10000],prefix[10000];
ll d,m,i,y,n;
ll m1,g1,m2,g2;
ll r1,q1,r2,q2,w1,w2;

//<<-----Implement Functions Here---->>//
ll skips[]={0,3,2,5,0,3,5,1,4,6,2,4};
string DAY[]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

ll dow(ll d, ll m ,ll y){
	y-=m<3;
	return (y + y/4 - y/100 + y/400 + skips[m-1]+d-1)%7;
}

//<<-----Start of Main--------------->>//
void MAIN(){
	cin >> m1 >> g1 >> m2 >>g2;
	if(m1>2)g1++;
	if(m2<2)g2--;
	if(g1 > g2){cout<<0<<endl;return;}
	//if(g1 == g2){cout<<1<<endl;return;}
	r1 = g1%2800;r2 = g2%2800;
	q1 = g1/2800;q2 = g2/2800;
	w1 = 2800*q1;w2 = 2800*q2;
	//cout<<w1<<" "<<w2;
	n = abs(w1-w2)/2800 * prefix[2800];
	n -= prefix[r1-1];n+=prefix[r2];
	cout<<n<<endl;
}

int main(){
	fastio;randomINIT;

	cin>>t;
	prefix[0] = 0;
	for(y=401;y<=3200;y++)
	{
		n = dow(1,1,y);
		if(n == 2||(n == 3 && !((y%4 == 0&&(y%100!=0))||(y%400 == 0))))pre[y-400] = 1;
	}
	for(i=1;i<=2800;i++)prefix[i] = prefix[i-1]+pre[i];
	//for(i = 1;i<=2800;i++)cout<<prefix[i]<<endl;
	while(t--){MAIN();
	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}