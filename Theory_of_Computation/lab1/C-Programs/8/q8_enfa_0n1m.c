#include <stdio.h>
#include <string.h>

#define PHI -1

enum states { q0, q1, NUM_STATES };

const char *state_names[] = { "*q0", "*q1" };

/* 
 * EXPLICIT TRANSITION TABLE
 * delta \ alphabets | 0 | 1   | ε
 * ->*q0             | q0| phi | q1
 *   *q1             |phi| q1  | phi
 */
int transition_table[NUM_STATES][3] = {
    {  q0, PHI,  q1 }, /* State q0 (*q0) */
    { PHI,  q1, PHI }  /* State q1 (*q1) */
};

int main()
{
    int n, m;
    char input[200];
    int i, len;
    enum states curr = q0; /* Starts at q0 */
    int rejected = 0;
    int choice;

    printf("Language L = {0^n 1^m | n, m >= 0} over Σ={0,1}\n\n");
    
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
        printf("Enter any string from Σ={0,1} (leave empty for ε):\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
    }
    else if (choice == 2)
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
        if (n + m >= (int)sizeof(input))
        {
            printf("String too long.\n");
            return 1;
        }
        int idx = 0;
        for (i = 0; i < n; i++)
            input[idx++] = '0';
        for (i = 0; i < m; i++)
            input[idx++] = '1';
        input[idx] = '\0';
        
        if (idx == 0)
            printf("\nConstructed string: ε (empty string)\n");
        else
            printf("\nConstructed string: \"%s\"\n", input);
    }
    else
    {
        printf("Invalid choice.\n");
        return 1;
    }

    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Cannot process string outside of Σ={0,1}.\n");
            return 1;
        }
    }

    printf("\nTotal defined states: {*q0, *q1}\n");
    printf("Initial state: ->*q0\n");
    printf("Final states: *q0, *q1\n");
    
    if (len == 0)
        printf("Processing the string \"ε\":\n");
    else
        printf("Processing the string \"%s\":\n", input);

    for (i = 0; i < len; i++)
    {
        char ch = input[i];
        int c_idx = (ch == '0') ? 0 : 1;
        
        /* Look up the standard character transition in the table */
        int next = transition_table[curr][c_idx];

        if (next != PHI)
        {
            /* Valid direct transition found */
            printf("%s --- (%c) ---> %s\n", 
                   (curr == q0) ? "->*q0" : "*q1", ch, state_names[next]);
            curr = next;
        }
        else
        {
            /* Direct transition is PHI. Check if an epsilon jump can save the path */
            int eps_next = transition_table[curr][2];
            
            if (eps_next != PHI)
            {
                /* Take the epsilon jump */
                printf("%s --- (ε) ---> %s\n", 
                       (curr == q0) ? "->*q0" : "*q1", state_names[eps_next]);
                curr = eps_next;

                /* Retry the character from the new state */
                next = transition_table[curr][c_idx];
                
                if (next != PHI)
                {
                    printf("%s --- (%c) ---> %s\n", 
                           (curr == q0) ? "->*q0" : "*q1", ch, state_names[next]);
                    curr = next;
                }
                else
                {
                    /* Even after epsilon jump, it's a dead end */
                    printf("%s --- (%c) ---> Φ\n", 
                           (curr == q0) ? "->*q0" : "*q1", ch);
                    rejected = 1;
                    break;
                }
            }
            else
            {
                /* No epsilon jump available, true dead end */
                printf("%s --- (%c) ---> Φ\n", 
                       (curr == q0) ? "->*q0" : "*q1", ch);
                rejected = 1;
                break;
            }
        }
    }

    if (!rejected && (curr == q0 || curr == q1))
    {
        if (len == 0)
            printf("The empty string \"ε\" is accepted by the ε-NFA.\n");
        else
            printf("The string \"%s\" is accepted by the ε-NFA.\n", input);
    }
    else
    {
        printf("The string \"%s\" is not accepted by the ε-NFA.\n", input);
    }

    return 0;
}