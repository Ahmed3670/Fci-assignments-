#include <iostream>
#include <fstream>
#include <valarray>
#include <cmath>
#include <cstring>
#include <iomanip>

float Q1(float );
float Q2(float );
float Q3(float );
float iqr(float ,float );

using namespace std;

int main()
{
    while (true)
    {
    fstream file;
    char x[99],fName[20];
    int nLine=0,IQR;
    int nElement;
    float q1,q2,q3;
    cout<<"enter file name\n";
    cin>>fName;
    strcat(fName,".txt");
    valarray <float> arr(99);
    string mode;
    cout<<"1-entre a new data set\n";
    cout<<"2-load data set\n";
    cout<<"3-display data\n";
    cout<<"4-for quartiles data set and interquartile range\n";
    cin >> mode ;
    cout<<endl<<endl;
    while(mode!="1" &&mode!="2" &&mode!="3" &&mode!="4")
    {
        cout<<"invalid\n";
        cout<<"1-entre (1) for a new data set\n2";
        cout<<"2-enter (2) to load data set\n";
        cout<<"3-enter (3) to display data\n";
        cout<<"4-enter (4) for quartiles data set and  the Interquartile range\n";
        cin>>mode;
    }
    if (mode=="1")
    {
        cout<<"enter the number of elements\n";

        cin >> nLine ;
        cout<<"enter the elements\n";

        file.open(fName,ios::out);
        for (int i=0 ; i<nLine ; i++)
        {
            cin >> arr[i];
        }

        for (int i=0 ; i<nLine ; i++)
        {
            file << arr[i] << endl;
        }
        file.close();
    }
    else if (mode=="2") {
        file.open(fName,ios::in);
        for (int i=0 ; !file.eof() ; i++) {
            file >> arr[i];
        }
        file.close();
    }

    else if (mode=="3") {
        file.open(fName,ios::in);
        for (int i=0 ; !file.eof() ; i++) {
            file >> arr[i];
        }
        for (int i=0 ; arr[i]!='\0' ; i++) {
            cout << arr[i]<<"                                            " <<i+1<<endl;


        }

        file.close();
    }
     else if (mode=="4") {
        file.open(fName,ios::in);
        for (int i=0 ; !file.eof() ; i++) {
            for (int i=0 ; i<nLine ; i++)
            {
                for (int j=0;j<nLine-1;j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        int swap=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=swap;
                    }
                }
            }
            file >> arr[i];
            nLine+=1;
        }
         file.close();
        for (int i=0 ; arr[i]!='\0' ; i++) {
            cout << setw(5) << arr[i] << setw(40) << i+1 << endl;
        }
        cout<<"the num of elements in the data set = ";
        cout << --nLine << endl;
        if (nLine%2!=0){
            q2=arr[Q2(nLine)];
            cout<<"median= " << q2 << endl;

        }
        else {
            q2=Q2(nLine);
            q2=(arr[q2-1]+arr[q2])/2;
            cout<<"median= " << q2 << endl;



        }
          if ((nLine/2)%2!=0){
            q1=arr[Q1(nLine)];
            cout<<"Q1= " << q1 << endl;

        }
        else {
            q1=Q1(nLine);
            q1=(arr[q1-1]+arr[q1])/2;
            cout<<"Q1= " << q1 << endl;
        }
          if ((nLine/2)%2!=0){
            q3=arr[Q3(nLine)];
            cout<<"Q3= " << q3 << endl;

        }
        else {
            q3=Q3(nLine);
            q3=(arr[q3-1]+arr[q3])/2;
            cout<<"Q3= " << q3 << endl;
        }
        cout<<"the Interquartile range =";
        cout<<iqr(q3,q1)<<endl;
    }
}
    return 0;
}


float Q2(float x){
    float Q2;
    Q2=(x)/2;
    return Q2;
}
float Q1(float x){
    float Q1;
    Q1=(x)/4;
    return Q1;
}
float Q3(float x){
    float Q3;
    Q3=(x*3)/4;
    return Q3;
}
float iqr(float x,float y){
    float iqr=x-y;
    return iqr;
}

