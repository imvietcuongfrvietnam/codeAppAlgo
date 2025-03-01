#include<bits/stdc++.h>

using namespace std;

int main(){

int n;
cin>>n;
vector<int> v;
int inp;

for(int i = 0;i<n;i++){
    cin>>inp;
    v.push_back(inp);
}
vector<long long> S;
S.push_back(0);
long long current_sum = 0;
for(int i = 1;i<=n;i++){
        current_sum += v[i-1];
    S.push_back(current_sum);
}
int q;
cin>>q;
int i, j;
while(q--){
    cin>>i>>j;
    cout<<S[j] - S[i-1]<<endl;
}

}
