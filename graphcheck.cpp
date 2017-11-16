#include <iostream>
#include <vector>
using namespace std;

class graph{
int v;
vector<int> *adj;
public:
    graph(int vertices){
    v = vertices;
    adj = new vector<int>[v];
    }
    void addEdge(int v,int w);
    void print();
    };

void graph::addEdge(int v , int w){
adj[v].push_back(w);
}
void graph::print(){
for(int i=0 ; i<v ; i++){
     for(int j=0 ; j<adj[i].size() ; j++){
        cout<<adj[i][j]<<" ";
     }
     cout<<endl;
}
}
int main()
{
    int v  = 5;
    graph gr(5);
    gr.addEdge(0, 1);
    gr.addEdge(0, 4);
    gr.addEdge(1, 2);
    gr.addEdge(1, 3);
    gr.addEdge(1, 4);
    gr.addEdge(2, 3);
    gr.addEdge(3, 4);
    gr.print();
    return 0;
}
