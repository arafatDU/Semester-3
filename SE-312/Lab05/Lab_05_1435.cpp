#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    char ch;
    int i=0, j=0, line_num = 1, multipleEndAt;
    bool isEndMultipleLine = false;
    FILE *fp;
    fp = fopen("test_code.c", "r");

    if(fp == NULL){
        cout<<"Error openning file"<<endl;
        return 1;
    }

    while(!feof(fp))
    { 
        ch = fgetc(fp);  
        if(ch > 1 && ch < 127) str += ch;
    }

    cout<<str<<endl;

    for( i=0; i<str.length(); i++)
    {
        if(str[i] == '\n') line_num++;

        // Single line comment
        if(str[i] == '/' && str[i+1] == '/')
        {
            cout<<"\nSingle line comment found at "<< line_num<<endl<<"Comment: ";
            int j = i+2;
            while(str[j] != '\n')
            {
                cout<<str[j];
                j++;
            }
            cout<<endl<<endl;
        }

        // Multiple line comment
        if(str[i] == '/' && str[i+1] == '*')
        {
            cout<<"Start Multiple line comment at line: "<<line_num<<endl;
            j = i+2;
            multipleEndAt = line_num;
            while(str[j]){
                if(str[j] == '\n') multipleEndAt++;
                if(str[j] == '/' && str[j+1] == '*') break;
                if(str[j] == '*' && str[j+1] == '/')
                {
                    isEndMultipleLine = true;
                    break;
                }
                j++;
            }
            if(!isEndMultipleLine){
                cout<<"Error!!!  NO END OF MULTIPLELINECOMMENT"<<endl<<endl;
            }
        }

        // Printing multiple line if there is found end of MULTIPLELINECOMMENT
        if(isEndMultipleLine)
        {
            cout<<"End of multiple line comment at line "<< multipleEndAt<<endl<<"Comment: ";
            for(i+=2; i<= j-2; i++)
            {
                cout<<str[i];
            }
            cout<<endl<<endl;
            isEndMultipleLine = false;
        }
    }




    return 0;
}