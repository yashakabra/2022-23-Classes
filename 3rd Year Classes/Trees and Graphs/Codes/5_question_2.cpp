// #pragma GCC optimize "Ofast"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>
#include<stack>
#include<map> 
#define ll                   long long
#define skip                 cin>>ws;
#define vll                  vector<ll> 
#define vb                   vector<bool>
#define vpll                 vector<pair<ll,ll>>
#define vi                   vector<int>
#define vpi                  vector<pair<int, int>>
#define vvll                 vector<vector<ll>>
#define vvi                  vector<vector<int>>
#define vvvll                vector<vector<vector<ll>>>
#define pll                  pair<ll,ll>
#define vs                   vector<string>
#define vvpll                vector<vector<pair<ll, ll>>>
#define vvpi                 vector<vector<pair<int, int>>>
#define pb                   push_back
#define pob                  pop_back()
#define MOD                  (ll)(1000000000 + 7)
#define MOD2                 (ll)(998244353)
#define INF                  (ll)(1000000000000000000 + 5)
#define count1(n)            __builtin_popcountll(n)
#define all(x)               begin(x), end(x)
#define sz(x)                (int)x.size()
#define pi                   pair<int, int>

using namespace std;

template<typename T> istream& operator>>(istream &cin, pair<T, T> &v) {cin>>v.first>>v.second; return cin;}
template<typename T> istream& operator>>(istream &cin, vector<T> &v) {for(T &e: v) cin>>e; return cin;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void JUDGE()
{
    #ifndef ONLINE_JUDGE
    freopen("test_file.txt", "r", stdin);
    freopen("test_file_out.txt", "w", stdout);
    #endif
}

ll inline mo(ll a){ return a%MOD;}

ll po(ll x, ll y, ll p)
{
    ll res = 1; x = x % p;   
    while (y > 0) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } 
    return res%p; 
}

void test_case();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases = 1;
    // cin>>test_cases;

    while(test_cases--) {
        test_case();
    }

    return 0;
}   

int n, m;
vector<int> vis;
vector<vector<int>> g;

void dfs(int par, int dep = 0){
    vis[par] = 1;
    for(int e: g[par]){
        if(!vis[e]){
            dfs(e, dep + 1);
        }
    }
}

void using_dfs(){
    int ans = 0;
    vis.assign(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }

    cout<<"Using dfs: "<<ans<<"\n";
}

void bfs(int par){
    queue<int> q;
    q.push(par);
    vis[par] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int e: g[x]){
            if(!vis[e]){
                vis[e] = 1;
                q.push(e);
            }
        }
    }
}

void using_bfs(){
    int ans = 0;
    vis.assign(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans++;
            bfs(i);
        }
    }

    cout<<"Using bfs: "<<ans<<"\n";
}

void test_case()
{
    cin>>n>>m;

    g.assign(n, {});

    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    using_dfs();

    using_bfs();
}
