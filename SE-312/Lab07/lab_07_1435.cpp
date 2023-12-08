#include<bits/stdc++.h>
using namespace std;

#define STATES 8
#define SYMBOLS 2

string initialState, finalstate;
string dfa_transition[STATES][SYMBOLS+1];
string TF[STATES][STATES];
string equivalence[STATES][2];

void readInput()
{
    cin>>initialState>>finalstate;
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cin>>dfa_transition[i][j];
        }
    }
}


int getIndex(string s)
{
    int i;
    for(i=0; i<STATES; i++)
        if(dfa_transition[i][0] == s) break;
    return i;
}


bool canBeEquivalence(int index1, int index2)
{
    if(dfa_transition[index1][1] == finalstate && dfa_transition[index2][1] != finalstate) return false;
    else if(dfa_transition[index1][1] != finalstate && dfa_transition[index2][1] == finalstate) return false;
    
    else if(dfa_transition[index1][2] == finalstate && dfa_transition[index2][2] != finalstate) return false;
    else if(dfa_transition[index1][2] != finalstate && dfa_transition[index2][2] == finalstate) return false;

    return true;
}


bool isEquivalence(string s1, string s2)
{
    //cout<<"("<<s1<< " "<< s2<<") "<<endl;
    int index1, index2;
    if(s1 == finalstate || s2 == finalstate) return false;

    index1 = getIndex(s1);
    index2 = getIndex(s2);
    //cout<<"For index "<<index1<<" and "<<index2<<endl;

    if(!canBeEquivalence(index1, index2)){
        // states cannot be equivalence---proved
        return false;
    }
    else{
        cout<<endl<<"("<<s1<< " "<< s2<<") is in else conditions for check 00/01 and 10/11"<<endl;
        
        // First check 10/11 ----> (s1_1)---0--- and (s2_1)----1---
        string stateFromS1By1 = dfa_transition[index1][2];
        string stateFromS2By1 = dfa_transition[index2][2];

        // Second check 00/01 ----> (s1_0)---0--- and (s2_0)----1---
        string stateFromS1By0 = dfa_transition[index1][1];
        string stateFromS2By0 = dfa_transition[index2][1];

        index1 = getIndex(stateFromS1By1);
        index2 = getIndex(stateFromS2By1);

        if(!canBeEquivalence(index1, index2)){
            // states cannot be equivalence---proved
            return false;
        }
        else{
            cout<<endl<<"---- Now check 00 or 01---"<<endl;

            index1 = getIndex(stateFromS1By0);
            index2 = getIndex(stateFromS2By0);

            if(!canBeEquivalence(index1, index2)) return false;

        }
    }
    

    return true;

}


int indexOfMatchedRemovedState(string s)
{
    for(int i=0; i<STATES; i++)
    {
        if(s == equivalence[i][0])
        {
            return i;
        }
    }
    return 0;
}


int main()
{
    freopen("input.txt", "r", stdin);
    readInput();


    // Print given transition table
    cout<<finalstate<<endl;
    cout<<"  0 1"<<endl;
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cout<<dfa_transition[i][j]<<" ";
        }
        cout<<endl;
    }


    // Initialize all to 'X'
    for(int i=1; i<STATES; i++)
    {
        for(int j=0; j<i; j++)
        {
            TF[i][j] = "X";
        }
    }


    // Checking the equivalence state
    
    string s1, s2;
    for(int i=1; i<STATES; i++)
    {
        s1 = dfa_transition[i][0];
        for(int j=0; j<i; j++)
        {
            s2 = dfa_transition[j][0];
            //cout<<"("<<s1<< " "<< s2<<") ";
            if(isEquivalence(s1, s2)) 
            {
                TF[i][j] = "=";
                if(s1 != initialState)
                {
                    equivalence[i][0] = s1;
                    equivalence[i][1] = s2; 
                }
                else 
                {
                    equivalence[i][0] = s2;
                    equivalence[i][1] = s1; 
                }
            }
        }
    }



    cout<<endl<<endl;
    // Print Table Fillin TF
    for(int i=1; i<STATES; i++)
    {
        cout<< dfa_transition[i][0]<< " ";
        for(int j=0; j<i; j++)
        {
            cout<<TF[i][j]<< " ";
        }
        cout<<endl;
    }


    for(int i=0; i<STATES; i++)
        for(int j=0; j<2; j++)
            if(equivalence[i][j] != " ")
                cout<<equivalence[i][j]<<" ";


    // Print final transition table
    cout<<endl<<endl;
    for(int i=0; i<STATES; i++)
    {
        if(dfa_transition[i][0] == equivalence[i][0]) continue;
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            int index = indexOfMatchedRemovedState(dfa_transition[i][j]);
            if(index) cout<<equivalence[index][1]<<" ";
            else cout<<dfa_transition[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}