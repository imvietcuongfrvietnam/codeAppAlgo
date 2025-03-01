#include<bits/stdc++.h>
#include<sstream>

using namespace std;

int main(){
queue<int> Q;
string command;

while(getline(cin, command)){
    if(command == "#") break;

    stringstream ss(command);
    string op;
    ss>>op;
    if(op == "PUSH"){
            int v;
            ss>>v;
            Q.push(v);
    }
    else {
        if(Q.empty()) cout<<"NULL\n";
        else {
        cout<<Q.front()<<endl;
        Q.pop();
        }
    }
}


}
