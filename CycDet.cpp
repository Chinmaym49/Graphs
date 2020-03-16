#include<bits/stdc++.h>
using namespace std;

class CycDet {
    map<int,vector<int>> g;
    int v;
public:
    CycDet(int v) {
        this->v=v;
    }

    void init() {
        for(int i=0;i<v;i++) {
            vector<int> x;
            g.insert(pair<int,vector<int>>(i,x));
        }
    }

    void addEdge(int s,int d) {
        g[s].push_back(d);
    }

    bool detect(int s) {
        vector<int> vis;
        vis.assign(v,0);
        vis[s]=1;
        stack<int> st;
        st.push(s);
        while(!st.empty()) {
            int x=st.top();
            auto i=g[x].begin();
            for(;i!=g[x].end();i++) {
                if(*i==s)
                    return true;
                if(!vis[*i]) {
                    st.push(*i);
                    vis[*i]=1;
                    break;
                }
            }
            if(i==g[x].end())
                st.pop();
        }
        return false;
    }
};

int main() {
    CycDet c(4);
    c.init();
    c.addEdge(0,1);
    c.addEdge(1,2);
    c.addEdge(2,3);
    c.addEdge(2,0);
    for(int i=0;i<4;i++)
        cout<<c.detect(i)<<endl;
    return 0;
}