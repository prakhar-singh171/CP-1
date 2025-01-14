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
#define pb push_back
#define pp pop_back
#define bb(v) v.back()
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
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{"; _print(p.ff); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long fpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
#define double long double
#define ss second

int ans;

vi pre;

#define MOD 1000000007

int nC2(int n) {
    if (n < 2) return 0; 
    return (long long)(n) * (n - 1) / 2 % MOD;
}


// void solve(int xx) {
//     int n, k; 
//     cin >> n >> k;
//     set<int> s;
    
//     for (int i = 0; i < k; i++) {
//         int l, r;
//         cin >> l >> r;
//         s.insert(l);
//         s.insert(r);
//     }
    
//     int rem = n - s.size();  
    
//     vector<int> dp(rem + 1);
//     dp[0] = 1;
//     dp[1] = 1;
    
//     for (int i = 2; i <= rem; i++) {
//         int x1 = (long long)nC2(i) * 2 % MOD * dp[i - 2] % MOD;
//         int x2 = i*dp[i - 1] % MOD;
        
//         dp[i] = (x1 + x2) % MOD;
//     }

//     cout << dp[rem] << endl;
// }

void solve1(){
   int n; cin>>n;
   vi a(n); vi b(n);
   for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
        vi pre(n+2,0);
    int diff=-1;
    int save=-1;
    rep(i,0,n){
        if(a[i]>=b[i]) continue;
         diff=b[i]-a[i];
         save=i;
       break;

    }
   rep(i,0,n){
        if(save==i) continue;
        a[i]-=diff;
        if(a[i]<b[i]) {no; rr;}
   }
    yes;
}

void solve2(){

    int n,m; cin>>n>>m; debug(n); debug(m);
    vector<vector<int>> v(n,vector<int>(m));
     string st; cin>>st;
    for(auto &i:v){
        for(auto &j:i) cin>>j;

    }
debug(v);

   
    int sum=0;
    int i=0;
    int j=0;
    if(st[0]=='R') {
        //v[0][0]=-v[n-1][0];
        rep(i,0,n) sum+=v[i][0];
        j++;
    }
    else{i++;  sum=accumulate(all(v[0]),0LL); }
    
    debug(sum);
   // sum=0;
    v[0][0]=-sum; sum=0;
    int previ=i; int prevj=j;
    reverse(all(st)); st.pop_back(); reverse(all(st));
    for(auto i:st){
        if(i=='D') {
            int tt=accumulate(all(v[previ]),0LL);
            v[previ][prevj]=sum-tt;  
            previ++;
        }
    
        else{
            int tt=0;
            rep(i,0,n) tt+=v[i][prevj];
            v[previ][prevj]=sum-tt;
            prevj++;

        }
    }

    int x1=accumulate(all(v[n-1]),0LL);
    v[n-1][m-1]=sum-x1;


        for(auto i:v){
            for(auto j:i) cout<<j<<" ";
                cout<<endl;
        }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("input2.txt", "w", stdout);
        freopen("error1.txt", "w", stderr);
    #endif
   

    int test = 1;
    cin >> test;
    rep(i, 1, test + 1) solve2();

    return 0;
}
