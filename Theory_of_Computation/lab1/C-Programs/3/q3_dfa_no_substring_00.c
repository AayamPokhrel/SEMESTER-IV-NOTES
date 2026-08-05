#include <stdio.h>
#include <string.h>

enum states { q0, q1, qd };

const char *state_str[] = { "->*q0", "  *q1", "   qd" };

enum states delta(enum states s, char ch)
{
    switch (s)
    {
        case q0:
            if (ch == '0') return q1;
            if (ch == '1') return q0;
            break;
        case q1:
            if (ch == '0') return qd;
            if (ch == '1') return q0;
            break;
        case qd:
            return qd;
    }
    return qd;
}

int main()
{
    char input[100];
    enum states curr;
    int i, len;

    printf("Enter any string from Σ={0,1}:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    len = strlen(input);

    /* Validate alphabet */
    for (i = 0; i < len; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Cannot process string outside of Σ={0,1}.\n");
            return 1;
        }
    }

    printf("Total defined states: {q0, q1, qd}\n");
    printf("Since \"ε\" also occurs in the language (L), initial state is also one of the final states.\n");
    printf("Initial state: ->*q0\n");
    printf("Final states: *q0, *q1\n");
    printf("Dead state: qd\n");
    printf("Processing the string \"%s\":\n", input);

    if (len == 0)
    {
        printf("Empty string (ε). Staying in initial state ->*q0.\n");
        printf("The string \"ε\" is accepted by DFA.\n");
        return 0;
    }

    curr = q0;
    for (i = 0; i < len; i++)
    {
        enum states next = delta(curr, input[i]);
        printf("%s --- (%c) ---> %s\n", state_str[curr], input[i], state_str[next]);
        curr = next;
    }

    if (curr == q0 || curr == q1)
        printf("The string \"%s\" is accepted by DFA.\n", input);
    else
        printf("The string states towards dead state(qd), therefore \"%s\" is not accepted by the DFA.\n", input);

    return 0;
}
