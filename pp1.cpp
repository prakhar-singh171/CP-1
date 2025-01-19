#include<bits/stdc++.h>
using namespace std;
#define int long long
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.second;
}


int gcd(int a,int b){
    int res=1;
    while(b>0){
        if(b & 1) res=res*a;
      a=a*a;
        b>>=1;

    }
    return res;
}
int32_t main(){
    vector<pair<int,int>> v={{1,3},{3,5},{3,6}};
    sort(v.begin(),v.end(),compare);
    for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
    cout<<gcd(3,7)<<endl;


}