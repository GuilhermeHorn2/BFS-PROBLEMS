#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

void bfs_adj(std::vector<std::vector<int>> &graph);

int main()
{
 /* ?_n;||(or) e &&(and)*/

 // fazer BFS para adj matrix

 std::vector<int> a = {0, 1, 0, 0};
 std::vector<int> b = {0, 0, 1, 0};
 std::vector<int> c = {1, 0, 0, 0};
 std::vector<int> d = {0, 0, 1, 0};

 std::vector<std::vector<int>> graph = {a, b, c, d};

 bfs_adj(graph);

 return 0;
}

void bfs_adj(std::vector<std::vector<int>> &graph)
{
 // build matrix that tracks the nodes that were visited
 std::vector<int> tmp;
 for (int i = 0; i < graph.size(); i++)
 {
  tmp.push_back(0);
 }
 std::queue<int> q;
 tmp[0] = 1; // mark strt
 q.push(0);

 while (!q.empty())
 {
  int r = q.front();
  q.pop();
  // visit
  std::cout << r << (char)10;
  //
  for (int i = 0; i < graph[r].size(); i++)
  {
   if (graph[r][i]) // get adj nodes
   {
    if (!tmp[i]) // if this node is not marked
    {
     tmp[i] = 1; // mark the node
     q.push(i);
    }
   }
  }
 }
}
