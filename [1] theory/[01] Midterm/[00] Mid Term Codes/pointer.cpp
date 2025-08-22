#include<iostream>
using namespace std;

int main()
{
    int n= 10;
    void *ptr = &n;

    //cout<<*(int*)ptr;

    int *ptr2 = new int;

    *ptr2 = n;

    cout << *ptr2;

    delete ptr2;

}
