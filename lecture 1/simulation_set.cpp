#include<set>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){

set<long> s;
int n;
cin>>n;
long x;
for(int i = 1;i<=n;i++){
        cin>>x;
    s.insert(x);
}
set<long>::iterator p;
string command;
getline(cin, command);
while(getline(cin, command)){
    if(command == "#") break;
    stringstream ss(command);
    string op;
    ss>>op;
    ss>>x;
    if(op == "min_greater_equal"){
        p = s.lower_bound(x);
    }
    else if(op == "min_greater"){
        if(s.find(x) == s.end()) {p = s.lower_bound(x);}
        else {s.erase(s.find(x));
        p = s.lower_bound(x);
        s.insert(x);
    }}
    else if (op == "insert"){
        s.insert(x);
        continue;
    }
    else if(op == "remove"){
            p = s.find(x);
    if(p!=s.end())
        s.erase(p);
        continue;
    }

    if(p!=s.end()){
        cout<<*p<<endl;
        continue;
    }
    cout<<"NULL"<<endl;
}

}
