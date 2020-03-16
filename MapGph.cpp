#include<bits/stdc++.h>
using namespace std;

class MapGph {
    map<int,vector<int>> gph;
    int v;
public:
    MapGph(int v) {
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

    void show() {
        for(auto i=gph.begin();i!=gph.end();i++) {
            cout<<i->first<<": ";
            for(auto j=i->second.begin();j!=i->second.end();j++)
                cout<<*j<<" ";
            cout<<endl;
        }
    }
};

int main() {
    // Nodes: 0,1,2,3,....
    MapGph m(4);
    m.init();
    m.addEdge(0,1);
    m.addEdge(1,2);
    m.addEdge(2,3);
    m.addEdge(3,0);
    m.addEdge(0,2);
    m.show();
    return 0;
}