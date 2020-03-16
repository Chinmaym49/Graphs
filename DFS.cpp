#include<bits/stdc++.h>
using namespace std;

class DFS {
    map<int,vector<int>> gph;
    int v;
public:
    DFS(int v) {
        this->v=v;
    }

    void init() {
        for(int i=0;i<v;i++) {
            vector<int> g;
            gph.insert(pair<int,vector<int>>(i,g));
        }
    }

    void addEdge(int s,int d) {
        gph[s].push_back(d);
        gph[d].push_back(s);
    }

    void dfs(int s) {
        stack<int> st;
        vector<bool> vis;
        vis.assign(v,false);
        st.push(s);
        vis[s]=true;
        cout<<s<<" ";
        while(!st.empty()) {
            int x=st.top();
            auto i=gph[x].begin();
            for(;i!=gph[x].end();i++) {
                if(!vis[*i]) {
                    cout<<*i<<" ";
                    vis[*i]=true;
                    st.push(*i);
                    break;
                }
            }
            if(i==gph[x].end())
                st.pop();
        }
        cout<<endl;
    }

};

int main() {
    // Nodes: 0,1,2,3,....
    DFS m(4);
    m.init();
    m.addEdge(0,1);
    m.addEdge(1,2);
    m.addEdge(2,3);
    m.addEdge(3,0);
    m.addEdge(0,2);
    m.dfs(0);
    return 0;
}