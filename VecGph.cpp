#include<bits/stdc++.h>
using namespace std;

class VecGph {
    vector<vector<int>> gph;
    int v;
public:
    VecGph(int v) {
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

    void show() {
        for(auto i=gph.begin();i!=gph.end();i++) {
            for(auto j=i->begin();j!=i->end();j++) {
                cout<<*j<<"\t";
            }
            cout<<endl;
        }
    }

};

int main() {
    // Nodes: 0,1,2,3,....
    VecGph v1(4);
    v1.init();
    v1.addEdgeUnD(0,1);
    v1.addEdgeUnD(0,2);
    v1.addEdgeUnD(1,2);
    v1.addEdgeUnD(1,3);
    v1.addEdgeUnD(2,3);
    v1.show();
    VecGph v2(3);
    v2.init();
    v2.addEdgeD(0,1);
    v2.addEdgeD(2,0);
    v2.addEdgeD(2,1);
    v2.show();
    return 0;
}