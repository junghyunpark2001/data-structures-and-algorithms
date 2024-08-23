#include <iostream>
#include <vector>
using namespace std;


int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // dp 테이블 채우기
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // 배낭의 용량
    vector<int> weights = {10, 20, 30}; // 각 아이템의 무게
    vector<int> values = {60, 100, 120}; // 각 아이템의 가치
    int n = weights.size(); // 아이템의 수

    cout << "최대 가치: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
