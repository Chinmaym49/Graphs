#include<bits/stdc++.h>
using namespace std;

class BFS {
    vector<vector<int>> gph;
    int v;
public:
    BFS(int v) {
        this->v=v;
    }

    void init() {
        for(int i=0;i<v;i++) {
            vector<int> g;
            g.assign(v,0);
            gph.push_back(g);
        }
    }

    void addEdgeUnD(int s,int d) {
        gph[s][d]=1;
        gph[d][s]=1;        
    }

    void addEdgeD(int s,int d) {
        gph[s][d]=1;
    }

    void bfs(int s) {
        queue<int> q;
        vector<bool> vis;
        vis.assign(v,false);
        q.push(s);
        vis[s]=true;
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            cout<<x<<" ";
            for(int i=0;i<v;i++) {
                if(gph[x][i] && !vis[i]) {
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        cout<<endl;
    }


};

int main() {
    // Nodes: 0,1,2,3,....
    BFS v1(4);
    v1.init();
    v1.addEdgeUnD(0,1);
    v1.addEdgeUnD(0,2);
    v1.addEdgeUnD(1,2);
    v1.addEdgeUnD(1,3);
    v1.addEdgeUnD(2,3);
    v1.bfs(0);
    BFS v2(3);
    v2.init();
    v2.addEdgeD(0,1);
    v2.addEdgeD(2,0);
    v2.addEdgeD(2,1);
    v2.bfs(0);
    return 0;
}