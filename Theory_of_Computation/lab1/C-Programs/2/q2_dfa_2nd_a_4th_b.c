#include <stdio.h>
#include <string.h>

enum states { q0, q1, q2, q3, q4, qd };

const char *state_str[] = { "->q0", "  q1", "  q2", "  q3", " *q4", "  qd" };

enum states delta(enum states s, char ch)
{
    switch (s)
    {
        case q0:
            if (ch == 'a') return q1;
            if (ch == 'b') return q1;
            break;
        case q1:
            if (ch == 'a') return q2;
            if (ch == 'b') return qd;
            break;
        case q2:
            if (ch == 'a') return q3;
            if (ch == 'b') return q3;
            break;
        case q3:
            if (ch == 'a') return qd;
            if (ch == 'b') return q4;
            break;
        case q4:
            return q4;
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

    printf("Choose any string from alphabet Σ={a,b} of at least length 4:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    len = strlen(input);

    if (len < 4)
    {
        printf("Input string length must be >= 4.\n");
        return 1;
    }

    for (i = 0; i < len; i++)
    {
        if (input[i] != 'a' && input[i] != 'b')
        {
            printf("Cannot process string outside of Σ={a,b}.\n");
            return 1;
        }
    }

    printf("Total defined states: {q0, q1, q2, q3, q4, qd}\n");
    printf("Initial state: ->q0\n");
    printf("Final state: *q4\n");
    printf("Dead state: qd\n");
    printf("Processing the string \"%s\":\n", input);

    curr = q0;
    for (i = 0; i < len; i++)
    {
        enum states next = delta(curr, input[i]);
        printf("%s --- (%c) ---> %s\n", state_str[curr], input[i], state_str[next]);
        curr = next;
    }

    if (curr == q4)
        printf("The string \"%s\" is accepted by DFA.\n", input);
    else
        printf("The string states towards dead state(qd), therefore \"%s\" is not accepted by the DFA.\n", input);

    return 0;
}
