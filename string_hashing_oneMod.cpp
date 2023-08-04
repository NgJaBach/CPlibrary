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
const int N=1000050,M=1000000007;
const ll INF=1e18+7;
int base=2017;
ll basepow[N];
struct hashing{
    ll hashstr[N];
    int n;
    void Create(string s){
        n=(int)s.size();
        hashstr[0]=0;
        for(int i=1;i<=n;++i) hashstr[i]=(hashstr[i-1]*base+s[i-1])%M;
//        for(int i=1;i<=n;++i) cout<<hashstr[i]<<" "; cout<<endl;
        return;
    }
    int counting(int m,int hashval){
        ll num;
        int cnt=0;
        for(int i=m;i<=n;++i){
            num=(hashstr[i]-(hashstr[i-m]*basepow[m])%M+M)%M;
            if(num==hashval) ++cnt;
        }
        return cnt;
    }
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    basepow[0]=1;
    for(int i=1;i<N;++i) basepow[i]=(basepow[i-1]*base)%M;
    string a,b;
    cin>>a>>b;
    hashing hashA,hashB;
    hashA.Create(a);
    hashB.Create(b);
    cout<<hashA.counting(hashB.n,hashB.hashstr[hashB.n]);
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

