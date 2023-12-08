#include<bits/stdc++.h>
using namespace std;

string w, S;

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




void Leftmost(string w, string S)
{
    // replacing 'A' with "0A" or Empty
    int i = 0;
    while(w[i++] != '1')
    {
        S = replace( S, 'A', "0A");
        cout<<" => "<<S;
    }
    S = replace( S, 'A', "");
    cout<<" => "<<S;


    // replacing 'B' with "0B" or "1B" or Empty
    while(w[i] != '\0')
    {
        if(w[i] == '0') 
        {
            S = replace( S, 'B', "0B");
            cout<<" => "<<S;
        }
        
        if(w[i] == '1') 
        {
            S = replace( S, 'B', "1B");
            cout<<" => "<<S;
        }
        i++;
    }
        
    S = replace( S, 'B', "");
    cout<<" => "<<S;

}




void Rightmost(string w, string S)
{
    int i = 0;
    for( i; i<w.length(); i++)
        if(w[i] == '1') break;


    // replacing 'B' with "0B" or "1B" or Empty
    while(w[i++] != '\0')
    {
        if(w[i] == '0') 
        {
            S = replace( S, 'B', "0B");
            cout<<" => "<<S;
        }
        
        if(w[i] == '1') 
        {
            S = replace( S, 'B', "1B");
            cout<<" => "<<S;
        }
    }   
    S = replace( S, 'B', "");
    cout<<" => "<<S;


    // replacing 'A' with "0A" or Empty
    i = 0;
    while(w[i++] != '1')
    {
        S = replace( S, 'A', "0A");
        cout<<" => "<<S;
    }
    S = replace( S, 'A', "");
    cout<<" => "<<S;


}



int main()
{
    cout<<"Enter string: ";
    cin>>w;



    S = "A1B";
    cout<< "Leftmost: S => "<<S;
    Leftmost(w, S);
    cout<<endl;
   
    S = "A1B";
    cout<<"Rightmost: S => "<<S;
    Rightmost(w, S);
    cout<<endl;


    cout<<endl;

}