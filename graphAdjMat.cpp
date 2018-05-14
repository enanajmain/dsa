#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"

#ifndef NULL_VALUE
#define NULL_VALUE -999999
#endif

#ifndef INFINITY
#define INFINITY 999999
#endif

class Graph {
public:
  Graph(bool, int, int);
  ~Graph();
  bool isEdge(int, int);
  void addEdge(int u, int v);
  void removeEdge(int u, int v);
  int getDegree(int u);
  void dfs(int);
  void bfs(int);
private:
  bool isDirected;
  int ** adjMat;
  int noOfVertices;
  int noOfEdges;
};

Graph::Graph(bool isDirected, int noOfVertices, int noOfEdges) {
  this->isDirected = isDirected;
  this->noOfVertices = noOfVertices;
  this->noOfEdges = noOfEdges;
  adjMat = new int * [noOfVertices];
  for (int i=0; i<noOfVertices; i++) {
    adjMat[i] = new int[noOfVertices];
    for (int j=0; j<noOfVertices; ++j)
      adjMat[i][j] = 0;
  }
}

Graph::~Graph() {
  for (int i=0; i<noOfVertices; ++i)
    if (adjMat[i])
      delete[] adjMat[i];
  if (adjMat) delete[] adjMat;
  adjMat = NULL;
}

bool Graph::isEdge(int u, int v) {
  return adjMat[u][v];
}

void Graph::addEdge(int u, int v)
{
  if(u<0 || u>=noOfVertices || v<0 || v>=noOfVertices) return;
  adjMat[u][v] = 1;
  if(!isDirected) adjMat[v][u] = 1;
}

void Graph::removeEdge(int u, int v)
{
  if (u<0 || u>=noOfVertices || v<0 || v>=noOfVertices) return;
  adjMat[u][v] = 0;
  if (!isDirected) adjMat[v][u] = 0;
}

void Graph::dfs(int source) {
  if (source <0 || source >= noOfVertices) return;

  bool * visited = new bool[noOfVertices];
  bool * adjVertex = new bool[noOfVertices];
  for (int i=0; i<noOfVertices; ++i)
    visited[i] = false;

  Stack<int> st(noOfVertices);
  st.push(source);

  while (st.size() > 0) {
    source = st.peek();
    st.pop();
    visited[source] = true;
    std::cout << source << " " ;

    int noOfAdjVertices = 0;
    for (int i=0; i<noOfVertices; ++i) {
      if (isEdge(source, i)) {
        noOfAdjVertices++;
        adjVertex[i] = true;
      } else
        adjVertex[i] = false;
    }

    for (int i=0; i<noOfVertices; ++i) {
      if (!adjVertex[i]) continue;
      else if (!visited[i]) {
        st.push(i);
      }
    }
  }
  std::cout << std::endl;
}

void Graph::bfs(int source) {
  if (source <0 || source >= noOfVertices) return;

  bool * adjVertex = new bool[noOfVertices];
  bool * visited = new bool[noOfVertices];
  for (int i=0; i<noOfVertices; ++i) {
    visited[i] = false;
  }

  Queue<int> q(noOfVertices);
  q.enqueue(source);
  visited[source] = true;
  std::cout << source << " ";

  while (q.size() > 0) {
    source = q.first();
    q.dequeue();

    int noOfAdjVertices = 0;
    for (int i=0; i<noOfVertices; ++i) {
      if (isEdge(source, i)) {
        noOfAdjVertices++;
        adjVertex[i] = true;
      } else
        adjVertex[i] = false;
    }
    for (int i=0; i<noOfVertices; ++i) {
      if (!adjVertex[i]) continue;
      else if (!visited[i]) {
        q.enqueue(i);
        visited[i] = true;
        std::cout << i << " ";
      }
    }
  }
  std::cout << std::endl;
}
