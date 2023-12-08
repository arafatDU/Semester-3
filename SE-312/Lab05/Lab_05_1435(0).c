#include<stdio.h>
#include<stdbool.h>


bool isSingleLineComment( char *line )
{
    while(*line)
    {
        if(*line == '/' && *(line+1) == '/') return true;
        line++;
    }
    return false;
}


bool isStartMultipleLineComment(char *line)
{
    while(*line)
    {
        if(*line == '/' && *(line+1) == '*') return true;     
        line++;
    }
    return false;
}


bool isEndMultipleLineComment(char *line)
{
    while(*line)
    {
        if(*line == '*' && *(line+1) == '/') return true;     
        line++;
    }
    return false;
}


int main()
{
    FILE *fp = fopen("test_code.c", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }

    char line[100], ch;
    int cnt = 0, i=0;
    bool inMultipleLine = false;
    while(fgets(line, sizeof(line), fp))
    {
        cnt++;
        if(inMultipleLine)
        {
            if(isEndMultipleLineComment(line)) inMultipleLine = false;
        }
        
        if(isSingleLineComment(line))
        {
            printf("Single line comment found at line %d\n", cnt);
            for(i = 0; i< sizeof(line); i++) if(line[i] =='/') break;
            i+=2;
            printf("Comment: ");
            for(i; i< sizeof(line); i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");
        }
        if(isStartMultipleLineComment(line))
        {
            inMultipleLine = true;
            printf("Multiple line comment found at line: %d\n", cnt);
            //if(!isEndMultipleLineComment) printf("Multiple line comment fount at line: %d\n", cnt);
        }
        
        

    }
    if(inMultipleLine) printf("Multiple line Comment Error\n");



    return 0;
}
















/*
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("test_code.c", "r");

    char str[1000], ch;
    int cnt=0, i=0;
    

    // do{
    //     ch = fgetc(fp);
    //     if(ch == '\n') cnt++;

    // } while( ch != EOF);

    while(!feof(fp))
    {
        fgets(str, 100, fp);
        cnt++;
        while(str[i])
        {
            if(str[i] == '/' && str[i+1] == '/') printf("Single line comment found at line %d\n", cnt);
            i++;
        }
        //printf("%s\n", str);
    }



    fclose(fp);
    printf("Total number: %d\n",cnt);

    return 0;
}

*/