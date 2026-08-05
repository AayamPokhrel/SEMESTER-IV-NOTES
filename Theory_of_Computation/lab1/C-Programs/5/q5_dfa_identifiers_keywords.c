#include <stdio.h>
#include <string.h>

enum states { q0, q1, qd };

const char *state_str[] = { "->q0", " *q1", "  qd" };

/* C keywords list */
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while", NULL
};

int is_letter_or_underscore(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

int is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}

enum states delta(enum states s, char ch)
{
    switch (s)
    {
        case q0:
            if (is_letter_or_underscore(ch)) return q1;
            return qd;
        case q1:
            if (is_letter_or_underscore(ch) || is_digit(ch)) return q1;
            return qd;
        case qd:
            return qd;
    }
    return qd;
}

int is_keyword(const char *str)
{
    int i;
    for (i = 0; keywords[i] != NULL; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[100];
    enum states curr;
    int i, len;

    printf("Alphabets Σ={A..Z, a..z, 0..9, _}\n");
    printf("Enter a string to validate as C identifier or keyword:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    len = strlen(input);

    if (len == 0)
    {
        printf("Empty string is neither a keyword nor an identifier. It is rejected by DFA.\n");
        return 1;
    }

    printf("Total defined states: {q0, q1, qd}\n");
    printf("Initial state: ->q0\n");
    printf("Final state: *q1\n");
    printf("Dead state: qd\n");
    printf("Processing the string \"%s\":\n", input);

    curr = q0;
    for (i = 0; i < len; i++)
    {
        enum states next = delta(curr, input[i]);
        printf("%s --- (%c) ---> %s\n", state_str[curr], input[i], state_str[next]);
        curr = next;
    }

    if (curr == q1)
    {
        if (is_keyword(input))
            printf("\"%s\" is a keyword. It is accepted by DFA.\n", input);
        else
            printf("\"%s\" is a valid identifier. It is accepted by DFA.\n", input);
    }
    else
    {
        printf("\"%s\" is neither a keyword nor a valid identifier. It is rejected by DFA.\n", input);
    }

    return 0;
}
