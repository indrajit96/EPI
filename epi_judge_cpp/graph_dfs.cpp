#include <iostream>
#include <list>
#include <queue>

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

int main () {
  Graph g(4); 
  g.AddEdge(0, 1); 
  g.AddEdge(0, 2); 
  g.AddEdge(1, 2); 
  g.AddEdge(2, 0); 
  g.AddEdge(2, 3); 
  g.AddEdge(3, 3); 
  
  cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
  g.Dfs(2);
  cout << "Following is B First Traversal \n";
  g.Bfs(2);  
 return 0; 
}

