#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x,a=1,b=1,c=1;
    cout<<"enter the power\n";
    cin>>x;
    cout<<endl<<setprecision(7);
    for (int i=2 ; i<102 ; i++)
    {
        a+=(x*b)/c;
        b*=x;
        c*=i;
        cout << setw(10) << a << " " ;
        if ( !( (i-1)%10 ) && i!=2 )
            cout << endl;
    }
    cout << endl << endl << "e^" << x << " = " << a ;
    cout << endl << endl << "e^" << x << " = " << exp(x) ;
}
