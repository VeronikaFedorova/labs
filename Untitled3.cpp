#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	};
    for(int i = 1; i <= n; i++){
    	cin >> b[i];
	};

    vector < vector <int> > dp(n+1, vector <int> (m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], (j >= a[i] ? dp[i-1][j-a[i]]+b[i] : 0));
        }
    }
    cout << dp[n][m];
}
