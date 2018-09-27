#include <bits/stdc++.h>

using namespace std;

class PuzzleBoard{
private:
  vector< set<int> > edges;
  vector< vector<int> > fields;
  int numOfNodes;
  int boardSize;
  int currX, currY;
  int getNode(const int& x, const int& y)
  {
    return (x*boardSize + y);
  }

  bool outOfBounds(const int& x, const int& y)
  {
    return (x < 0 || x >= boardSize || y < 0 || y >= boardSize);
  }

public:
  PuzzleBoard(int boardSize, int **fields = NULL){
    if(fields == NULL)
    {
      srand(time(NULL));
      fields = new int*[boardSize];
      for(int i = 0; i < boardSize; i++)
      {
        fields[i] = new int[boardSize];
        for(int j = 0; j < boardSize; j++)
        {
          fields[i][j] = rand()%boardSize + 1;
        }
      }
    }
    this->boardSize = boardSize;
    numOfNodes = boardSize*boardSize;
    edges.resize(numOfNodes, set<int>());
    for(int i = 0; i < boardSize; i++)
    {
      for(int j = 0; j < boardSize; j++)
      {
        int currNode = getNode(i, j);
        int nextNode;
        if(!outOfBounds(i + fields[i][j], j))
        {
          nextNode = getNode(i + fields[i][j], j);
          edges[currNode].insert(nextNode);
        }
        if(!outOfBounds(i - fields[i][j], j))
        {
          nextNode = getNode(i - fields[i][j], j);
          edges[currNode].insert(nextNode);
        }
        if(!outOfBounds(i, j + fields[i][j]))
        {
          nextNode = getNode(i, j + fields[i][j]);
          edges[currNode].insert(nextNode);
        }
        if(!outOfBounds(i, j - fields[i][j]))
        {
          nextNode = getNode(i, j - fields[i][j]);
          edges[currNode].insert(nextNode);
        }
      }
    }
    for(int i = 0; i < boardSize; i++)
    {
      for(int j = 0; j < boardSize; j++)
      {
        this->fields[i][j] = fields[i][j];
      }
    }
    currX = currY = 0;
  }

  bool makeMove(int direction){
    int nx;
    int ny;
    int curr;
    int next;
    set<int>::iterator it;
    switch(direction){
      case 0:
      nx = currX - fields[currX][currY];
      ny = currY;
      if(outOfBounds(nx, ny))
      {
        return false;
      }
      curr = getNode(currX, currY);
      next = getNode(nx, ny);
      it = edges[curr].find(next);
      if(it == edges[curr].end())
      {
        return false;
      }
      currX = nx;
      currY = ny;
      break;


      case 1:
      nx = currX;
      ny = currY + fields[currX][currY];
      if(outOfBounds(nx, ny))
      {
        return false;
      }
      curr = getNode(currX, currY);
      next = getNode(nx, ny);
      it = edges[curr].find(next);
      if(it == edges[curr].end())
      {
        return false;
      }
      currX = nx;
      currY = ny;
      break;


      case 2:
      nx = currX + fields[currX][currY];
      ny = currY;
      if(outOfBounds(nx, ny))
      {
        return false;
      }
      curr = getNode(currX, currY);
      next = getNode(nx, ny);
      it = edges[curr].find(next);
      if(it == edges[curr].end())
      {
        return false;
      }
      currX = nx;
      currY = ny;
      break;


      case 3:
      nx = currX;
      ny = currY - fields[currX][currY];
      if(outOfBounds(nx, ny))
      {
        return false;
      }
      curr = getNode(currX, currY);
      next = getNode(nx, ny);
      it = edges[curr].find(next);
      if(it == edges[curr].end())
      {
        return false;
      }
      currX = nx;
      currY = ny;
      break;
    }


    return true;
  }


  bool getResult(){
    return (currX == boardSize-1 && currY == boardSize-1);
  }


  friend ostream& operator<<(ostream &os, const PuzzleBoard& m);


  int solve(){
    int d[numOfNodes];
    memset(d, -1, sizeof(d));
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while(!q.empty())
    {
      int curr = q.front();
      q.pop();
      for(auto next : edges[curr])
      {
        if(d[next] == -1)
        {
          d[next] = d[curr] + 1;
          q.push(next);
        }
      }
    }

    if(d[numOfNodes-1] == -1)
    {
      cout << "No solution\n";
    }
    return (d[numOfNodes]);
  }
};
