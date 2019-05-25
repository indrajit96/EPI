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
  int find_cycle();
  int find_cycle_utils(int start, bool visit[], bool stack[]);
};

int Graph::find_cycle_utils(int node, bool visit[], bool stack[]) {
  if(!visit[node]) {
    visit[node] = true;
    stack[node] = true;
    list<int>::iterator i;
   for (i= adj[node].begin(); i!= adj[node].end(); ++i) {
     if(stack[*i])
       return true;
     if(!visit[*i] && find_cycle_utils(*i,visit,stack))
       return true;
   }
  }
  stack[node] = false;
  return false;
}

int Graph::find_cycle() {
  int i;
  bool stack[V];
  for(i=0;i<V;i++) {
    stack[i] = false;
  }
  bool visit[V];
  for(i=0;i<V;i++) {
    stack[i] = false;
  }

  for(i=0;i<V;i++) {
    if(find_cycle_utils(i,visit,stack)) {
      printf("A cycle");
      return true;
    }
  }
  return false;
}

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
  g.AddEdge(1, 2); 
  g.AddEdge(2, 3); 
  /*
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
  */
  g.find_cycle();

 return 0; 
}

