#include <bits/stdc++.h>
using namespace std;

#define STATES 3

// Function to calculate regular expressions Rij(k)
// void calculateRegularExpressions(char *regex[STATES][STATES], int k)
// {
//     if (k == 0)
//     {
//         // Initialize base cases for k = 0
//         regex[0][0] = "e + 1";
//         regex[0][1] = "0";
//         regex[0][2] = "#";
//         regex[1][0] = "1";
//         regex[1][1] = "e";
//         regex[1][2] = "0";
//         regex[2][0] = "#";
//         regex[2][1] = "1";
//         regex[2][2] = "0 + e";
//         return;
//     }
// }

int main()
{
    int k = 0;
    string RE[STATES][STATES][STATES];

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
