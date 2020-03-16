#include<bits/stdc++.h>
using namespace std;

class Dijkstras {
    vector<vector<int>> g;
    int v;
public:
    Dijkstras(int v) {
        this->v=v;
        for(int i=0;i<v;i++) {
            vector<int> x;
            x.assign(v,0);
            g.push_back(x);
        }
    }

    void addEdge(int s,int d,int w) {
        g[s][d]=w;
        g[d][s]=w;
    }

    vector<int> shortestDist(int s) {
        vector<bool> sp;
        sp.assign(v,false);
        vector<int> dis;
        dis.assign(v,INT_MAX);
        dis[s]=0;
        for(int c=0;c<v;c++) {
            int min=INT_MAX,mini=-1;
            for(int i=0;i<v;i++) {
                if(!sp[i] && min>dis[i]) {
                    mini=i;
                    min=dis[i];
                }
            }
            sp[mini]=true;
            for(int i=0;i<v;i++) {
                if(!sp[i] && g[mini][i]!=0) {
                    dis[i]=std::min(min+g[mini][i],dis[i]);
                }
            }
            
        }
        return dis;
    }

    // for unweighted
    void shortestPath(int s,int d) {
        vector<int> dis;
        dis.assign(v,INT_MAX);
        vector<int> pre;
        pre.assign(v,-1);
        queue<int> q;
        vector<bool> vis;
        dis[s]=0;
        vis.assign(v,false);
        q.push(s);
        vis[s]=true;
        int f=0;
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for(int i=0;i<v;i++) {
                if(g[x][i] && !vis[i]) {
                    q.push(i);
                    vis[i]=true;
                    dis[i]=dis[x]+1;    // Considered unweighted
                    pre[i]=x;
                    if(i==d) {
                        f=1;
                        break;
                    }
                }
            }
            if(f)
                break;
        }
        if(f) {
            cout<<dis[d]<<endl;
            int i=d;
            while(i!=s) {
                cout<<i<<" ";
                i=pre[i];
            }
            cout<<s;
            cout<<endl;
        }
        else
            cout<<s<<" and "<<d<<" are not connected\n";
    }

};

int main() {
    Dijkstras d(6);
    d.addEdge(0,1,4);
    d.addEdge(1,3,8);
    d.addEdge(3,5,7);
    d.addEdge(2,3,3);
    d.addEdge(0,2,8);
    d.addEdge(2,4,2);
    d.addEdge(4,5,14);
    vector<int>dd=d.shortestDist(0);
    for(auto i=dd.begin();i!=dd.end();i++)
        cout<<*i<<endl;
    d.shortestPath(0,5);
    return 0;
}