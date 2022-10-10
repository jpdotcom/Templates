#include <bits/stdc++.h>
#define print(x) cout<<x<<'\n';
using namespace std;
//Segment Tree (With Lazy Prop)

struct node{
    long long val=0;
    long long lazy=0;
    int l,r;
    struct node *leftChild,*rightChild;
    node(int lv,int rv){
        l=lv,r=rv;
        if (l!=r){
            int m=(l+r)/2;
            leftChild=new node(l,m);
            rightChild=new node(m+1,r);
        }
    }
    void prop(){
        val+=(r-l+1)*lazy;
        if (l!=r){
            leftChild->lazy+=lazy;
            rightChild->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(int ql, int qr){
        prop();
        if (qr<l || ql>r) return 0;
        if (ql<=l && r<=qr){
            return val;
        }
        return leftChild->query(ql,qr)+rightChild->query(ql,qr);
    }
    void update(int ql, int qr, int v){
        prop();
        if (qr<l || ql>r) return;
        if (ql<=l && r<=qr){
            val+=(r-l+1)*v;
            if (l!=r){
                leftChild->lazy+=v;
                rightChild->lazy+=v;
            }
        }
        else{
            leftChild->update(ql,qr,v),rightChild->update(ql,qr,v);
            val=leftChild->val+rightChild->val;
        }
    }
};
int main(){
    int arr[5]={1,1,1,1,1};
    int n=5;
    node st(0,n-1);
    for (int i=0;i<5;i++){
        st.update(i,i,arr[i]);
    }
    st.update(3,4,-100);
    print(st.query(0,3));
    return 0;
}
