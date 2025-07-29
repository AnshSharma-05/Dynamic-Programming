#include<bits/stdc++.h>
using namespace std;

int main(){
    int d = 3;
    int a = 3;
    int arr[d][a];

    for(int i = 0; i < d; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int> > dp( d , vector<int> (a , 0));
    int totalPoints = 0;
    
    for(int i = 0; i < a; i++){
        dp[0][i] = arr[0][i];
    }

    for(int i = 1; i < d; i++){
        for(int j = 0; j < a ; j++){

            if(j == 0) dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1] , dp[i - 1][j + 2]);
            if(j == 1) dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1] , dp[i - 1][j + 1]);
            if(j == 2) dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1] , dp[i - 1][j - 2]);
        }
    }

    int ans = 0;
    for(int i = 0; i < a; i++){
        ans = max(ans , dp[d - 1][i]);
    }

    cout << ans << endl;

    return 0;
}