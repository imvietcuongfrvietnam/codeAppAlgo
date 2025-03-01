//C++

#include <bits/stdc++.h>
#include<sstream>
using namespace std;

int main()
{
queue <string> q;
string s;
cin>>s;
stringstream ss(s);
vector <string> words;
string word;
while(ss<<word){
    words.push_back(word);
}
while(words[0] != "#"){
    if(words[0] == "PUSH"){
        q.push(words[1]);
        words.erase(words.begin(), words.end());
    }
    else{
        if(q.empty()){
            cout<<"NULL\n";
        }
        else{
            cout<<q.front()<<endl;
            q.pop();
        }
    }
    cin>>s;
    ss(s);
    while(ss<<word){
    words.push_back(word);
}
}
}
