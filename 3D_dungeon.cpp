#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <queue>

int has_path(std::vector<std::vector<std::vector<char>>> &dg, int x, int y, int z);

int main()
{
 /* ?_n;||(or) e &&(and)*/

 // 3D Dungeon master problem

 std::vector<char> a = {'S', '.', '.'};
 std::vector<char> b = {'#', '#', '.'};
 std::vector<char> c = {'.', '.', '.'};
 std::vector<char> d = {'.', '#', '#'};
 std::vector<char> e = {'.', '.', 'E'};
 std::vector<std::vector<char>> grid = {a, b, c, d, e};
 std::vector<std::vector<std::vector<char>>> dg = {grid};

 std::cout << has_path(dg, 0, 0, 0) + 1;

 return 0;
}

int has_path(std::vector<std::vector<std::vector<char>>> &dg, int x, int y, int z)
{
 // # -> rock
 // . -> can go
 // S -> strt
 // E -> end

 // matrix that keeps track of the levels of the nodes visisted
 std::vector<std::vector<std::vector<int>>> lvls;
 for (int i = 0; i < dg.size(); i++)
 {
  std::vector<std::vector<int>> tmp_1;
  lvls.push_back(tmp_1);
  for (int j = 0; j < dg[0].size(); j++)
  {
   std::vector<int> tmp_2;
   lvls[0].push_back(tmp_2);
   for (int k = 0; k < dg[0][0].size(); k++)
   {
    lvls[i][j].push_back(0);
   }
  }
 }

 std::queue<char> q_x;
 std::queue<char> q_y;
 std::queue<char> q_z;
 q_x.push(x);
 q_y.push(y);
 q_z.push(z);

 int lvl = 0;

 while (!q_x.empty())
 {
  int a = q_x.front();
  int b = q_y.front();
  int c = q_z.front();
  q_x.pop();
  q_y.pop();
  q_z.pop();

  if (dg[a][b][c] == 'E')
  {
   return lvls[a][b][c];
  }

  std::vector<int> d_i = {0, 0, +1, -1, 0, 0};
  std::vector<int> d_j = {+1, -1, 0, 0, 0, 0};
  std::vector<int> d_k = {0, 0, 0, 0, +1, -1};

  for (int q = 0; q < 6; q++)
  {
   int i = a + d_i[q];
   int j = b + d_j[q];
   int k = c + d_k[q];

   if (i >= 0 && i < dg.size())
   {
    if (j >= 0 && j < dg[0].size())
    {
     if (k >= 0 && k < dg[0][0].size())
     {
      if (dg[i][j][k] != '#')
      {
       if (dg[i][j][k] == 'E')
       {
        return lvls[a][b][c];
       }
       if (dg[i][j][k] != 'E' || dg[i][j][k] != 'S')
       {
        dg[i][j][k] = '#';
       }
       lvls[i][j][k] = lvls[a][b][c] + 1;
       q_x.push(i);
       q_y.push(j);
       q_z.push(k);
      }
     }
    }
   }
  }
 }
 return -1;
}
