#include<bits/stdc++.h>

using namespace std;

void spreadRumor(vector<vector<int>>& friends, vector<int>& chocolates, int student, vector<bool>& visited) {
    visited[student] = true;
    for (int friendStudent : friends[student]) {
        if (!visited[friendStudent]) {
            spreadRumor(friends, chocolates, friendStudent, visited);
        }
    }
}



int main() {
    freopen("input.txt","r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> chocolates(n);
    vector<vector<int>> friends(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> chocolates[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        friends[x - 1].push_back(y - 1);  
        friends[y - 1].push_back(x - 1);
    }

    vector<int> sortedIndexByNeededChoc(n);
    for (int i = 0; i < n; ++i) {
        sortedIndexByNeededChoc[i] = i;
    }

    sort(sortedIndexByNeededChoc.begin(), sortedIndexByNeededChoc.end(), [&chocolates](int a, int b) {
        return chocolates[a] < chocolates[b];
    });

    vector<bool> visited(n, false);
    int totalChocolates = 0;

    for (int i = 0; i < n; ++i) {
        int student = sortedIndexByNeededChoc[i];
        if (!visited[student]) {
            totalChocolates += chocolates[student];
            spreadRumor(friends, chocolates, student, visited);
        }
    }

    cout << totalChocolates << endl;

    return 0;
}
