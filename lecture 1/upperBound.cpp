#include<set>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){

set<long> s;
int n;
cin>>n; cin.ignore();
long x;
for(int i = 1;i<=n;i++){
        cin>>x;
    s.insert(x);
}
set<long>::iterator p = s.end();
string command;
getline(cin, command);
while(getline(cin, command)){
    if(command == "#") break;
    stringstream ss(command);
    string op;
    ss>>op;
    ss>>x;
    p = s.upper_bound(x);
    if(p!=s.end()){
        cout<<*p<<endl;
        continue;
    }
    cout<<"-1"<<endl;
}
}
