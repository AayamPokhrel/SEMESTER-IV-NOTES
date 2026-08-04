#include <stdio.h>
#include <string.h>

enum states { q0, q1, q2, NUM_STATES };

const char *state_names[] = { "q0", "q1", "*q2" };

#define Q0_BIT (1 << q0)
#define Q1_BIT (1 << q1)
#define Q2_BIT (1 << q2)

#define ACCEPTING Q2_BIT

/* NFA transition: returns bitmask of next states for a single state */
int nfa_delta(int state, char ch)
{
    switch (state)
    {
        case q0:
            if (ch == '0') return 0;               /* Φ */
            if (ch == '1') return Q1_BIT;           /* {q1} */
            break;
        case q1:
            if (ch == '0') return Q1_BIT | Q2_BIT;  /* {q1, q2} */
            if (ch == '1') return Q1_BIT;            /* {q1} */
            break;
        case q2:
            return 0;  /* Φ for both */
    }
    return 0;
}

/* Compute next state set from current state set */
int compute_next(int current_set, char ch)
{
    int next = 0;
    int s;
    for (s = 0; s < NUM_STATES; s++)
    {
        if (current_set & (1 << s))
            next |= nfa_delta(s, ch);
    }
    return next;
}

/* Print state set */
void print_state_set(int state_set)
{
    int s, first = 1;
    printf("{");
    if (state_set == 0)
    {
        printf("Φ");
    }
    else
    {
        for (s = 0; s < NUM_STATES; s++)
        {
            if (state_set & (1 << s))
            {
                if (!first) printf(", ");
                printf("%s", state_names[s]);
                first = 0;
            }
        }
    }
    printf("}");
}

int main()
{
    char input[100];
    int curr_set, i, len;

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

    printf("Initial state: ->q0\n");
    printf("Final state: *q2\n");
    printf("Processing the string \"%s\":\n", input);

    if (len == 0)
    {
        printf("Empty string (ε). Staying in initial state {q0}.\n");
        printf("The string \"ε\" is not accepted by the NFA.\n");
        return 0;
    }

    curr_set = Q0_BIT; /* Start in {q0} */
    for (i = 0; i < len; i++)
    {
        int next_set = compute_next(curr_set, input[i]);
        printf("  ");
        print_state_set(curr_set);
        printf(" --- (%c) ---> ", input[i]);
        print_state_set(next_set);
        printf("\n");
        curr_set = next_set;
    }

    if (curr_set & ACCEPTING)
        printf("The string \"%s\" is accepted by NFA.\n", input);
    else
        printf("The string \"%s\" is not accepted by the NFA.\n", input);

    return 0;
}
