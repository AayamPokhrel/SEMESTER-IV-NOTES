#include <stdio.h>
#include <string.h>

enum states { q0, q1, NUM_STATES };

const char *state_names[] = { "*q0", "*q1" };

#define Q0_BIT (1 << q0)
#define Q1_BIT (1 << q1)

#define ACCEPTING (Q0_BIT | Q1_BIT)

/* Compute ε-closure of a state set */
/* ε-transitions: q0 --ε--> q1 */
int epsilon_closure(int state_set)
{
    if (state_set & Q0_BIT)
        state_set |= Q1_BIT;
    return state_set;
}

/* NFA transition (on input symbols only, no ε) */
int nfa_delta(int state, char ch)
{
    switch (state)
    {
        case q0:
            if (ch == '0') return Q0_BIT;  /* {q0} */
            if (ch == '1') return 0;       /* Φ */
            break;
        case q1:
            if (ch == '0') return 0;       /* Φ */
            if (ch == '1') return Q1_BIT;  /* {q1} */
            break;
    }
    return 0;
}

/* Compute next state set from current state set, then apply ε-closure */
int compute_next(int current_set, char ch)
{
    int next = 0;
    int s;
    for (s = 0; s < NUM_STATES; s++)
    {
        if (current_set & (1 << s))
            next |= nfa_delta(s, ch);
    }
    return epsilon_closure(next);
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
    int n, m;
    char input[200];
    int i, len, curr_set;

    printf("Language L = {0^n 1^m | n, m >= 0} over Σ={0,1}\n\n");

    printf("Enter value of n (number of 0s, n >= 0): ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid value for n. Must be >= 0.\n");
        return 1;
    }
    printf("Enter value of m (number of 1s, m >= 0): ");
    if (scanf("%d", &m) != 1 || m < 0)
    {
        printf("Invalid value for m. Must be >= 0.\n");
        return 1;
    }

    /* Construct string 0^n 1^m */
    len = n + m;
    if (len >= (int)sizeof(input))
    {
        printf("String too long.\n");
        return 1;
    }
    for (i = 0; i < n; i++)
        input[i] = '0';
    for (i = n; i < len; i++)
        input[i] = '1';
    input[len] = '\0';

    if (len == 0)
        printf("\nConstructed string: ε (empty string)\n");
    else
        printf("\nConstructed string: \"%s\"\n", input);

    printf("\nInitial state: ->*q0\n");
    printf("Final states: *q0, *q1\n");
    printf("ε-transition: *q0 --- (ε) ---> *q1\n");

    /* Compute ε-closure of initial state */
    curr_set = epsilon_closure(Q0_BIT);
    printf("ε-closure of initial state {*q0} = ");
    print_state_set(curr_set);
    printf("\n");

    if (len == 0)
    {
        printf("\nEmpty string (ε). Current state set: ");
        print_state_set(curr_set);
        printf("\n");
        printf("The string \"ε\" is accepted by ε-NFA.\n");
        return 0;
    }

    printf("\nProcessing the string \"%s\":\n", input);
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
        printf("The string \"%s\" is accepted by ε-NFA.\n", input);
    else
        printf("The string \"%s\" is not accepted by the ε-NFA.\n", input);

    return 0;
}
