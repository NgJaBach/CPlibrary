#include <bits/stdc++.h>
#define taskname "hello"
#define vt vector
#define pb push_back
#define vl vt<ll>
#define vvl vt<vl>
#define vi vt<int>
#define vvi vt<vi>
#define vb vt<bool>
#define vvb vt<vb>
#define ii pair<int,int>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define FOR(i,l,r) for(int i = int(l); i <= int(r); ++i)
#define FOD(i,r,l) for(int i = int(r); i >= int(l); --i)
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
const int oo = 1e9;
const ll OO = 1e17;
const ll MOD = 1e9 + 7;
int start = 0;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> void input1(vt<T> &x){
    FOR(i, start, x.size()-1) cin >> x[i];
}
template<class T> void input2(vt<T> &x){
    FOR(i, start, x.size()-1) input1(x[i]);
}
template<class T> void print1(vt<T> &x){
    FOR(i, start, x.size()-1) cout << x[i] << ' ';
    cout << '\n';
}
template<class T> void print2(vt<T> &x){
    FOR(i, start, x.size()-1) print1(x[i]);
}
ll gen(ll a, ll b) {
    return a + (rng() % (b - a + 1));
}
int m, n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(taskname".INP","r",stdin);
    freopen(taskname".inp","w",stdout);
    cout<<rng()%1000+1;
    return 0;
}
