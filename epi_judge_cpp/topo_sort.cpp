#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
  int V;
  list <int> * adj;
  queue <int> q;
  void Dfs_helper(int v, bool visit[]);
  public :
  Graph(int V);
  void AddEdge(int v , int w);
  void Dfs(int v);
  void Bfs(int v);
  void topo_sort(int v);
  void topo_helper(int v, bool visit[], stack<int> &s);
};

Graph :: Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph :: AddEdge(int v , int w) {
  adj[v].push_back(w);
}

void Graph :: Dfs_helper(int v, bool visit[]) {
  visit[v] = true;
  cout << v << " ";

  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if(!visit[*i])
      Dfs_helper(*i,visit);
  }
}

void Graph::Dfs(int v) {
  bool * visit = new bool[V];
  int i;
  for(i=0;i<V;i++)
    visit[i] = false;

  Dfs_helper(v,visit);
}

void Graph::Bfs(int v) {
  bool * visit = new bool[V];
  int i;
  for(i=0;i<V;i++)
    visit[i] = false;

  visit[v] = true;
  q.push(v);

  while(!q.empty()) {
    v = q.front();
    q.pop();

    cout << v << " ";
    visit[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if(!visit[*i]) {
        q.push(*i);
        visit[*i] = true;
      }
    }
  }
}

void Graph::topo_helper(int node,bool visit[] ,stack<int> &s){

  visit[node] = true;
  list<int>::iterator i;
  int flag = 0;
  for (i = adj[node].begin(); i != adj[node].end(); ++i) {
    if(!visit[*i]) {
      flag = 1;
      topo_helper(*i,visit,s);
    }
  }
  s.push(node);
}
 
void Graph::topo_sort(int v) {
  bool visit[V];
  stack<int> s;
  int i,j,k;
  for(i=0;i<V;i++) {
    visit[i] = false;
  }
  
  for(i=0;i<V;i++) {
    if(visit[i] == false)
      topo_helper(i,visit,s);
  }
  cout << "TOPO SORT IT IS\n";
  while(s.empty() == false) {
    cout << s.top() << " ";
    s.pop();
  }
}

int main () {
  Graph g(6); 
  g.AddEdge(5, 2); 
  g.AddEdge(5, 0); 
  g.AddEdge(4, 0); 
  g.AddEdge(4, 1); 
  g.AddEdge(2, 3); 
  g.AddEdge(3, 1); 
/*  
  cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
  g.Dfs(2);
  cout << "Following is B First Traversal \n";
  g.Bfs(2);  
  */
  g.topo_sort(0);
 return 0; 
}

