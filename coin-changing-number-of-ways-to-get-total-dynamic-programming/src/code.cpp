#include <iostream>
#include <vector>

using namespace std;

int getNumberOfWay(vector<int> coins, int sum)
{
  int cols = sum+1;
  int rows = coins.size();
  vector<vector<int> > dp(rows, vector<int>(cols, 0));
  for (int i = 0; i<rows; ++i) {
    for (int j = 0; j<cols; ++j) {
      if (i == 0) {
        dp[i][j] = (j % coins[i]) == 0 ? 1 : 0;
      }
      else {
        if (j>=coins[i]) {
          dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
        }
        else {
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }

  return dp[rows-1][cols-1];
}

int main()
{
  vector<int> coins(3);
  coins[0] = 2;
  coins[1] = 3;
  coins[2] = 4;

  std::cout << getNumberOfWay(coins, 10) << endl;
}