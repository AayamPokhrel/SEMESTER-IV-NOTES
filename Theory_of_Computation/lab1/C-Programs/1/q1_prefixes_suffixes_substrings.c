#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int len, i, j;

    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    len = strlen(input);

    if (len == 0)
    {
        printf("\nThe input string is empty (ε).\n");
        printf("\nPrefixes for string \"\":\n");
        printf("  ε\n");
        printf("\nSuffixes for string \"\":\n");
        printf("  ε\n");
        printf("\nSubstrings for string \"\":\n");
        printf("  ε\n");
        return 0;
    }

    printf("\nPrefixes for string \"%s\":\n", input);
    printf("  ε\n");
    for (i = 1; i <= len; i++)
    {
        printf("  %.*s\n", i, input);
    }

    printf("\nSuffixes for string \"%s\":\n", input);
    for (i = 0; i < len; i++)
    {
        printf("  %s\n", input + i);
    }
    printf("  ε\n");

    printf("\nSubstrings for string \"%s\":\n", input);
    printf("  ε\n");
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j <= len; j++)
        {
            printf("  %.*s\n", j - i, input + i);
        }
    }

    return 0;
}
