#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int mxSize=2;
const char baseChar='0';
struct Vertex{
    int next[mxSize];
    int cnt=0;
    Vertex(){
        fill(begin(next),end(next),-1);
    }
};
struct Trie{
    vector<Vertex> t;
    Trie(){
        Vertex root;
        t.push_back(root);
    }
void insert(string s){
    int v=0;
    for (int i=0;i<s.size();i++){
        int idx=s[i]-baseChar;
        if (t[v].next[idx]==-1){
            t[v].next[idx]=t.size();
            Vertex u;
            t.push_back(u);
        }
        v=t[v].next[idx];
    }
    t[v].cnt++;
}
void remove(string s){

    int v=0;
    for (int i=0;i<s.size();i++){
        int idx=s[i]-baseChar;
        if (t[v].next[idx]==-1) return;
        v=t[v].next[idx];
    }
    t[v].cnt--;
}
void search(){
}
};

int main(){
    return 0;
}
