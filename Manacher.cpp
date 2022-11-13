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
struct Manacher{
    string s="";
    vector<int> lp;
    Manacher(string s){
        for (char c: s){
            this->s+='#';
            this->s+=c;
        }
        this->s="$"+this->s+"#~";
        manacher();
    }
    void manacher(){
        int n=s.size()-2;
        int l=1,r=1;
        lp.pb(0);
        for (int i=1;i<=n;i++){
            int v=max(0,min((l+r-i<lp.size() ? lp[l+r-i] : 1000000000),r-i));
            while (s[i-v]==s[i+v]) v++;
            if (i+v>r){
                l=i-v,r=i+v;
            }
            lp.pb(v);
        }
        lp=vector<int>(begin(lp)+1,end(lp));
        return;
    }
    bool is_palindrome(int l, int r){
        return lp[l+r+1]>=r-l+1;
    }
};
int main(){
    string s="racecar";
    Manacher p(s);
    print(p.is_palindrome(1,5));
}
