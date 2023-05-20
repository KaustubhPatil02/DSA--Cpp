#include<iostream>
using namespace std;

int main(){
    cout<<"Input and output operations \n";
    cin.ignore();
    int a;
    cout<<"Enter the value of a:"<<endl;
    cin>> a;
    cout<<"Value of a: "<<a<<endl;

    int b;
    cout<<"Enter the value of b:"<<endl;
    cin>>b;
    cout<<"Value of b: "<<b<<endl;

    int sum;
    sum=a+b;
    cout<<"Total:"<<sum<<endl;
}