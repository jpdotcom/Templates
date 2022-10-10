#include <bits/stdc++.h>
#define print(x) cout<<x<<'\n';
#define pb push_back
using namespace std;
struct DSU{
    vector<int> p;
    vector<int> s;
    int limit;
    DSU(int l){
        limit=l;
        p=vector<int>(limit+1);
        s=vector<int>(limit+1,1);
        p[0]=s[0]=0;
        for (int i=1;i<=limit;i++) p[i]=i;
    }
    int find(int a){
        return (p[a]==a ? a : p[a]=find(p[a]));
    }
    void unite(int a, int b){
        if ((a=find(a)) == (b=find(b))) return;
        else{
            if (s[a]>s[b]) swap(a,b);
            s[b]+=s[a];
            p[a]=b;
            return;
        }
    }
    vector<vector<int>> get_components(){
        vector<vector<int>> c(limit+1);
        for (int i=1;i<=limit;i++){
            c[find(i)].pb(i);
        }
        vector<vector<int>> out;
        for (int i=1;i<=limit;i++){
            if (c[i].size()>=1) out.pb(c[i]);
        }
        return out;
    }
};
int main(){

    DSU dj(5);
    dj.unite(1,2);
    dj.unite(3,4);
    dj.unite(2,5);
    vector<vector<int>> vals=dj.get_components();
    for (auto x: vals){
        for (auto y:x){
            cout<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
}
