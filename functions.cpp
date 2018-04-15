#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <valarray>
#include <fstream>


using namespace std;

int main()
{
    while (true)
    {
    fstream file;
    char x[99],fName[20];
    valarray <float> arr(99);
    valarray <float> arr1(99);
    double sumX=0,sumY=0,sumXY=0,sumXX=0,sumYY=0,r1,r2,r;
    int nLine;
    string mode;
    cout <<"enter file name\n";
    cin>>fName;
    strcat(fName,".txt");
    cout<<"1-entre a new data set\n";
    cout<<"2-display data and Calculate the Correlation Coefficient \n";
    cin >>mode ;
      while(mode!="1" &&mode!="2" &&mode!="3")
    {
        cout<<"invalid\n";
        cout<<"1-entre (1) for a new data set\n";
        cout<<"2-enter (2) to display data and Calculate the Correlation Coefficient \n";
        cin>>mode;
    }
     if (mode=="1")
    {
        cout<<"enter the number of elements\n";

        cin >> nLine ;
        cout<<"enter the elements\n";

        file.open(fName,ios::out);



        for (int i=0 ; i<nLine*2 ; i++)
        {
            if (i%2==0)
                cin >> arr[i];
            else
                cin >> arr1[i-1];
        }

        for (int i=0 ; i<nLine*2 ; i++)
        {
            if (i%2==0)
                file <<arr[i]<<" ";
            else
                file <<arr1[i-1]<< endl;
        }
        file.close();
    }

    else if (mode=="2") {
        file.open(fName,ios::in);

        for (int i=0 ; !file.eof() ; i++)
        {
                file >> arr[i];
                file >> arr1[i];
                nLine=i+1;
        }


        for (int i=0 ; arr[i]!='\0' ; i++) {

                cout << "(" << arr[i] << "," << arr1[i] << ")" << endl;


        }



            for (int i=0 ; i<nLine ; i++) {
                sumXY+=(arr[i]*arr1[i]);
            }


            for (int i=0 ; i<nLine ; i++) {
                sumXX+=(arr[i]*arr[i]);
            }



            for (int i=0 ; i<nLine ; i++) {
                sumYY+=(arr1[i]*arr1[i]);
            }



            sumX=arr.sum();
            sumY=arr1.sum();


            r1=( nLine * sumXY - sumX * sumY );
            r2=(nLine*sumXX-pow(sumX,2)) * (nLine*sumYY-pow(sumY,2));
            r=r1/sqrt(r2);
            cout << "The Correlation Coefficient = " << r << endl;
        }
        }
    }

