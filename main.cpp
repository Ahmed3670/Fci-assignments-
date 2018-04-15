#include <iostream>
#include <string>

using namespace std;

int main()
{
    int shift;
    string plain;
    string mode;
    cout << "what do you want to do ?\n1- Cipher\n2- Decipher" << endl;
    cin >> mode;
    while (mode!="1" && mode!="2") {
        cout << "invalid" <<endl;
        cin >> mode ;
    }
    cout<<"enter the text\n";
    cin.get();
    getline(cin,plain);
    cout<<endl;
    int w=plain.size();
    cout << "Enter shift" << endl;
    cin>>shift;
    for (int i=0 ; i<w ; i++) {
        if (plain[i]>64 && plain[i]<91 ) {
            plain[i]=(char)(plain[i]+32);
        }
    }
    string x="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    if (mode=="1") {
    for (int i=0;i<w;i++)
    {
        if (plain[i]==' ') {
            cout << ' ';
        }
        for(int j=0;j<26;j++)
        {
            if (plain[i]==x[j]) {
                cout << x[j+shift];
            }
        }
    }

    }

    if (mode=="2") {
    for (int i=0;i<w;i++)
    {
        if (plain[i]==' ') {
            cout << ' ';
        }
        for(int j=26;j<52;j++)
        {
            if (plain[i]==x[j]) {
                cout << x[j-shift];
            }
        }
    }
    }




    return 0;
}


