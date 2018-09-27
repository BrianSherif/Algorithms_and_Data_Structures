#include <iostream>
#include <vector>
#include <stdlib>
#include <queue>

using namespace std;

const int INF = (1 << 30); // large number to represent infinity

// Floyd-Warshall Algorithm is a Dynamic programming algorithm used to find shortest paths between pairs of cities
// Running time is O(n^3)
int find_meetup_city(const std::vector< std::vector<int> >& adj, const int& p, const int& q)
{

  int n = adj.size();
  int dp[n][n];
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j)
      {
        dp[i][j] = 0;
      }
      else if(adj[i][j] != -1)
      {
        dp[i][j] = adj[i][j];
      }else{
        dp[i][j] = INF;
      }
    }
  }

  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int res = INF;
  int city;
  for(int i = 0; i < n; i++)
  {
    if(res > std::max(dp[p][i], dp[q][i]))
    {
      res = std::max(dp[p][i], dp[q][i]);
      city = i;
    }
  }
  return city;
}
