#include<iostream>
using namespace std;

int main()
{
    char val[5]= {'h','e','l','l','o'};

    for(int i = 0; i<5; i++)
    {
        cout<<val[i]<<endl;
    }
    char val2[6]="hello";
    for(int i = 0; i<6; i++)
    {
        cout<<val2[i];
    }

    //cout<<val2[5];
    return 0;
}
