#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main(){
stack<int> s;

string command;
while(getline(cin, command)){
if(command == "#") break;
stringstream ss(command);
string op;
ss>>op;
if(op == "PUSH"){
int v;
ss>>v;
s.push(v);
}

else{
if(s.empty()) cout<<"NULL\n";
else{
cout<<s.top();
s.pop();}
}

}
}
