#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//for copy
#include <iterator>//for ostream_iterator

 
using std::queue;
using std::vector;
using std::pair;

//using namespace std;


void displayAdjList(vector<vector<int> > &adj)
{
  for(unsigned int i=0; i<adj.size(); ++i)
  {
    for(unsigned int j=0; j<adj[i].size(); j++)
    {
      std::cout<< adj[i][j]<< " ";
    }

    std::cout << std::endl;
  }
}

void add_edge(vector<vector<int> > &adj, int start, int end)
{  
  adj[start].push_back(end);
  adj[end].push_back(start);
}

/*input: 2D vector pointer adj with edges, start and end vertices*/
int reach(vector<vector<int> > &adj, int start, int fin) 
{
  //write your code here
  //vector for keeping track of visited vertices
  vector<int> vis;
  for(int m = 0; m<=fin; ++m)
  {
    vis.push_back(0);
  }
  //mark all vertices adjacent to start
  for(unsigned int k = 0; k< adj[start].size(); ++k)
  {
    vis[adj[start][k]]=1;
  }
  //iterate vis and if vis(adj to start), iterate adj vec to mark
  //vis v's as visited
  for(unsigned int i=0; i< vis.size(); ++i)
  {
    if(vis[i])//only enter nested loop for the verices adj to start
    {
      for(unsigned int j=0;j<adj[i].size(); ++j)//iterate all adj v's 
      {
        if(!vis[adj[i][j]])
        {
          vis[adj[i][j]]=1;
        }
      }
    }
    if(vis[fin])//if fin is one of the visited vertices
    {
      return 1;
    }
  }

  return 0;
}

int main() 
{
  int v, e;
  std::cout << "Enter num vertices and edges\n";
  std::cin >> v >> e;
  //2D vector of size n, with vector in each element
  //adjacency vector, with size and initial value adj(v, vector<int>());
  //for adj matrix:  vector<vector<int> > adj(v, vector<int>(v, 0));
  vector<vector<int> > adj(v, vector<int>());
  
  std::cout<<"initialized 2d vector of size "<< v<< " by vector<int>"<<std::endl;
  
  for (int i = 0; i < e; i++) 
  {
    int start, end;
    std::cout<<"Enter edges, vertices that edge is incident to from 0 to n-1\n";
    std::cin >> start >> end;
    //u--; v--;  //minus to start at 0,0
    add_edge(adj, start, end);
  }
  //check adj's elements
  std::cout<<"print adj elements"<<std::endl;
  std::cout<<"adj.size "<<adj.size()<<std::endl;
  std::cout<<"adj[0].size "<<adj[0].size()<<std::endl;
  for(unsigned int p=0; p<adj.size(); p++)
  {
    std::cout<<"sizes " <<adj[p].size()<<" ";
  }
  std::cout<<std::endl;
  //show contents
  displayAdjList(adj);
  int x, y;  //x, y for start and end
  std::cout<<"Enter start and end vertices from 0 to "<< v-1 << std::endl;
  std::cin >> x >> y;
  //x--; y--;
  
  /*reach called with adj and start and end vertices
  returns 1 if there is a route, 0 if not */
  int answer =0;
  answer = reach(adj, x, y);
  std::cout << "\n"<< "The answer is: " << answer <<std::endl;
}
