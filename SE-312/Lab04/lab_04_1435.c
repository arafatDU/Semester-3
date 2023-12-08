#include<stdio.h>
#include<stdbool.h>
#include<string.h>


void NFA_to_DFA(int num_states,int num_symbol, char *set_of_state,char *alphabet, char initial_state,char final_states,char transition_table[num_states][num_symbol][10],char dfa_transition[num_states][num_symbol+1][10])
{
    dfa_transition[0][0][0] = initial_state;
    for(int i=0; i<num_symbol; i++)
        for(int k=0; transition_table[0][i][k] != '#'; k++)
            dfa_transition[0][i+1][k] = transition_table[0][i][k];

    // for(int i=0; i<num_states; i++)
    // {
    //     for(int j=0; j<num_symbol+1; j++)
    //     {
    //         for(int k=0; k<10; k++)
    //         {
    //             if(k == strlen(transition_table[i][j])) break;
    //             if(i==0 && j==0 && k==0)
    //                 dfa_transition[i][j][k] = initial_state;
                
    //             dfa_transition[i][j+1][k]= transition_table[i][j][k];
    //             
    //         }
    //     }
    // }
    

}


int is_match(char *arr1, char *arr2)
{
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if(len1 != len2) return 0;
    for(int i=0; i<len1; i++)
    {
        if(arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

int main()
{
    int num_states,num_symbol,num_final;
    printf("Enter the number of states: ");
    scanf("%d",&num_states);
    printf("Enter the number of symbol in alphabet: ");
    scanf("%d",&num_symbol);
    getchar();

    char set_of_state[num_states],alphabet[num_symbol],initial_state,final_states,transition_table[num_states][num_symbol][10],steps[100];
    char dfa_transition[num_states][num_symbol+1][10];
    for(int i=0; i<num_states; i++){
        printf("Enter state %d: ",i+1);
        scanf("%c",&set_of_state[i]);
        getchar();
    }
    printf("\n\n");

    for(int i=0; i<num_symbol; i++){
        printf("Enter %dth symbol of alphabet: ",i+1);
        scanf("%c",&alphabet[i]);
        getchar();
    }

    printf("Enter the initial state: ");
    scanf("%c",&initial_state);
    getchar();

    printf("Enter the final state: ");
    scanf("%c",&final_states);
    getchar();

    for(int i=0; i<num_states; i++){
        for(int j=0; j<num_symbol; j++){
            for(int k=0; k<10; k++){
                transition_table[i][j][k] = '#';
            }
        }
    }
    for(int i=0; i<num_states; i++){
        for(int j=0; j<num_symbol+1; j++){
            for(int k=0; k<10; k++){
                dfa_transition[i][j][k] = '*';
            }
        }
    }

    int num_transition[num_states][num_symbol];
    for(int i=0; i<num_states; i++){
        printf("For %c: \n",set_of_state[i]);
        for(int j=0; j<num_symbol; j++){
            printf("If the input is %c : \n",alphabet[j]);
            printf("How many transition? : ");
            scanf("%d",&num_transition[i][j]);
            getchar();
            for(int k=0; k<num_transition[i][j]; k++){
                scanf("%c",&transition_table[i][j][k]);
                getchar();
            }
        }
    }


    // checking transition table
    printf("DFA Transition Table: \n");
    for(int i=0; i<num_states; i++){
        printf("%d  ", i);
        for(int j=0; j<num_symbol; j++){
            for(int k=0; k<10; k++){
                printf("%c ", transition_table[i][j][k]);
            }
            printf(" ");
        }
        printf("\n");
    }



    NFA_to_DFA(num_states, num_symbol, set_of_state, alphabet, initial_state, final_states, transition_table, dfa_transition);


    // checking dfa transition table
    for(int i=0; i<num_states; i++){
        for(int j=0; j<num_symbol+1; j++){
            for(int k=0; k<10; k++){
                printf("%c ", dfa_transition[i][j][k]);
            }
            printf(" ");
        }
        printf("\n");
    }


    return 0;
}