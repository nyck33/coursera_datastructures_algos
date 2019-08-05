#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::queue;
using std::vector;
using std::pair;



void add_edge(vector<vector<int> > &adj, int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void explore(int vertex, vector<vector<int> > &adj, vector<bool> vis, vector<int> ccnum, int cnum)
{
  //std::cout<< "vertex "<<vertex<<std::endl;
  vis[vertex]=true;
  ccnum[vertex]=cnum;
  std::cout<< vertex<<" ";
  for(unsigned int i=0; i< adj[vertex].size(); i++)
  {
    if(!vis[adj[vertex][i]])
    {
      //std::cout<< "adj[vertex][i] "<<adj[vertex][i]<<std::endl;
      explore(adj[vertex][i], adj, vis, ccnum, cnum);
    }    
  }
}

void DFS(vector<vector<int> > &adj, int v, int e, vector<bool> vis, vector<int> ccnum, int cnum)
{
  for(int i=0; i<v; i++)
  {
    if(vis[i]==false)
    {
      explore(i, adj, vis, ccnum, cnum);
      std::cout<<"\n";
      cnum= cnum+1;
      std::cout<< "cnum: "<<cnum<<std::endl;
    }
  }
}

int main() 
{
  
  int v, e;
  std::cout<<"Enter number of vertices and edges"<<std::endl;
  std::cin >> v >> e;
  vector<vector<int> > adj(v, vector<int>());
  for (int i = 0; i < e; i++) {
    std::cout<<"Enter vertices incident to edge from 0 to n-1"<<std::endl;
    int x, y;
    std::cin >> x >> y;
    add_edge(adj, x, y);
  }
  //int ans2;

  vector<bool>  vis(v, false);
  vector<int> ccnum(v,0);
  int cnum =1;
  
  //ans1 = number_of_components(adj, v, e);
  DFS(adj, v, e, vis, ccnum, cnum);
  
  //std::cout<<"number of components ans1 "<<ans1<<std::endl;
  std::cout<<"Num components is "<<cnum<<std::endl;
}


/* 
int number_of_components(vector<vector<int> > &adj, int v, int e) 
{
  int num = 0;
  vector<vector<int> > comp(v, vector<int>());//
  vector<int> curr; //keep track of current component

  for(int i =0; i<v;i++)
  {
    for(unsigned int j=0; j<adj[i].size(); j++)
    {//if adj[i][j] not in comp[i] comp[adj[i][j]]
      if(std::find(comp[adj[i][j]].begin(), comp[adj[i][j]].end(), 
        adj[i][j])!=comp[adj[i][j]].end())
      {
        comp[i].push_back(adj[i][j]);
        curr.push_back(adj[i][j]);//keep track
        if(comp[i][j]!= i)
        {
          for(int k=0; k< v; k++)
          {
            if(k == comp[i][j])
            {
              for(unsigned int m=0;m < adj[k].size(); m++)
              {
                //if adj[k][m] not in comp[i]
                if(std::find(comp[i].begin(), comp[i].end(), 
                  adj[k][m])!=comp[i].end())
                {
                  comp[i].push_back(adj[k][m]);
                  curr.push_back(adj[k][m]); //keep track
                }
                for(unsigned int n=0; n<curr.size();n++)
                {
                  //once curr has all vertices of comp
                  if(std::find(curr.begin(), curr.end(), comp[i][n]) != curr.end())
                  {
                    continue; //go back to j loop
                  }
                  else
                  {
                    num++;//increment num components
                    //clear curr
                    curr.clear();

                  }
                }
              }
            }
          }
        }
      }
    }  
  }  
  return num;
}
*/