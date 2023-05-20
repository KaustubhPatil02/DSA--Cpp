#include<iostream>
using namespace std;

int main()
{
    int a;
    char b;
    float c;
    bool d;
    short int i;
    long int l;
    unsigned int u;
    signed int s;;

    cout<<"Dataypes in Bytes:"<<endl;

    cout<<"Size of int:\n"<<sizeof(int)<<endl;
    cout<<"Size of char:\n"<<sizeof(char)<<endl;
    cout<<"Size of float:\n"<<sizeof(float)<<endl;
    cout<<"Size of bool:\n"<<sizeof(bool)<<endl;
    cout<<"Size of short int:\n"<<sizeof(i)<<endl;
    cout<<"Size of long int:\n"<<sizeof(l)<<endl;
    cout<<"Size of unsigned long int:\n"<<sizeof(u)<<endl;
    cout<<"Size of signed long int:\n"<<sizeof(s)<<endl;



    return 0;
}