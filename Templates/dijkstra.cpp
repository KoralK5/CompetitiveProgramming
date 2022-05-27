#include <iostream>
#include <map>
#include <list>
#include <climits>
#include <set>
using namespace std;

template <typename T>
class Graph{
public:
    int v;
    map<T,list<pair<T,int>>>l;
    void addEdge(T u,T v,int wt,bool bidir=true){
        l[u].push_back(make_pair(v,wt));
        if(bidir){
            l[v].push_back(make_pair(u,wt));
        }
    }
    void print(){
        for(auto it=l.begin();it!=l.end();it++){
            cout<<it->first<<" -> ";
            for(auto it1=it->second.begin();it1!=it->second.end();it1++){
                cout<<"("<<it1->first<<","<<it1->second<<"),";
            }
            cout<<"\n";
        }
    }
    void dijkstra(T src){
        map <T,int>dist;
        for(auto i=l.begin();i!=l.end();i++){
            dist[i->first]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int,T>>s;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p=*(s.begin());
            T node=p.second;
            int nodeDist=p.first;
            s.erase(s.begin());
            for(auto i=l[p.second].begin();i!=l[p.second].end();i++){
                if(nodeDist+i->second<dist[i->first]){
                    T dest=i->first;
                    auto f= s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=nodeDist+i->second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d=dist.begin();d!=dist.end();d++){
            cout<<d->first<<" is located at distance of "<<d->second<<"\n";
        }
    }
};

int main() {
    Graph <string>g;
    g.addEdge("amritsar","delhi",1);
    g.addEdge("amritsar","jaipur",4);
    g.addEdge("jaipur","delhi",2);
    g.addEdge("jaipur","mumbai",8);
    g.addEdge("bhopal","agra",2);
    g.addEdge("mumbai","bhopal",3);
    g.addEdge("agra","delhi",1);
    g.print();
    cout<<"\n";
    g.dijkstra("amritsar");
    return 0;
}
