#include <bits/stdc++.h>
using namespace std;

void depthFirstSearch(const int& curr, bool vis[], stack<int>& s, const vector< vector<bool> >& adj){
  vis[curr] = true;
  for(unsigned int i = 0; i < adj[curr].size(); i++)
  {
    if(adj[curr][i] && !vis[i])
    {
      depthFirstSearch(i, vis, s, adj);
    }
  }
  s.push(curr);
}

vector<int> picking_order(const vector< vector<bool> >& adj){
  stack<int> s;
  int n = adj.size();
  bool vis[n];
  memset(vis, false, sizeof(vis));
  for(int i = 0; i < n; i++)
  {
    if(!vis[i])
    {
      depthFirstSearch(i, vis, s, adj);
    }
  }

  vector<int> res;
  while(!s.empty())
  {
    res.push_back(s.top());
    s.pop();
  }
  return res;
}

int main(){
  int n;
  vector< vector<bool> > adj(n, vector<bool>(n, false));
  for(int i = 0; i < n; i++)
  {
    int to;
    cin >> to;
    adj[i][to] = true;
  }

  vector<int> res = picking_order(adj);
  for(auto el : res){
    cout << el << " ";
  }
  cout << endl;
  return 0;
}
