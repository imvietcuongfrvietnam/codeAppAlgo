#include<iostream>
#include<set>

using namespace std;

int main(){

set<string> s;
s.insert("abc");
s.insert("xyz");
s.insert("123");

set<string>::iterator p;

for(p = s.begin(); p!= s.end();p++){
cout<<*p<<" ";}
cout<<endl;

p = s.find("abc");
if(p == s.end()){
    cout<<"ko tim thay";
}
else cout<<"tim thay";

s.erase("abc"); // xoa
//upper_bound and lower_bound:
//upper bound >, lower_bound <=
set<int> int_set;
for(int i = 1;i<=5;i++) int_set.insert(i);

auto p1 = int_set.upper_bound(3);
cout<<endl<<*p1;
p1 = int_set.lower_bound(5);
cout<<endl<<*p1;
p1 = int_set.upper_bound(10);

if(p1 == int_set.end()) cout<<endl<<"not found";
}
