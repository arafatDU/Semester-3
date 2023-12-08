#include <bits/stdc++.h>

using namespace std;
int dowmCount=0, sideCount= 0;

bool isSafe(int **arr, int x, int y, int n, int **solArr)
{
    if (x < n && y < n && arr[x][y] == 1)
        return true;

    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{
    // Base case
    if(x == n-1 && y == n-1 && arr[x][y] == 1)
    {   
        solArr[x][y] = 1; 
        return true;
    }


    if (isSafe(arr, x, y, n, solArr))
    {
        solArr[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, solArr))
        {
            dowmCount++;
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, solArr))
        {
            sideCount++;
            return true;
        }

        solArr[x][y] = 0;         // backtracking
        return false;
    }
    return false;
}

int main()
{
    freopen("ratInMaze.txt", "r", stdin);
    int n;
    cin >> n;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
            solArr[i][j] = 0;
    }

    if (ratInMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout<<solArr[i][j]<< " ";
            cout<<endl;
        }
    }else{
        cout<<"No way"<<endl;
    }

    cout<<"Down: "<<dowmCount<<"   Side: "<<sideCount<<endl;

    return 0;
}


// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1