#include <bits/stdc++.h>
#include <time.h>
typedef long long ll;
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
 ----------------------------------------------------------------------
 Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vi dist;
  
set<pair<int, int> > q; 
  
void bf_help(vi adj[], int s){
    set<pair<int, int> >::iterator it;

    for (int i = 0; i < adj[s].size(); i++){ 
        int v = adj[s][i]; 
        if (dist[s] + 1 < dist[v]){ 
  
            it = q.find({ dist[v], v }); 
            q.erase(it); 
            dist[v] = dist[s] + 1; 
            q.insert({ dist[v], v }); 
        } 
    } 
  
    if (q.size() == 0) 
        return; 
  
    it = q.begin(); 
    int next = it->second; 
    q.erase(it); 
  
    bf_help(adj, next); 
} 
  
void bf(vi adj[], int n, vi &s, int k){ 
    vi source(n +1, 0); 
 
    for (int i = 0; i < k; i++) 
        source[s[i]] = 1;
  
    for (int i = 1; i <= n; i++){ 
        if (source[i]){ 
            dist[i] = 0; 
            q.insert({ 0, i }); 
        } 
        else { 
            dist[i] = INF; 
            q.insert({ INF, i }); 
        } 
    } 

    auto itr = q.begin(); 
    int start = itr->second; 
  
    bf_help(adj, start);
}  


signed main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
 ll t; 
 cin >> t; 
 while(t--){
      int n, m, k, u, v, q;
      cin >> n >> m >> k;

     vi adj[n +1], special(k);

     for(int i = 0; i < m; ++i){
     cin >> u >> v;
     adj[u].push_back(v);
     adj[v].push_back(u);
     }

     for(int i = 0; i < k; ++i){
      cin >> special[i];
     }

     dist = vi(n +1, INF);
     bf(adj, n, special, k);

     cin >> q;
     while(q--){
     cin >> u;
     cout << (dist[u] >= INF ? -1 : dist[u]) << endl;
     }


 }
  
 return 0;
}