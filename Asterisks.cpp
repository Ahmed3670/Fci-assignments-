#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "enter the number of stars"<<endl;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        for  (int j=x-i;j<=x;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}
