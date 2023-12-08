#include<bits/stdc++.h>
using namespace std;

bool processStringWithStack(string input) {
    stack<char> myStack;
    int i=0;
    int len = input.length();
    bool check;

    // for (i=0; i<len/2; i++) {
    //     if (input[i] == '0') {
    //         myStack.push(input[i]);
    //     } else{
    //         return false;
    //     }
    // }
    // for (i; i<len; i++) {
    //     if (input[i] == '1') {
    //         myStack.pop();
    //     } else{
    //         return false;
    //     }
    // }
    while(input[i++] == '0')
    {
        myStack.push(input[i]);
    }
    while(input[i++] != '\0')
    {
        if(myStack.empty()) return false;
        myStack.pop();
    }
    
    if(myStack.empty()) return true;
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    if(processStringWithStack(input)) cout<<"Accepted"<<endl;
    else cout<<"Rejected"<<endl;

    return 0;
}
