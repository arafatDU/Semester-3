#include<bits/stdc++.h>
using namespace std;

string RE, w, x, y, z, k, s1, s2;
int r1, r2, n;

bool isAccepted(string s)
{
    int numOfZero = 0, numOfOne = 0;
    for(int i =0; i< s.size(); ++i){
        if(s[i] == '0') numOfZero++;
        else numOfOne++;
    } 
    return (r1 * n == numOfZero) and (r2 *n == numOfOne);
}



bool checkString(){
    string generated_w;
    int temp_k = 0;
    bool isInLan;

    while(true){
        generated_w+=x;
        for(int i = 1; i <= temp_k; ++i) generated_w+=y;
        generated_w+=z;
        
        cout << "Generated : " << generated_w << endl;
        isInLan = isAccepted(generated_w);
        if(isInLan == false){
            k = temp_k;
            break;
        } 
        generated_w.clear();
        temp_k++;
    }
    if(isInLan == false) return false;
    return true;
}


void pump()
{
    string generated_w;
    int l, temp_k;
    bool isInLan;
    // separator
    l = rand() % n + 1;
    cout << "Separator, l = " << l << endl;

    for(int i = 0; i < l; ++i) x += w[i];
    for(int i = l; i < n; ++i) y += w[i];
    for(int i = n; i < w.size(); ++i) z+=w[i];

    cout << "x: " << x << " y: " << y << " z: " << z<< endl;

}

void get_num_from_re()
{
    int i;
    for(i = 0; i < RE.size();++i){
        if(RE[i] == '0' and RE[i+1] == '^'){
            i++;
            break;       
        }
    }
    
    while(RE[++i] != '^'){
        s1+=RE[i];
    }

    if(s1[s1.size()-1] == '1') s1.resize(s1.size()-1);
    while(RE[++i]!='\0'){
        s2+=RE[i];
    }
    
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;  
    s1.erase(s1.size() - 1);
    s2.erase(s2.size() - 1);
    if(s1.size() == 0) s1 = "1";


    //cout << "s1: " << s1 << endl << "s2: " << s2 << endl; 
    r1 = stoi(s1);
    r2 = stoi(s2);
}


void generateString(){
    int i;
    int len = (r1 + r2) * n;
    for(i = 0; i < len ;++i){
        if(i < r1*n) w+='0'; 
        if(i >= r1*n) w+='1'; 
    }
}

int main()
{
    int k = 0, i;
    //freopen("input.txt", "r", stdin);
    cout<<"Enter Regular Expression: ";
    cin >> RE;
    cout << "Regular Expression: " << RE << endl;

    //substring from regular expression
    get_num_from_re();
    cout << "r1: " << r1 << endl << "r2: " << r2 << endl; 


    srand(time(0));
    n = rand() % 10 + 2;
    cout<<"n = "<<n<<endl;

    generateString();
    cout << "String, w: " << w << endl;

    pump();

    checkString();


    return 0;
}