#include<bits/stdc++.h>
using namespace std;
// P → ε
// P → 0
// P → 1
// P → 0P0
// P → 1P1

string w, derivation;

string replace(string s, char c1, string s2)
{
    string sub1, sub2;
    int l = s.length(), i;
    for ( i = 0; i < l; i++)
    {
        // check for c1 and replace
        if (s[i] == c1) break;
        sub1 += s[i];
    }
    for( i = i+1; i<l; i++)
    {
        sub2 += s[i];
    }
    s = sub1 + s2 + sub2;
    return s;
}

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
                derivation = replace(derivation, 'P', "0");
                cout<<" => "<<derivation;
                return;
            }
            else if(s[s.length() - 1] == '1')
            {
                cout<<"Not in this Grammar."<<endl;
                return;
            }

            else if (s.length() >= 2 && s[s.length() - 1] == '0') 
            {
                derivation = replace(derivation, 'P', "0P0");
                derivation = "0P0";
                cout<<" => "<<derivation;
                CTG(s.substr(1, s.length() - 2), derivation);
            }
        }
        else if (s[0] == '1') 
        {
            if(s.length() == 1)
            {
                derivation = replace(derivation, 'P', "1");
                cout<<" => "<<derivation;
                return;
            }
            else if(s[s.length() - 1] == '0')
            {
                cout<<"Not in this Grammar."<<endl;
                return;
            }
            
            else if (s.length() >= 2 && s[s.length() - 1] == '1') 
            {
                derivation = replace(derivation, 'P', "1P1");
                //derivation = "1P1";
                cout<<" => "<<derivation;
                //cout<<endl<<s.substr(1, s.length() - 2)<<endl;
                CTG(s.substr(1, s.length() - 2), derivation);
            }
        }
    }
}

int main()
{
    // w = "101";
    // w = "10101";
    // w = "101010";

    cout<<"Enter the input: ";
    cin>>w;

/*       This is a test of Replace function
    string test = "P";
    test = replace(test, 'P', "1P1");
    test = replace(test, 'P', "0P0");
    cout<<test<<endl;
*/

    derivation = "P";
    cout<<derivation;
    CTG(w, derivation);
    cout<<endl;
    //P => 1P1 => 101


    cout<<endl;

}