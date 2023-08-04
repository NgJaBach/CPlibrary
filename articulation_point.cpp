// NgJaBach: Forever Meadow <3

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;
int dis[N],low[N],cnt;
vector<int>gay[N];
bool ok[N];
void dfs(int u,int p=-1){
    int children=0;
    ++cnt;
    dis[u]=cnt;
    low[u]=cnt;
    for(auto v:gay[u]){
        if(v==p) continue;
        if(dis[v]) low[u]=min(low[u],low[v]);
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if((p!=-1) and (dis[u]<=low[v])) ok[u]=true;
            ++children;
        }
    }
    if((p==-1) and (children>1)) ok[u]=true;
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y,m;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        ok[i]=false;
        dis[i]=0;
    }
    cnt=0;
    for(int i=1;i<=n;++i){
        if(dis[i]) continue;
        dfs(i);
    }
    vector<int>ans;
    for(int i=1;i<=n;++i) if(ok[i]) ans.pb(i);
    cout<<(int)ans.size()<<endl;
    for(auto tmp:ans) cout<<tmp<<" ";
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

