#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool result = false;

int length, cnt =0;
char input[100], store[100];
char looping;

void stateTransition(int num_states,int num_symbol,char *setofstate,char *alphabet,char initialstate,char finalstate,char transition[num_states][num_symbol][10],int num_transition[num_states][num_symbol],int index)
{
    if(index==length && initialstate == finalstate){
        result = true;
        store[cnt++] = initialstate;
        for(int j=0; j<cnt; j++)printf("%c ",store[j]);
        printf("\n");
        return;
    }
    if(index==length && initialstate != finalstate){
        cnt--;
        looping = initialstate;
        return;
    }
    int i;
    for(i=0; i<num_symbol; i++){
        if(alphabet[i]==input[index])break;
    }
    if(num_transition[initialstate-'a'][i]==0)return;
    int k=0;
    store[cnt++] = initialstate;
    while(k<num_transition[initialstate-'a'][i] && !result){
        stateTransition(num_states,num_symbol,setofstate,alphabet,transition[initialstate-'a'][i][k],finalstate,transition,num_transition,index+1);
        k++;
    }
    return;
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
                transition_table[i][j][k] = '*';
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
    // checking num_transition matrix
    for(int i=0; i<num_states; i++){
        printf("%d  ", i);
        for(int j=0; j<num_symbol; j++){
            printf("%d ", num_transition[i][j]);
        }
        printf("\n");
    }

    printf("Enter the string: ");
    scanf("%s",input);
    length = strlen(input);
    stateTransition(num_states,num_symbol,set_of_state,alphabet,initial_state,final_states,transition_table,num_transition,0);
    if(result)printf("Accepted\n");
    else printf("Rejected because looping in %c\n",looping);
    return 0;
}