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
    int choice;

    printf("Language L = {0^n 1^m | n, m >= 0} over Σ={0,1}\n\n");
    printf("Total defined states: {q0, q1}\n\n");

    printf("Choose input method:\n");
    printf("1. Enter custom string\n");
    printf("2. Generate string using n and m variables\n");
    printf("Enter choice (1 or 2): ");
    if (scanf("%d", &choice) != 1) return 1;

    /* Clear input buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (choice == 1)
    {
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

        if (len == 0)
            printf("\nCustom string: ε (empty string)\n");
        else
            printf("\nCustom string: \"%s\"\n", input);
    }
    else
    {
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
    }

    printf("\nInitial state: ->*q0\n");
    printf("Final states: *q0, *q1\n");
    printf("ε-transition: *q0 --- (ε) ---> *q1\n");

    /* Compute ε-closure of initial state */
    curr_set = epsilon_closure(Q0_BIT);

    if (len == 0)
    {
        printf("\nEmpty string (ε). Current state set: ");
        print_state_set(curr_set);
        printf("\n");
        printf("The string \"ε\" is accepted by ε-NFA.\n");
        return 0;
    }
    printf("\nProcessing the strings:\n");

    /* Show initial ε-closure: q0 --ε--> q1 always happens at the start */
    printf("*q0 --- (ε) ---> *q1\n");

    for (i = 0; i < len; i++)
    {
        /* Calculate the actual next state mathematically */
        int next_set = compute_next(curr_set, input[i]);

        /* Print transition traces from current state set */
        if (curr_set == (Q0_BIT | Q1_BIT))
        {
            if (input[i] == '0')
            {
                printf("*q0 --- (0) ---> *q0\n");
                printf("*q1 --- (0) ---> Φ\n");
                printf("*q0 --- (ε) ---> *q1\n");
            }
            else if (input[i] == '1')
            {
                printf("*q0 --- (1) ---> Φ\n");
                printf("*q1 --- (1) ---> *q1\n");
            }
        }
        else if (curr_set == Q0_BIT)
        {
            if (input[i] == '0')
            {
                printf("*q0 --- (0) ---> *q0\n");
                printf("*q0 --- (ε) ---> *q1\n");
            }
            else if (input[i] == '1')
            {
                printf("*q0 --- (1) ---> Φ\n");
            }
        }
        else if (curr_set == Q1_BIT)
        {
            if (input[i] == '0')
            {
                printf("*q1 --- (0) ---> Φ\n");
            }
            else if (input[i] == '1')
            {
                printf("*q1 --- (1) ---> *q1\n");
            }
        }
        else if (curr_set == 0)
        {
            printf("Φ --- (%c) ---> Φ\n", input[i]);
        }

        curr_set = next_set;
    }

    if (curr_set & ACCEPTING)
        printf("The string \"%s\" is accepted by the ε-NFA.\n", input);
    else
        printf("The string \"%s\" is not accepted by the ε-NFA.\n", input);

    return 0;
}