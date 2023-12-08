#include <stdio.h>
#include <string.h>

int a, b, startState , endState ;
char smbl[100];
int flag = 0;

int nfaTraversal(int trans[a][b][a], int state, char *input, int pos, char *ans){

    if(input[pos]=='\0'){
        if(state == endState){
            ans[pos] = state + '0';
            ans[pos+1] = '\0';
            for(int i=0; i<=pos+1; i++){
                printf("%c ", ans[i]);
            }
            printf("\n");
            flag = 1;
            return 0;
        }else {
            flag = 0;
            return 0;
        }
    }

    ans[pos] = state + '0';
    int value = input[pos] - '0';

    for(int i=0; i<a; i++){
        if(trans[state][value][i] != -1){
            nfaTraversal(trans, trans[state][value][i], input, pos+1, ans);
        }
    }

    return 0;
}

int main(){

    //taking general info
    printf("Enter the number of states : ");
    scanf("%d", &a);
    printf("Enter the number of symbols : ");
    scanf("%d", &b);

    char smbl[b];
    printf("Enter the symbols : ");
    scanf("%s", smbl);

    //taking transition function from file
    int trans[a][b][a];

    FILE *fp = fopen("nfa.txt", "r");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<a; k++){
                fscanf(fp, "%d", &trans[i][j][k]);
            }
        }
    }
    
    // int startState, endState;
    printf("Enter Starting State: ");
    scanf("%d", &startState);
    printf("Enter Ending State: ");
    scanf("%d", &endState);
  
    char str[100];
    char ans[100];
    //ans[0] = startState;

    while (1)
    {
        printf("Enter the String to check : ");
        scanf("%s", str);

        nfaTraversal(trans, 0, str, 0, ans);
        if(flag==0){
            printf("\nRejected\n\n");  
        }else{
            printf("\nAccepted\n\n");  
        }
    }
    
    return 0;
}