#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define vpll vector<pair<long,long>> 
#define pii pair<int,int>
#define pll pair<long,long>


void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    cout<<0<<" "<<0<<" "<<min(x,y)<<" "<<min(x,y)<<endl;
    cout<<0<<" "<<min(x,y)<<" "<<min(x,y)<<" "<<0<<endl;
}


int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}