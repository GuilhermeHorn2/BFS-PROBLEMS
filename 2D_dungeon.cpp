#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

int has_path(std::vector<std::vector<int>> grid);

int main()
{
 /* ?_n;||(or) e &&(and)*/

 // 2D Dungeon master problem
 std::vector<int> a = {0, 0, 0};
 std::vector<int> b = {1, 1, 0};
 std::vector<int> c = {0, 0, 0};
 std::vector<int> d = {0, 1, 1};
 std::vector<int> e = {0, 0, 0};
 std::vector<std::vector<int>> grid = {a, b, c, d, e};

 std::cout << has_path(grid);

 return 0;
}

int has_path(std::vector<std::vector<int>> grid)
{
 // grid[i][j] == 0 --> can go
 // grid[i][j] == 1 --> cannot go
 // grid[i][j] == 2 --> goal

 grid[0][0] = 1;

 grid[grid.size() - 1][grid[0].size() - 1] = 2;
 std::queue<int> q_i;
 std::queue<int> q_j;

 q_i.push(0);
 q_j.push(0);

 while (!q_i.empty())
 {
  int a = q_i.front();
  int b = q_j.front();
  q_i.pop();
  q_j.pop();
  if (grid[a][b] == 2)
  {
   return 1;
  }
  else
  {
   // grid[a][b] = 1;
   //  if the node is not marked/not a rock can go and search for adjs
   std::vector<int> di = {0, 0, +1, -1};
   std::vector<int> dj = {-1, +1, 0, 0};
   for (int k = 0; k < 4; k++)
   {
    int i = a + di[k];
    int j = b + dj[k];
    if (i >= 0 && i < grid.size())
    {
     if (j >= 0 && j < grid[0].size())
     {
      if (grid[i][j] == 2)
      {
       return 1;
      }
      if (!grid[i][j])
      {
       grid[i][j] = 1;
       q_i.push(i);
       q_j.push(j);
      }
     }
    }
   }
  }
 }
 return 0;
}
