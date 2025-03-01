#include<list>
#include<iostream>

using namespace std;
void printList(auto L){
for(auto i = L.begin(); i!= L.end();i++) cout<<*i<<" ";
cout<<endl;
}

int main(){
list<int> L;
for(int i = 1;i<=5;i++) L.push_back(i);
printList(L);
for(int j = 6;j<=10;j++) L.push_front(j);
printList(L);

list<int> L1(3, 0);
printList(L1);
list<int> L2 = {1,2,3,4};
printList(L2);

auto p = L.begin();
advance(p, 2);

L.insert(p, 99);
printList(L);

L.erase(p);
printList(L);
advance(p, -1);
L.erase(p);
printList(L);
L.insert(p, 2, 66);
printList(L);
}
