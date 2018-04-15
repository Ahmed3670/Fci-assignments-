#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int hours,depend;
        cout<<endl<<endl<<"enter the hours\n";
        cin>>hours;
        cout<<"enter the number of depends\n";
        cin>>depend;
        if (depend>=3)
            depend=35;
        else
            depend=0;
        if(hours<=40)
        {
            cout<<"gross pay : "<<(hours*16.78)*.75-10-depend<<endl;
        }
        else
        {
            cout<<"gross pay : "<<((hours-40)*16.78*1.5+40*16.78)*.75-10-depend<<endl;
        }


    }

}
