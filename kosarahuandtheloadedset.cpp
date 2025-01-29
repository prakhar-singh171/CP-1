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

// namespace trees {
//     class SGTree {
//     public:
//         vi seg;
//         int n;

//         SGTree(int n) {
//             this->n = n;
//             seg.resize(4 * n, 0); 
//         }

//         // Build the segment tree for max sum in a range (1-based index)
//         void build(int ind, int low, int high, vi &arr) {
//             if (low == high) {
//                 seg[ind] = arr[low]; 
//                 return;
//             }
//             int mid = (low + high) / 2;
//             build(2 * ind, low, mid, arr);
//             build(2 * ind + 1, mid + 1, high, arr);
//             seg[ind] = max(seg[2 * ind], seg[2 * ind + 1]); // Store max sum in this range
//         }

//         // Point update (1-based index)
//         void update(int ind, int left, int right, int updind, int val) {
//             if (updind < left || updind > right) return;
//             if (left == right) {
//                 seg[ind] = val;
//                 return;
//             }
//             int mid = (left + right) / 2;
//             if (updind <= mid) 
//                 update(2 * ind, left, mid, updind, val);
//             else 
//                 update(2 * ind + 1, mid + 1, right, updind, val);
            
//             seg[ind] = max(seg[2 * ind], seg[2 * ind + 1]); // Update max sum
//         }

//         // Range Maximum Sum Query (1-based index)
//         int query(int ind, int low, int high, int L, int R) {
//             if (low > R || high < L) return 0;  // No overlap
//             if (low >= L && high <= R) return seg[ind]; // Complete overlap

//             int mid = (low + high) / 2;
//             int leftSum = query(2 * ind, low, mid, L, R);
//             int rightSum = query(2 * ind + 1, mid + 1, high, L, R);
//             return max(leftSum, rightSum);
//         }
//     };
// }

// using namespace trees;


#define I1 INT_MAX
#define I2 INT_MIN
#define END 2500000
const int nn=2000005;
// void solve() {

  
//     SGTree obj(3000000);
//     int n;
//     cin>>n;
//     vector<int> v(3000000,I2);
//     vector<int> v1;
//     set<int> s;

//     while(n--){
//         int x;
//         cin>>x;
//         v1.push_back(x);
//       //  s.insert(x+1);
//     }

//     sort(all(v1));

//     rep(i,0,v1.size()-1){
//         v[v1[i]+1]=v1[i+1]-v1[i]-1;
//         s.insert(v1[i+1]);
//     }
//     if(v1[0]!=1){
//         v[1]=v1[0]-1;
//         s.insert(1);
//     }

//     v[v1.back()+1]=I1;
//     v[0]=I2;
//     s.insert(0);
//     v[END]=0;
//     s.insert(END);
//     s.insert(v1.back());
//     obj.build(v,1,1,2000005);

//     int q;
//     cin>>q;
//     while(q--){
//         char ch; int n1;
//         cin>>ch>>n1;
//         if(ch=='+'){
//             auto it=s.lower_bound(n1);
//             obj.update(1,1,END,n1+1,*it-1-n1);
//            // if(it!=s.begin()){
//                 --it;
//                 obj.update(1,1,END,*it+1,n1-*it-1);
//           //  }
//             s.insert(n1+1); s.insert(*it+1);
//             continue;

//         }
//         if(ch=='-'){
//             obj.update(1,1,end,n1+1,I2);
//             auto it=s.lower_bound(n1);
//             auto it1=it;
//           //  if(it!=s.begin()){
//                 --it;
//                 obj.update(1,1,end,*it+1,*it1-1-*it)
//             s.erase(n1+1); s.insert(*it+1);
//             continue;

//         }

//         int low=1;
//         int high=end;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(obj.query(1,low,mid,1,end)>=n1){
//                 ans=mid;
//                 high=mid-1;
//             }
//             else low=mid+1;
//         }
//         cout<<ans<<endl;


//     }
//     cout<<endl;


//   }



namespace trees {
    class SGTree {
    public:
        vi seg;
        int n;

        SGTree(int n) {
            this->n = n;
            seg.resize(4 * n, I2); // Initialize with very small values
        }

        // Build segment tree (1-based indexing)
        void build(int ind, int low, int high, vi &arr) {
            if (low == high) {
                seg[ind] = arr[low];
                return;
            }
            int mid = (low + high) / 2;
            build(2 * ind, low, mid, arr);
            build(2 * ind + 1, mid + 1, high, arr);
            seg[ind] = max(seg[2 * ind], seg[2 * ind + 1]); // Store max value
        }

        // Update a single point
        void update(int ind, int left, int right, int updind, int val) {
            if (updind < left || updind > right) return;
            if (left == right) {
                seg[ind] = val;
                return;
            }
            int mid = (left + right) / 2;
            if (updind <= mid)
                update(2 * ind, left, mid, updind, val);
            else
                update(2 * ind + 1, mid + 1, right, updind, val);

            seg[ind] = max(seg[2 * ind], seg[2 * ind + 1]); // Update max
        }

        // Range Maximum Query
        int query(int ind, int low, int high, int L, int R) {
            if (low > R || high < L) return I2; // No overlap
            if (low >= L && high <= R) return seg[ind]; // Complete overlap

            int mid = (low + high) / 2;
            int leftMax = query(2 * ind, low, mid, L, R);
            int rightMax = query(2 * ind + 1, mid + 1, high, L, R);
            return max(leftMax, rightMax);
        }
    };
}

using namespace trees;

// void solve() {
//     int NN=nn;
//     SGTree obj(nn);
//     int n;
//     cin >> n;
    
//     vector<int> v(NN, I2);
//     vector<int> v1;
//     set<int> s;

//     // Read input and prepare sorted unique values
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         v1.push_back(x);
//     }

//     sort(all(v1));

//     for (int i = 0; i < v1.size() - 1; i++) {
//         v[v1[i] + 1] = v1[i + 1] - v1[i] - 1;
//         s.insert(v1[i + 1]);
//     }

//     if (v1[0] != 1) {
//         v[1] = v1[0] - 1;
//         s.insert(1);
//     }

//     v[v1.back() + 1] = I1;
//     v[0] = I2;
//     s.insert(0);
//     v[END] = 0;
//     s.insert(END);
//     s.insert(v1.back());
//     //debug(v);

//     // Build segment tree
//     obj.build(1, 1, NN, v);

//    // debug(obj.seg);

//     int q;
//     cin >> q;
    
//     while (q--) {
//         char ch;
//         int n1;
//         cin >> ch >> n1;

//         if (ch == '+') { // Insert new number
//             auto it = s.lower_bound(n1);
//             obj.update(1, 1, END, n1 + 1, *it - 1 - n1);

//             --it;
//             obj.update(1, 1, END, *it + 1, n1 - *it - 1);
            
//             s.insert(n1 + 1);
//             s.insert(*it + 1);
//             continue;
//         }

//         if (ch == '-') { // Remove number
//             obj.update(1, 1, END, n1 + 1, I2);

//             auto it = s.lower_bound(n1);
//             auto it1 = it;
//             --it;
//             obj.update(1, 1, END, *it + 1, *it1 - 1 - *it);

//             s.erase(n1 + 1);
//             s.insert(*it + 1);
//             continue;
//         }

//         // Binary search to find smallest index where max value >= n1
//         int low = 1, high = END, ans = -1;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (obj.query(1, 1, END, low, mid) >= n1) {
//                 ans = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         cout << ans << endl;
//     }
//     cout << endl;
// }

void solve() {
    int NN = nn;
    SGTree obj(nn);
    int n;
    cin >> n;

    vector<int> v(NN, I2);
    vector<int> v1;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    sort(all(v1));

    for (int i = 0; i < v1.size() - 1; i++) {
        v[v1[i] + 1] = v1[i + 1] - v1[i] - 1;
        s.insert(v1[i + 1]);
    }

    if (v1[0] != 1) {
        v[1] = v1[0] - 1;
        s.insert(1);
    }

    v[v1.back() + 1] = I1;
    v[0] = I2;
    s.insert(0);
    v[END] = 0;
    s.insert(END);
    s.insert(v1.back());
    debug(s);

    obj.build(1, 1, NN, v); // Proper segment tree build

    int q;
    cin >> q;
    while (q--) {
        char ch;
        int n1;
        cin >> ch >> n1;

        if (ch == '+') {
            auto it = s.lower_bound(n1);
            obj.update(1, 1, END, n1 + 1, *it - 1 - n1);
            --it;
            obj.update(1, 1, END, *it + 1, n1 - *it - 1);
            s.insert(n1 + 1);
            s.insert(*it + 1);
            continue;
        }

        if (ch == '-') {
            obj.update(1, 1, END, n1 + 1, I2);
            auto it = s.lower_bound(n1);
            auto it1 = it;
            --it;
            obj.update(1, 1, END, *it + 1, *it1 - 1 - *it);
            s.erase(n1 + 1);
            s.insert(*it + 1);
            continue;
        }

        int low = 1, high = END, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (obj.query(1, 1, END, 1, mid) >= n1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("input2.txt", "w", stdout);
    freopen("error1.txt", "w", stderr);
#endif

    fast();
    int test = 1;
    cin >> test;
    while (test--) solve();

    return 0;
}