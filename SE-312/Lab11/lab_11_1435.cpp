#include<bits/stdc++.h>
using namespace std;

string w, S[3];

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




string Leftmost(string w, string S)
{
    string temp_S = S;
    // replacing 'S' with "aS" or Empty
    int i = 1;
    while(w[i++] != 'b')
    {
        if(temp_S.find('b') != string::npos)
            temp_S = replace( temp_S, 'S', "aS");
        else 
            temp_S = replace(S, 'S', "aSbS");
        cout<<" => "<<temp_S;
    }
    temp_S = replace( temp_S, 'S', "");
    cout<<" => "<<temp_S;


    // replacing 'B' with "0B" or "1B" or Empty
    while(w[i] != '\0')
    {
        if(w[i] == 'a') 
        {
            temp_S = replace( temp_S, 'S', "aS");
            cout<<" => "<<temp_S;
        }
        
        if(w[i] == 'b') 
        {
            temp_S = replace( temp_S, 'S', "aSbS");
            cout<<" => "<<temp_S;
        }
        i++;
    }
        
    temp_S = replace( temp_S, 'S', "");
    cout<<" => "<<temp_S;


    return temp_S;

}



int main()
{
    string s1, s2;
    //cout<<"Enter string: ";
    //cin>>w;
    w = "aab";


    S[0] = "aS";
    S[1] = "aSbS";

    cout<< "Leftmost: S => "<<S[0];
    s1 = Leftmost(w, S[0]);
    cout<<endl<<s1<<endl<<endl;

    cout<< "Leftmost: S => "<<S[1];
    s2 = Leftmost(w, S[1]);
    cout<<endl<<s2<<endl;
   
    
    if(w == s1 && s1== s2) cout<<"The grammar is ambiguous."<<endl;
    else cout<<"Not ambiguous."<<endl;

    cout<<endl;

}