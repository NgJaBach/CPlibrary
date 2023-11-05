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
//#define endl '\n'
const int N=100050,M=1000000007;
const ll INF=1e18+7;
const int NoMatch=-1;
int nx,ny,m;
int match[N];
int level[N];
bool found;
vector<int>adj[N];
vector<int>S;
void Enter(){
    cin>>nx>>ny>>m;
    for(;m>0;--m){
        int x,y;
        cin>>x>>y;
        --x; --y;
        adj[x].pb(y);
    }
    return;
}
void Init(){
    fill(match,match+ny,NoMatch);
    S.reserve(nx);
    for(int x=0;x<nx;++x) S.pb(x);
    return;
}
bool BFS(){
    queue<int>Q;
    fill(level,level+ny,0);
    for(int x:S){
        for(int y:adj[x]){
            if(level[y]==0){
                level[y]=1;
                Q.push(y);
            }
        }
    }
    while(!Q.empty()){
        int ypop,x;
        ypop=Q.front(); Q.pop();
        if((x=match[ypop])==NoMatch) return true;
        for(int y:adj[x]){
            if(level[y]==0){
                level[y]=level[ypop]+1;
                Q.push(y);
            }
        }
    }
    return false;
}
void dfs(int x,int lv){
    for(int y:adj[x]){
        if(level[y]==lv+1){
            level[y]=0;
            if(match[y]==NoMatch) found=true;
            else dfs(match[y],lv+1);
            if(found){
                match[y]=x;
                return;
            }
        }
    }
    return;
}
void solve(){
    for(auto tmp:S) cout<<tmp<<" "; cout<<endl;
    while(BFS()){
        for(int i=(int)S.size()-1;i>=0;--i){
            cout<<"--> "<<i<<endl;
            found=false;
            dfs(S[i],0);
            if(found){
                S[i]=S.back();
                S.pob();
            }
        }
    }
    return;
}
void Print(){
    for(int y=0;y<ny;++y){
        if(match[y]!=NoMatch){
            cout<<"x["<<match[y]<<"] - y["<<y<<"]"<<endl;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen("ASSIGN.inp","r",stdin);
//    freopen("ASSIGN.out","w",stdout);
    Enter();
    Init();
    solve();
    Print();
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4 3 6
1 1
1 3
2 1
2 2
3 2
4 1


------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

