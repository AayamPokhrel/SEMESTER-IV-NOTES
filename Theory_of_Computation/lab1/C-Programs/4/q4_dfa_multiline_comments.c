#include <stdio.h>
#include <string.h>

enum states { q0, q1, q2, q3, q4, qd };

const char *state_str[] = { "->*q0", "   q1", "   q2", "   q3", "  *q4", "   qd" };

enum states delta(enum states s, char ch)
{
    switch (s)
    {
        case q0:
            if (ch == '/') return q1;
            return qd; /* '*' or any other char */
        case q1:
            if (ch == '*') return q2;
            return qd; /* '/' or any other char (// is single-line comment, rejected) */
        case q2:
            if (ch == '*') return q3;
            return q2; /* '/' or any other char stays in q2 */
        case q3:
            if (ch == '/') return q4;
            if (ch == '*') return q3;
            return q2; /* any other char goes back to q2 */
        case q4:
            if (ch == '/') return q1; /* can start another comment */
            return qd; /* '*' or any other char */
        case qd:
            return qd;
    }
    return qd;
}

int main()
{
    char input[2000];
    int len = 0;
    int ch;
    enum states curr;
    int i;

    printf("Enter your multi-line comment (press Ctrl+Z on a new line on Windows, or Ctrl+D on Unix to end input):\n");

    /* Read all input until EOF */
    while ((ch = getchar()) != EOF)
    {
        if (len < (int)sizeof(input) - 1)
            input[len++] = (char)ch;
    }
    input[len] = '\0';

    /* Remove trailing newline/carriage return */
    while (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r'))
        input[--len] = '\0';

    if (len == 0)
    {
        printf("\nEmpty input (ε). Staying in initial state ->*q0.\n");
        printf("Since \"ε\" also occurs in the language (L), initial state is also one of the final states.\n");
        printf("The comment \"ε\" is accepted by DFA in a C-Program.\n");
        return 0;
    }

    if (len > 0 && len < 4)
    {
        printf("\nNote: Non-empty multi-line comments require at least 4 characters (e.g., \"/**/\").\n");
    }

    printf("Total defined states: {q0, q1, q2, q3, q4, qd}\n");
    printf("\nSince \"ε\" also occurs in the language (L), initial state is also one of the final states.\n");
    printf("Note: \"//\" (single-line comment) is not accepted by this DFA.\n");
    printf("Initial state: ->*q0\n");
    printf("Final states: *q0, *q4\n");
    printf("Dead state: qd\n");
    printf("Processing the string:\n");

    curr = q0;
    for (i = 0; i < len; i++)
    {
        enum states next = delta(curr, input[i]);
        /* Display special characters with escape notation */
        if (input[i] == '\n')
            printf("%s --- (\\n) ---> %s\n", state_str[curr], state_str[next]);
        else if (input[i] == '\r')
            printf("%s --- (\\r) ---> %s\n", state_str[curr], state_str[next]);
        else if (input[i] == '\t')
            printf("%s --- (\\t) ---> %s\n", state_str[curr], state_str[next]);
        else
            printf("%s --- (%c)  ---> %s\n", state_str[curr], input[i], state_str[next]);
        curr = next;
    }

    if (curr == q0 || curr == q4)
        printf("The comment is accepted by DFA as a valid multi-line comment in a C-Program.\n");
    else
        printf("Either the comment is incomplete or the comment is invalid. Therefore, it is not accepted by DFA as a multi-line comment in a C-Program.\n");

    return 0;
}
