#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define print(x) cout<<x<<'\n';
using namespace std;
using T=int;
const int MAXN=1e6;
const int MAXK=20;
T st[MAXN][MAXK];
T lg[MAXN+1];
struct SparseTable{
    int N,K;
    SparseTable(int n, int k,T arr[]){
        N=n;
        K=k;
        lg[1] = 0;
        for (int i = 2; i <= N+1; i++)
            lg[i] = lg[i/2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = min(st[i][j-1],  st[i + (1 << (j - 1))][j - 1]);
    }
    T query(int l, int r){
        T j = lg[r - l + 1];
        T minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
        return minimum;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q; 
    cin>>n>>q;
    int arr[n];
    FOR(n) cin>>arr[i];
    SparseTable t(n,20,arr);
    FOR(q){
        int a,b; cin>>a>>b; b--;
        print(t.query(a,b));
    }
    return 0;
}

