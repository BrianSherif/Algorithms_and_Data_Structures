//found on https://github.com/laituan245/spoj-solution/blob/master/classical/SCUBADIV.cpp

#include<bits/stdc++.h>
using namespace std;

const int INF_WEIGHT = 100000000;
int min (int a, int b);
int max (int a, int b);

int main () {
  int tc;//test cases
  int oRequired;
  int nRequired;
  int Ox[1000]; //oxygen
  int Ni[1000];
  int weight[1000];
  int dp[1000][22][80];//Tabulation
  int NCylinders;//number of cylinders
  cin >> tc;
  //Reading values
  for (int z = 0; z < tc; z++) {
    cin >> oRequired >> nRequired >> NCylinders;
    for (int i = 0; i < NCylinders; i++)
      cin >> Ox[i] >> Ni[i] >> weight[i];

    // Dynamic Programming
    for (int i = 0; i < NCylinders; i++)
      for (int j = 0; j <= oRequired; j++)
        for (int k = 0; k <= nRequired; k++) {
          dp[i][j][k] = INF_WEIGHT;//initialization to a value
          if (j == 0 && k == 0)
            dp[i][j][k] = 0;
        }
	//initialization of the weight
    for (int j = 0; j <= oRequired; j++)
      for (int k = 0; k <= nRequired; k++)
        if (j <= Ox[0] && k <= Ni[0] && (j > 0 || k > 0)) {
          dp[0][j][k] = weight[0];
        }

	//The Algorithm
    for (int i = 1; i < NCylinders; i++)
      for (int j = 0; j <= oRequired; j++)
        for (int k = 0; k <= nRequired; k++) {
          dp[i][j][k] = dp[i-1][j][k];
          if (j <= Ox[i] && k <= Ni[i])
            dp[i][j][k] = min(dp[i][j][k], weight[i]);
          else
            dp[i][j][k] = min(dp[i][j][k], weight[i] + dp[i-1][max(0,j-Ox[i])][max(0,k-Ni[i])]);
        }

    cout << dp[NCylinders-1][oRequired][nRequired] << "\n";
  }
}

//comparing functions
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
