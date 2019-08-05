#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

class Graph
{
//private
  int V;
  int cnum;

  vector<vector<int> > *adj;
  vector<int> *compnum;
  vector<bool> *vis;

  void explore(int v);

public:  
  Graph(int V);
  void addEdge(int start, int end);
  void DFSconnect();
  void printAns();
};

void Graph::printAns()
{
  std::cout<<"There are "<< cnum<< " components in the graph."<<std::endl;
}

void Graph::DFSconnect()
{
  cnum = 0; //component number
  
  for(int v=0; v<V; v++)
  {
    if(vis->at(v)==false)
    {
      explore(v);
      cnum++;
    }
  }
}

void Graph::explore(int v)
{
  vis->at(v)=true;
  
  for(unsigned int i=0; i < (*adj)[v].size(); i++)
  {
    if(vis->at((*adj)[v][i])==false)
    {
      explore((*adj)[v][i]);
    }
  }
}



Graph::Graph(int vertices)
{
  this->V = vertices;
  adj = new vector<vector<int> >(vertices, vector<int>());
  compnum = new vector<int>(vertices, 0);
  vis = new vector<bool>(vertices, false);
}

void Graph::addEdge(int u, int v)
{
  (*adj)[u].push_back(v);
  (*adj)[v].push_back(u);
}

int main() 
{
  
  int vertices, edges;
  std::cout<<"Enter number of vertices and edges"<<std::endl;
  std::cin >> vertices >> edges;

  Graph g(vertices);

  for (int i = 0; i < edges; i++) {
    std::cout<<"Enter vertices incident to edge from 0 to n-1"<<std::endl;
    int start, end;
    std::cin >> start >> end;
    g.addEdge(start, end);
  }

  //ans1 = number_of_components(adj, v, e);
  g.DFSconnect();
  g.printAns();
}
