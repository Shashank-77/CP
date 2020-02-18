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
ll i,j,sum,n,x;
vector<ll>v1,v;
map<ll,ll>map1;

//<<-----Implement Functions Here---->>//
 
struct TrieNode{ 
    struct TrieNode* children[2]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode* getNode(){ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEndOfWord = false; 
    for(int i = 0; i < 2; i++) pNode->children[i] = NULL; 
    return pNode; 
} 
 
void insert(struct TrieNode* root, string key){ 
    struct TrieNode* pCrawl = root; 
  
    for(int i = 0; i < 32; i++){
        ll index = key[i]-'0'; 
        if(!pCrawl->children[index]) pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    } 
 
    pCrawl->isEndOfWord = true; 
} 
 
TrieNode* remove(TrieNode* root, string key, ll depth = 0) 
{ 
   
    if (!root) return NULL; 
	if (depth == key.size()) { 
		if (root->isEndOfWord) root->isEndOfWord = false; 
		if (isEmpty(root)) { delete (root); root = NULL; } 
		return root; 
    } 
    ll index = key[depth] - '0'; 
    root->children[index] = remove(root->children[index], key, depth + 1); 
    if (isEmpty(root) && root->isEndOfWord == false) {delete (root); root = NULL; } 
    return root; 
} 

string decToBinary(ll n) { 
	string s;
    for(ll i = 31; i >= 0; i--) { 
		ll k = n >> i; 
		if (k&1) s+="1"; 
		else s+="0"; 
	}
	return s; 
} 
 
int query(struct TrieNode* root,string key)
{
	v1.clear();ll sum1 = 0;
	struct TrieNode* pCrawl = root; 

    for (ll i = 0; i < key.length(); i++) { 
        ll index = key[i] - '0';
        index = 1- index;
        if (pCrawl->children[index] != NULL) 
            v1.pb(index),cout<<index;
       	else if(pCrawl->children[1-index] != NULL)
       	{
       		index = 1- index;cout<<index;
       		v1.pb(index);
       	}

        
        pCrawl = pCrawl->children[index]; 

    } 
    //for(i=0;i<31;i++)cout<<v1[i];cout<<endl;
    for(i=0;i<=31;i++)sum1+=pow(2,i)*v1[31-i];
    //cout<<sum1<<endl;
	return sum1;
}

//<<-----Start of Main--------------->>//
void MAIN(){
	cin >> n;
	struct TrieNode *t = getNode();
	for(i=0;i<n;i++)
	{
		cin>>x,v.pb(x);map1[x]++;
		insert(t,decToBinary(x));
	}
	sort(all(v));ll ans = v[n-1];ll count1 = 0;
	cout<<ans<<endl;
	while(count1!=n)
	{
		x = query(t,decToBinary(ans));
		if(map1[x]>=1)map1[x]--;
		else remove(t,decToBinary(x),0),map1[x]--;
		count1++;
		//cout<<ans<<" "<<x<<" ";
		ans = (ans|x) - x;
		//cout<<ans<<endl;
		cout<<endl;
	}
	//cout<<ans;


	
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