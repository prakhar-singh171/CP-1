#include <bits/stdc++.h>
using namespace std;

#define ss second
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
const int mod = 1000000007;
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
 




void solve() {
    int d,x,k; cin>>d>>x>>k;
    int t1=x;
    int t2=d-x;
    if(k==1) {cout<<min(t1,t2)<<endl; rr;}
    if(k==2) {cout<<max(t1,t2)<<endl; rr;}
    multiset<int> ms;
    ms.insert(t1); ms.insert(t2);
    vector<int> ans={t1,t2};
    while(ans.size()!=(2*k)){
        int t1=*ms.begin();
        ms.erase(ms.find(t1));
        ms.insert(t1+d);
        ans.push_back(t1+d);
    }
    sort(all(ans));
    debug(ans);
    cout<<ans[k-1]<<endl;
}

void solve1(){
    int d1,d2,x,y,k;
    cin>>d1>>d2>>x>>y>>k;
    int low=1;
    int high=1e18;
    int ans;
    int p1 = x,p2 = d1-x;
    int q1 = y,q2 = d2-y;
    int nn;
    while(low<=high){
        int mid=low+(high-low)/2;
        int c1 = (mid-p1)/d1 + 1 + (mid-p2)/d1 + 1;
        int c2 =  (mid-q1)/d2 + 1 + (mid-q2)/d2 + 1;
        if(mid<p1) c1--; if(mid<p2) c1--;
        if(mid<q1) c2--; if(mid<q2) c2--;
       debug(p1);debug(p2);debug(q1);debug(q2);debug(c1); debug(c2); debug(mid);
        // if((c1+c2)>k){
        //     high=mid-1;
        // }
        // else if((c1+c2)<k) low=mid+1;
        // else {ans=mid; brea
       //k;}

       if((c1+c2)==k || (c1+c2)==k+1 || (c1+ c2)==k-1) {nn=c1+c2; ans=mid; break;}
       if((c1+c2)<k) low=mid+1;
       else high=mid-1;

    }
    debug(nn);
    if(nn==(k-1)){


         while(1){
            ans++;
        if(((ans-p1) % d1)==0) {  cout<<ans<<endl; rr;}
if(((ans-p2) % d1)==0) {  cout<<ans<<endl; rr;}
if(((ans-q1) % d2)==0) { cout<<ans<<endl; rr;}
if(((ans-q2) % d2)==0) {cout<<ans<<endl; rr;}
       // ans++;
    }
    }
    // debug(ans);
    while(1){
        if(((ans-p1) % d1)==0) { if(nn!=k) nn--; else {cout<<ans<<endl; rr;}}
if(((ans-p2) % d1)==0) {if(nn!=k) nn--;  else {cout<<ans<<endl; rr;}}
if(((ans-q1) % d2)==0) {if(nn!=k) nn--; else {cout<<ans<<endl; rr;}}
if(((ans-q2) % d2)==0) {if(nn!=k) nn--; else {cout<<ans<<endl; rr;}}
        ans--;
    }

}

void solve2(){

    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
        map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[v[i]].push_back(i);
    }

   // deb

    int ans=0;
    debug(mp);
    for(auto it:mp){
        vector<int> v1=it.second; int n1=v1.size();
        debug(v1);
        for(auto &i:v1) i=n-i;
            debug(v1);
            vector<int> suff=v1;
        for(int i=n1-2;i>=0;i--) suff[i]+=suff[i+1];
            debug(suff);
            for(int i=0;i<n1-1;i++) ans+=(it.second[i]+1)*suff[i+1];
    }

    cout<<ans<<endl;

}
 

 void solve3(){
        int n; 
        cin>>n;
        vi v(10000005);
        v[1]=1;
       rep(i,2,10000005){
        v[i]=v[i]^v[i-1];

       }
       debug(v);
       int ans=0;
       rep(i,0,n){
        int xx; cin>>xx;
        ans+=v[xx];
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
   // cin >> test; 
    rep(i, 1, test + 1) solve3();

    return 0;
}