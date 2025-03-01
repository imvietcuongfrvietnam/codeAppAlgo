#include<bits/stdc++.h>

using namespace std;

int main(){

int n, M;
cin>>n>>M;
set<int> S;
int inp;
for(int i = 0;i<n;i++) {
    cin>>inp;
    S.insert(inp);
}
int cnt = 0;
for(set<int>::iterator p = S.begin(); p!= S.end();p++){
    if(S.find(M - *p) != S.end()) cnt++;
}
cout<<cnt/2;
}
