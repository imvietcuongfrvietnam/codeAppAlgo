
    #include<bits/stdc++.h>

    #define pii pair<int, int>


    using namespace std;

    int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n+1, vector<int>(m+1, 0));

    int inp;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>inp;
            v[i][j] = inp;
        }
    }
    vector<vector<int>> S(n + 1, vector<int>(m + 1, 0));

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            S[i][j] = S[i-1][j]+S[i][j-1]+v[i][j] - S[i-1][j-1];
        }
    }

    int query;
    cin>>query;
    int r1,c1,r2,c2;
    while(query--){
        cin>>r1>>c1>>r2>>c2;
        cout<<S[r2][c2] +S[r1-1][c1-1] - S[r1-1][c2] - S[r2][c1-1]<<endl;
    }
    }
