#include <bits/stdc++.h>
using namespace std;

#define STATES 3
#define SYMBOLS 2

string dfa_transition[STATES][SYMBOLS+1];

void readInput()
{
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cin>>dfa_transition[i][j];
        }
    }
}

int main()
{
    int k = 0;
    string RE[STATES][STATES][STATES];
    string Transition[STATES][STATES];

    freopen("input.txt", "r", stdin);
    readInput();

    for(int i=0; i<STATES; i++)
    {
        if(dfa_transition[i][1] == "q0")
            Transition[i][0] = "0";
        else if(dfa_transition[i][2] == "q0")
            Transition[i][0] = "1";
        else
            Transition[i][0] = "#";

        if(dfa_transition[i][1] == "q1")
            Transition[i][1] = "0";
        else if(dfa_transition[i][2] == "q1")
            Transition[i][1] = "1";
        else
            Transition[i][1] = "#";

        if(dfa_transition[i][1] == "q2")
            Transition[i][2] = "0";
        else if(dfa_transition[i][2] == "q2")
            Transition[i][2] = "1";
        else
            Transition[i][2] = "#";
        
    }

    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<STATES; j++)
        {
            cout<<Transition[i][j]<<" ";
        }
        cout<<endl;
    }

/*
    string Transition[STATES][STATES] = {
        {"1", "0", "#"},
        {"1", "#", "0"},
        {"#", "1", "0"}
    };
*/

    for(int i=0; i<STATES; i++)
    {
        if(Transition[i][i] != "#")
            RE[i][i][0] = "e + ";
        for(int j=0; j<STATES; j++)
        {
            RE[i][j][0] += Transition[i][j];
            if(RE[i][i][0] == "#") RE[i][i][0] = "e";
        }
    }

/*
    // Initialize base cases for k = 0
    RE[0][0][0] = "e + 1";
    RE[0][1][0] = "0";
    RE[0][2][0] = "#";
    RE[1][0][0] = "1";
    RE[1][1][0] = "e";
    RE[1][2][0] = "0";
    RE[2][0][0] = "#";
    RE[2][1][0] = "1";
    RE[2][2][0] = "0 + e";
*/

    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(0) = " + RE[i][j][0]<<endl;




    k = 1;
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
                if(RE[i][k][k-1] == "#" || RE[k][k][k-1] == "#" || RE[k][j][k-1] == "#")
                {
                    RE[i][j][k] = RE[i][j][k-1];
                }else
                {
                    RE[i][j][k] = RE[i][j][k-1] + " + (" + RE[i][k][k-1] + ")(" + RE[k][k][k-1] + ")*(" + RE[k][j][k-1] + ")";
                }


    // Print Rij(1)
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(1) = " + RE[i][j][1]<<endl;




    cout<<endl<<endl;


    k = 2;
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
                if(RE[i][k][k-1] == "#" || RE[k][k][k-1] == "#" || RE[k][j][k-1] == "#")
                {
                    RE[i][j][k] = RE[i][j][k-1];
                }else
                {
                    RE[i][j][k] = RE[i][j][k-1] + " + (" + RE[i][k][k-1] + ")(" + RE[k][k][k-1] + ")*(" + RE[k][j][k-1] + ")";
                }


    // Print Rij(2)
    for(int i=0; i<STATES; i++)
        for(int j=0; j<STATES; j++)
            cout<<"R"<< i << j<<"(2) = " + RE[i][j][2]<<endl;



    return 0;
}



































/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STATES 3

// Function to concatenate two strings
void concatenate(char *result, const char *str) {
    strcat(result, str);
}



// Function to calculate regular expressions Rij(k)
void calculateRegularExpressions(char transitionTable[STATES][STATES], char *regex[STATES][STATES], int k) {
    if (k == 0) {
        for (int i = 0; i < STATES; i++) {
            for (int j = 0; j < STATES; j++) {
                strcpy(regex[i][j], transitionTable[i][j]);
            }
        }
        return;
    }

    char temp[100]; // Temporary buffer to store intermediate results

    // Calculate regular expressions using the formula
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            strcpy(temp, "");
            for (int r = 0; r < STATES; r++) {
                char intermediate[100];
                strcpy(intermediate, regex[i][r]);
                strcat(intermediate, regex[r][r]);
                strcat(intermediate, regex[r][j]);
                if (strlen(temp) > 0) {
                    strcat(temp, " + ");
                }
                strcat(temp, intermediate);
            }
            strcpy(regex[i][j], temp);
        }
    }

    calculateRegularExpressions(transitionTable, regex, k - 1);
}


char alphabet[36], start, final, cur_state;
int n,m;

int main()
{
    char transition[STATES][STATES] = {
        {'a', 'b', 'a'},
        {'b', 'c', 'a'},
        {'c', 'c', 'b'}
    };
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m+1;++j){
            printf("%c  ", transition[i][j]);
        }
        printf("\n");
    }

    


    int k = 0; // Number of intermediate states
    char *regex[STATES][STATES]; // Regular expression matrix

    //calculateRegularExpressions(transition, regex, k);

    // Print the calculated regular expressions
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            printf("R%c%c(%d) = %s\n", 'a' + i, 'a' + j, k, regex[i][j]);
        }
    }


    return 0;
}

*/