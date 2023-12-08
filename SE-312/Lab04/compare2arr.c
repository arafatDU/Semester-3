#include<stdio.h>
#include<string.h>


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
    char arr1[10] = {'a', 'b'};
    char arr2[10] = {'a', 'b', 'c'};
    char arr3[10] = {'a', 'c'};

    int len1 = strlen(arr1);

    printf("Length: %d\n", len1);

    printf("match: %d\n", is_match(arr1, arr2));



}