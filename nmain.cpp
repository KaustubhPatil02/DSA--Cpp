#include <iostream>
using namespace std;
#include <iterator> 
#include <map> 
int main()
{
string user , pass;
map<string , string> mp;
//   register :
//   ... for gettting  username and password into "user" and "pass hahahhhaaaaa"
mp[user]=pass; //keys for the purpose which has been already declared

//  login with a user and :
//  ... get username and password into "user" and "pass"
if ( (!mp.find(user)==mp.end()) || (mp[user]!=pass) ) cout<<"LOGIN FAILED"; else cout<<"LOGIN SUCCESS";

system("pause");
}