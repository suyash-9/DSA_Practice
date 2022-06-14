
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int minCost(int cost[R][C], int m, int n){
	int dp[R][C];
	dp[0][0]=cost[0][0];
	for(int j=1;j<C;j++){
		dp[0][j]=dp[0][j-1]+cost[0][j];
	}
	for(int j=1;j<C;j++){
		dp[j][0]=dp[j-1][0]+cost[j][0];
	}
	for(int i=1;i<R;i++){
		for(int j=1;j<C;j++){
			dp[i][j]=cost[i][j]+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
		}
	}
	return dp[m][n];
}

int main()
{
	int cost[R][C] = { { 1, 2, 3 },
					{ 4, 8, 2 },
					{ 1, 5, 3 } };
						
	cout << minCost(cost, 2, 2) << endl;
	
	return 0;
}


