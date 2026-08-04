/*
 * Lab 2: Context Free Grammar for a^n b^n, n >= 1
 *
 * Grammar  G = (V, T, P, S):
 *   Variables (Non-terminals) V = { S }
 *   Terminals                 T = { a, b }
 *   Start Symbol              S
 *   Productions P:
 *     1) S -> aSb
 *     2) S -> ab
 *
 * The program creates LHS and RHS variables and terminals and
 * shows whether the user-given input can be derived from the
 * grammar or not.
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 *  Production structure
 * ============================================================ */
typedef struct {
    char lhs;           /* Left-Hand Side  (always 'S' here) */
    char rhs[8];        /* Right-Hand Side  ("aSb" or "ab")  */
} Production;

int main(void) {
    char input[256];
    int  i, j, n, len, valid;

    /* Define productions */
    Production P[2];
    P[0].lhs = 'S'; strcpy(P[0].rhs, "aSb");
    P[1].lhs = 'S'; strcpy(P[1].rhs, "ab");

    printf("================================================\n");
    printf("  Context Free Grammar for a^n b^n, n >= 1\n");
    printf("================================================\n\n");

    /* --- Display the grammar --- */
    printf("Grammar Definition  G = (V, T, P, S):\n");
    printf("  Variables (Non-terminals) V = { S }\n");
    printf("  Terminals                 T = { a, b }\n");
    printf("  Start Symbol              S\n\n");
    printf("  Productions P:\n");
    for (i = 0; i < 2; i++)
        printf("    Production %d :  %c -> %s   (LHS: %c,  RHS: %s)\n",
               i + 1, P[i].lhs, P[i].rhs, P[i].lhs, P[i].rhs);

    printf("\n  Left-Hand Side  (LHS) of all productions : S\n");
    printf("  Right-Hand Side (RHS) of all productions : aSb, ab\n\n");

    printf("Enter a string to check derivation: ");
    scanf("%s", input);
    len = strlen(input);

    /* --- Analysis --- */
    printf("\n--- Analysis ---\n");
    printf("Input string : \"%s\"\n", input);
    printf("Length       : %d\n", len);

    valid = 1;
    for (i = 0; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            printf("Error: '%c' at position %d is not in terminal set {a, b}.\n",
                   input[i], i);
            valid = 0; break;
        }
    }
    if (!valid || len == 0) {
        printf("\nResult: The string \"%s\" CANNOT be derived from the grammar.\n", input);
        return 0;
    }
    if (len % 2 != 0) {
        printf("Length is odd - cannot be derived from S -> aSb | ab.\n");
        printf("\nResult: The string \"%s\" CANNOT be derived from the grammar.\n", input);
        return 0;
    }

    n = len / 2;

    for (i = 0; i < n && valid; i++)
        if (input[i] != 'a') { valid = 0; break; }
    for (i = n; i < len && valid; i++)
        if (input[i] != 'b') { valid = 0; break; }

    if (!valid) {
        printf("String is not of the form a^n b^n.\n");
        printf("\nResult: The string \"%s\" CANNOT be derived from the grammar.\n", input);
        return 0;
    }

    printf("Identified : a^%d b^%d  (n = %d)\n\n", n, n, n);

    /* --- Derivation process --- */
    printf("--- Derivation Process (Leftmost Derivation) ---\n\n");

    for (i = 0; i <= n; i++) {
        printf("  Step %d:  ", i);
        if (i == 0) {
            printf("S");
        } else {
            for (j = 0; j < i; j++) printf("a");
            if (i < n) printf("S");
            for (j = 0; j < i; j++) printf("b");
        }
        printf("\n");

        if (i < n) {
            if (i < n - 1)
                printf("           Apply Production 1: S -> aSb\n");
            else
                printf("           Apply Production 2: S -> ab\n");
        }
    }

    /* Compact derivation chain */
    printf("\n  Derivation chain:\n  ");
    for (i = 0; i <= n; i++) {
        if (i == 0) {
            printf("S");
        } else {
            for (j = 0; j < i; j++) printf("a");
            if (i < n) printf("S");
            for (j = 0; j < i; j++) printf("b");
        }
        if (i < n) printf(" => ");
    }
    printf("\n");

    /* --- Result --- */
    printf("\n--- Result ---\n");
    printf("The string \"%s\" CAN be derived from the grammar.\n", input);
    printf("Number of derivation steps : %d\n", n);
    if (n > 1)
        printf("Productions used : %d time(s) S -> aSb,  1 time S -> ab\n", n - 1);
    else
        printf("Productions used : 1 time S -> ab\n");

    return 0;
}
