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

//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){

	ll n,i,j,k,flag = 0,flag1 = 0,a,count1 = 0,b;
	cin >> n;
	vector<ll>v;
	for(i=0;i<n;i++)cin>>a,v.pb(a);
	
	for(i=0,j=n-1;i<n,j>=0;i++,j--)
	{
		
		
		if(v[i]<count1)
		{
			for(k=0;k<i;k++)v[k] = k;v[i-1] = a;count1 = 0;
			for(k = n-1;k>=i-1;k--)
			{
				if(v[k]<count1){flag = 1;break;}count1++;
			}
			if(flag)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			return;

		}
		else a = v[i];
		
		if(v[j] < count1)
		{
			for(k=n-1;k>j;k--)v[k] = (n-1)-k;v[j+1] = b;count1 = 0;
			for(k = 0;k<=j+1;k++)
			{
				if(v[k]<count1){flag1 = 1;break;}count1++;
			}
			if(flag1)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			return;
		}
		
		else b = v[j];
		//cout<<v[i]<<" "<<v[j]<<" "<<count1<<endl;
		count1++;
	}
	if(!flag&&!flag1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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