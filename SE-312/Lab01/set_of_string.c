#include<stdio.h>

int get_length(char str[])
{
    int count = 0;
    while(str[count] != '\0') count++;
    return count;
}

void generate_string(char alphabet[], int k, char str[], int index)
{
    if(index == k)
    {
        str[index] = '\0';
        printf("%s ", str);
        return;
    }

    for(int i=0; i< 2; i++)
    {
        str[index] = alphabet[i];
        generate_string(alphabet, k, str, index+1);
    }
}


int isPalindrome(char str[])
{
    int len = get_length(str);
    int left = 0;
    int right = len -1;
    while(left<right)
    {
        if(str[left] != str[right]) return 0;
        left++;
        right--;
    }
    return 1;
}

int main()
{
    char alphabet[] = {'0', '1'};
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    char str[k+1];


    generate_string(alphabet, k, str, 0);
    printf("\n");



    char w[100];
    printf("Enter a string to check palindrome: ");
    scanf("%s",w);
    if(isPalindrome(w)) printf("The string is palindrome.\n");
    else printf("The string is not palindrome.\n");


    return 0;
}
