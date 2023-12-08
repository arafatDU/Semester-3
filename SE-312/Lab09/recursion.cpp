#include<bits/stdc++.h>
using namespace std;
// P → ε
// P → 0
// P → 1
// P → 0P0
// P → 1P1

string w, derivation;

void CTG(string s, string derivation)
{
    if (s.empty()) {
        //cout << derivation << endl;
        return;
    } 
    else 
    {
        if (s[0] == '0') 
        {
            if(s.length() == 1)
            {
                cout<<"P => 0"<<endl;
                return;
            }
            else if(s[s.length() - 1] == '1')
            {
                cout<<"Not in this Grammar."<<endl;
                return;
            }

            else if (s.length() >= 2 && s[s.length() - 1] == '0') 
            {
                derivation = "0P0";
                cout<<"P => "<<derivation<<endl;
                CTG(s.substr(1, s.length() - 2), derivation);
            }
        }
        else if (s[0] == '1') 
        {
            if(s.length() == 1)
            {
                cout<<"P => 1"<<endl;
                return;
            }
            else if(s[s.length() - 1] == '0')
            {
                cout<<"Not in this Grammar."<<endl;
                return;
            }
            
            else if (s.length() >= 2 && s[s.length() - 1] == '1') 
            {
                derivation = "1P1";
                cout<<"P => "<<derivation<<endl;
                //cout<<endl<<s.substr(1, s.length() - 2)<<endl;
                CTG(s.substr(1, s.length() - 2), derivation);
            }
        }
    }
}

int main()
{
    w = "101";
    w = "10101";
    w = "101010";

    //cout<<w[0]<<"  "<<w[w.length() -1];
    //derivation = "P ";
    //cout<<derivation;

    CTG(w, derivation);
    //P => 1P1 => 101


    cout<<endl;

}