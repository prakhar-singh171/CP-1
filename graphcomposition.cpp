

#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define maxf(v) *max_element(v.begin(), v.end())
#define minf(v) *min_element(v.begin(), v.end())
#define revr(v) reverse(v.begin(), v.end())
#define inp(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &i : v) cout << i << " ";
#define tvs(v) for (auto &i : v)
#define rsort(v) sort(v.rbegin(), v.rend())
#define suv(s) set<int> s
#define mpg(s) map<int, int> s
#define pb push_back
#define pp pop_back
#define bb(v) v.back()
#define ss second
#define ff first
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rr return
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define summ(x) accumulate(all(x), 0LL)
#define prt(x) cout << x << endl
#define bk break
#define lb lower_bound
#define up upper_bound
#define lld long double
#define int long long
#define ull unsigned int
#define ll int
const int mod = 998244353;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
 namespace Disjoint{
    class DisjointSet {
    public:
    vector<int> rank, parent, size; 

    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node]=findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
}
 using namespace Disjoint;
void solve() {
   

   int n,m1,m2;

   cin>>n>>m1>>m2;
   vector<pair<int,int>> ed1(m1),ed2(m2);

   for(auto &i:ed1) cin>>i.first>>i.second;
    for(auto &i:ed2) cin>>i.first>>i.second;

    vector<vector<int>> adj(n+2),adj1(n+2);
    vector<int> vis(n+2,0),vis1(n+2,0);

    for(auto i:ed1){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    for(auto i:ed2){
        adj1[i.first].push_back(i.second);
        adj1[i.second].push_back(i.first);
    }
    int ans=0;
    int lll=0;
    set<pair<int,int>> t1;
    rep(i,1,n+1){
        queue<int> q;
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            set<int> tt;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                tt.insert(it);
                for(auto j:adj1[it]){
                    if(!vis[j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }

            debug(tt);
            if(tt.size()==1) {
                for(auto j:adj[*tt.begin()]){
                    t1.insert({min(j,*tt.begin()),max(j,*tt.begin())});
                }
             continue;}
            int x1=0;
            bool ff=1;
            for(auto it:tt){
               int x2=0;
                for(auto j:adj[it]){
                    if(tt.find(j)==tt.end()) {
                        t1.insert({min(it,j),max(it,j)});
                    }
                    else x2++;
                }
                if(x2==0) x1++;
                else ff=0;
               
            }
            if(!ff) ans+=x1;
            else
            ans+=max(0LL,x1-1);






        }
    }
    lll/=2;
    ans+=lll;

    cout<<ans+t1.size()<<endl;


}

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
    freopen("input2.txt", "w", stdout);

    freopen("error1.txt", "w", stderr);
#endif

    fast();
    int test=1;
    cin >> test;
    while (test--) solve();

    return 0;
}

