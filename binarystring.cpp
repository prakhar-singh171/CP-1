<<<<<<< HEAD
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


void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    int left=1;
        int right=n-2;
        while(left<right){
            int left1=left-1;
            int right1=right+1;
            if(v[left1]!=v[left] && v[right1]!=v[right]) {left++; right--; continue;}
            if(v[left1]==v[left] && v[right1]==v[right] && v[left1]==v[right1]){
                swap(v[left1],v[right1]);
            } 
            if(v[left1]==v[left] || v[right1]==v[right]){
                debug(left);
                if((left-2)<0) swap(v[left1],v[right1]);
                else{
                    if(v[left1]!=v[right+2] || v[right1]!=v[left-2]) swap(v[left1],v[right1]);
                }
            }  



            left++;
            right--;

        }
        int ans=0;
        rep(i,0,n-1){
            if(v[i]==v[i+1]) ans++;
        }
        cout<<ans<<endl;
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
    rep(i, 1, test + 1) solve();

    return 0;
}
=======
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
//   int n; cin>>n;
//   vi v(n),v1(n);
//   for(auto &i:v) cin>>i;
//     for(auto &i:v1) cin>>i;
//     vector<vector<pair<int,int>>> adj(n+2,vector<int>());
//     rep(i,0,n){
//         adj[i].push_back({v1[i],v[i]});
//         if(i>=1){
//             adj[i].push_back({i-1,0});
//         }
//     }

//     vector<int> dist(n+2,1e11);
//     vector<int> vis(n+2,0);
//     dist[0]=0;
//     multiset<pair<int,int>> ms;
//     ms.insert({0,0});
//     while(!ms.empty()){
//         auto it=*ms.begin();
//         ms.erase(ms.find(it));
//         if(it.first>dist[it.second]) continue;
//         for(auto j:adj[it.second]){
//             if(dist[j.second]>it.first+j.first){
//                 dist[j.second]=it.first+j.first;
//                 ms.insert({dist[j.second],j.second});
//             }
//         }
//     }

//     vi pre=v;
//     rep(i,1,n) pre[i]+=v[i-1];
//     int ans=0;
//     rep(i,0,n){
//         ans=max(ans,pre[i]-dist[i]);
//     }
//     cout<<ans<<endl;

// }

void solve(int xx) {
    string st;
    cin>>st;
    int n=st.size();
    int ones=0;
    for(auto i:st){
        if(i=='1') ones++;
    }
    
    int zeroes=n-ones;
    int tt=0;
    vi pre={0};
    for(auto i:st){
        if(i=='1'){
            pre.pb(tt);

        }
        else tt++;
    }
    tt=0;
    vi suff={0};
        for (int i = st.size() - 1; i >= 0; i--) {
        if (st[i] == '1') {
            suff.push_back(tt);
        } else {
            tt++;
        }
    }    debug(pre); debug(suff);

    int low=0;
    int high=ones;
    while(low<=high){
        int mid=(low+high)/2;
        auto f=[&](int mid){
            rep(i,0,mid+1){
                int n1=zeroes-(pre[i+1]+suff[mid+1-i]);
                debug(n1); debug(i);debug(mid);
                if(n1<=mid) return true;
            }
            return false;
        };
        if(f(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;

        }
    }
    cout<<ans<<endl;
}

// void solve(int xx) {
//     string st;
//     cin >> st;
//     int n = st.size();
//     int ones = 0;

//     for (auto i : st) {
//         if (i == '1') ones++;
//     }

//     int zeroes = n - ones;
//     int tt = 0;
//     vector<int> pre = {0};

//     for (auto i : st) {
//         if (i == '1') {
//             pre.push_back(tt);
//         } else {
//             tt++;
//         }
//     }

//     tt = 0;
//     vector<int> suff = {0};

//     for (int i = st.size() - 1; i >= 0; i--) {
//         if (st[i] == '1') {
//             suff.push_back(tt);
//         } else {
//             tt++;
//         }
//     }

//     // Debug output removed for final version, but you can include it for testing
//      debug(pre); debug(suff);

//     int low = 0;
//     int high = ones;
//     int ans = 0;

//     while (low <= high) {
//         int mid = (low + high) / 2;

//         auto f = [&](int mid) {
//             for (int i = 0; i <= mid; i++) {
//                 int n1 = zeroes - (pre[i] + suff[mid - i]);
//                 if (n1 >= mid) return true;
//             }
//             return false;
//         };

//         if (f(mid)) {
//             ans = mid;
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }

//     cout << ans << endl;
// }

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
    rep(i, 1, test + 1) solve(i);

    return 0;
}
>>>>>>> 5d98964f85d79a4f1b8b818f53cd6a210e1aff41
