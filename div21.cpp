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
ll n,i,j,m;
string s[10000];
map<string,ll>map1;
set<string>set1;
vector<string>v1,v2;
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
	cin >>n>>m;
	string s1,s2,temp;
	ll flag = 0;
	for(i = 0;i<n;i++)
	{
		cin>>s[i];map1[s[i]]++;
	}
	for(i=0;i<n;i++)
	{
		flag = 0;ll len = s[i].size();
		for(j=0;j<len;j++)
        {
            if(s[i][j] != s[i][len-j-1]){flag = 1;break;}
        }   
        ll c = 0;
        if(!flag){c = 1;set1.insert(s[i]);}

		if(map1[s[i]]>c)
		{
			s1 = s[i];
			reverse(s[i].begin(),s[i].end());
			temp = s1;
			s1 = s[i];
			s[i] = temp;
			if(map1[s1]>c)
			{
				v2.pb(s[i]);v1.pb(s1);
				map1[s[i]]--;map1[s1]--;
			}
		}
	}
	ll len1 = v1.size();
	ll len2 = v2.size();

	for(i = 0;i<len1;i++)s2+=v1[i];
	ll max1 = -1;
	for(auto it:set1){max1 = max(map1[it],max1);}

	for(auto it:set1)
	{
		if(map1[it] == max1)
		{
			for(i=0;i<max1;i++)s2+=it;
			break;
		}
	}



	for(i =len2-1;i>=0;i--)s2+=v2[i];
	cout<<s2.size()<<endl<<s2;

	
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