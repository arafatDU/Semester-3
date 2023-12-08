#include<stdio.h>
#include<stdbool.h>

char alphabet[36], start, final, cur_state;
int n,m;


int getIndex(char transition[n][m+1]);
void dfa(char s[],char transition[n][m+1]);

int main(){

    printf("Enter the no of states:");
    scanf("%d", &n);
    char setOfState[n];
    printf("Enter the set of states:\n");
    for (int i = 0; i < n; ++i){
        getchar();
        scanf("%c", &setOfState[i]);
    }

    for (int i = 0; i < n; ++i){
        printf("%c  ", setOfState[i]);
    }

    printf("\nEnter the no of alphabets:");
    scanf("%d", &m);
    printf("Enter the symbols:\n");
    for (int i = 0; i < m; i++){
        getchar();
        scanf("%c", &alphabet[i]);
    }
    
    for (int i = 0; i < n; ++i){
        printf("%c  ", alphabet[i]);
    }

    char transition[n][m+1];
    printf("\nEnter the transition table:\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m+1;++j){
            getchar();
            scanf("%c",&transition[i][j]);
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m+1;++j){
            printf("%c  ", transition[i][j]);
        }
        printf("\n");
    }

    printf("Enter start state:");
    getchar();
    scanf("%c", &start);

    printf("start state-->%c\n", start);

    printf("Enter final state:");
    getchar();
    scanf("%c", &final);

    printf("final state-->%c\n", final);

    char s[100];
    printf("Input string:");
    getchar();
    scanf("%s", s);



    int k = 0; bool b = false;
    while(s[k] != '\0'){
        int i;
        for(i = 0; i < m; ++i){
            if(s[k] == alphabet[i]){
                b = true;
                break;   
            }    
        }
        if(i == m){
            b = false;
            break;
        } 
        k++;
    }

    //b ? printf("\nAccepted\n") /*Function call*/ : printf("\nRejected\n");

    if(b){
        cur_state = start;
        dfa(s,transition);
    }else printf("Rejected\n");

    return 0;
}


void dfa(char s[],char transition[n][m+1]){
    int k = 0;
    int cur_index;
    while(s[k] != '\0'){
        // cur_state index
        int cur_index = getIndex(transition);// i
        for(int i = 0; i < m; ++i){
            if(s[k] == alphabet[i]){
                cur_state = transition[cur_index][i+1];
                printf("%c-->%c\n",s[k], cur_state);
            }
        }
        k++;
    }

    if(cur_state == final) printf("Accepted\n");
    else printf("Rejected\n");

}

int getIndex(char transition[n][m+1]){
    int cur_index;
    for(int i = 0; i < n; ++i){
            if(cur_state == transition[i][0]){
                cur_index = i;
                return cur_index;
            }
        }
    return -1;
}