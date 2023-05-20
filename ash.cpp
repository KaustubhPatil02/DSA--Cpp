#include<bits/stdc++.h>
using namespace std;
class A{
    float d;
    public:
    virtual void func(){
        cout<<"A";

    }
};
class B:public A{
int a=15;
public:
void func(){
    cout<<"B";

}
};
int main(int argc,char const *argv[]){
    B b;
    b.func();
}