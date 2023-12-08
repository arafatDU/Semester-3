#include<stdio.h>
#include<time.h>

char str[5][21];

int get_length(char str[])
{
    int count = 0;
    while(str[count] != '\0') count++;
    return count;
}

int check_string(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != '0' && str[i] != '1') return 0;
        i++;
    }
    return 1;
}

void concate_two_string(char str1[], char str2[])
{
	int l = get_length(str1) + get_length(str2);
	char z[l];
	int i = 0, j=0;
	while(str1[i] != '\0')
	{
        z[i] = str1[i];
        i++;
	}
	while(str2[j] != '\0')
	{
        z[i] = str2[j];
        i++;
        j++;
	}
	z[i] = '\0';
	printf("%s", z);
}

int main()
{
    srand(time(0));

    for(int i=0; i < 5; i++)
    {
        int size = rand() % 20 + 1;
        for(int j=0; j<size; j++)
        {
            str[i][j] = rand()%2 + '0';
        }
    }
    for(int i=0; i < 5; i++)
    {
        printf("string: %s length: %d\n", str[i], get_length(str[i]));
    }
    printf("\n\n");


    char test_str[100];
    printf("Enter a string to test whether it is from alphabet: ");
    scanf("%s", test_str);
    if(check_string(test_str)) printf("This string is from the alphabet!!\n\n");
    else printf("String is not from the alphabet.\n\n");


    char x[100], y[100];
    printf("Enter first string: ");
    scanf("%s", x);
    getchar();
    printf("Enter second string: ");
    scanf("%s", y);
    printf("The Concated String: ");
    concate_two_string(x, y);

    return 0;
}
