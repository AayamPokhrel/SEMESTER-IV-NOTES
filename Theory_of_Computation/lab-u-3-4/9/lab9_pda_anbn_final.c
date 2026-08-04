/*
 * Lab 9: PDA for a^n b^n (n >= 1) — Accepted by Final State
 *
 * PDA Definition:
 *   States          : { q0, q1, q2 }
 *   Input Alphabet  : { a, b }
 *   Stack Alphabet  : { a, Z0 }
 *   Start State     : q0
 *   Start Stack Sym : Z0
 *   Final State     : *q2
 *
 * Transition Table:
 * +-------+-------+-----------+-------------------------+
 * | State | Input | Stack Top | (Next State, Stack New) |
 * +-------+-------+-----------+-------------------------+
 * | ->q0  |   a   |    Z0     |        (q0, aZ0)        |
 * |   q0  |   a   |     a     |        (q0, aa)          |
 * |   q0  |   b   |     a     |        (q1, e)           |
 * |   q1  |   b   |     a     |        (q1, e)           |
 * |   q1  |   e   |    Z0     |       (*q2, Z0)          |
 * +-------+-------+-----------+-------------------------+
 *
 * Phase 1 (state q0): Push 'a' for every 'a' read.
 *                     On first 'b', pop one 'a', go to q1.
 * Phase 2 (state q1): Pop one 'a' for every 'b' read.
 *                     When stack has only Z0, move to *q2.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STACK 1000

char stack[MAX_STACK];
int  top = -1;

void  push(char c)     { stack[++top] = c; }
char  pop_s(void)      { return (top >= 0) ? stack[top--] : '\0'; }
char  peek(void)       { return (top >= 0) ? stack[top]   : '\0'; }
int   stackEmpty(void) { return top < 0; }

void printStack(void) {
    int i;
    if (top < 0) { printf("[EMPTY]"); return; }
    printf("[");
    for (i = 0; i <= top; i++) {
        if (stack[i] == 'Z') printf("Z0");
        else printf("%c", stack[i]);
        if (i < top) printf(", ");
    }
    printf("]");
}

const char *sym(char c) {
    if (c == 'Z') return "Z0";
    static char buf[2] = {0};
    buf[0] = c; return buf;
}

const char *stName(int s) {
    switch (s) {
        case 0: return "q0";
        case 1: return "q1";
        case 2: return "*q2";
        default: return "??";
    }
}

int main(void) {
    char input[256];
    int  i, len;
    int  state = 0;   /* 0=q0, 1=q1, 2=q2(accept) */

    printf("=====================================================\n");
    printf("  PDA: a^n b^n (n >= 1) — Accepted by Final State\n");
    printf("=====================================================\n\n");

    printf("PDA Definition:\n");
    printf("  States         : { q0, q1, q2 }\n");
    printf("  Input Alphabet : { a, b }\n");
    printf("  Stack Alphabet : { a, Z0 }\n");
    printf("  Start State    : ->q0\n");
    printf("  Stack Start    : Z0\n");
    printf("  Final State    : *q2\n\n");

    printf("Transition Table:\n");
    printf("+-------+-------+-----------+-------------------------+\n");
    printf("| State | Input | Stack Top | (Next State, Stack New) |\n");
    printf("+-------+-------+-----------+-------------------------+\n");
    printf("| ->q0  |   a   |    Z0     |        (q0, aZ0)        |\n");
    printf("|   q0  |   a   |     a     |        (q0, aa)          |\n");
    printf("|   q0  |   b   |     a     |        (q1, e)           |\n");
    printf("|   q1  |   b   |     a     |        (q1, e)           |\n");
    printf("|   q1  |   e   |    Z0     |       (*q2, Z0)          |\n");
    printf("+-------+-------+-----------+-------------------------+\n\n");

    printf("Enter a string (alphabet {a, b}): ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            printf("Error: Invalid character '%c'. Only 'a' and 'b' are allowed.\n",
                   input[i]);
            return 0;
        }
    }

    push('Z');
    state = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    printf("Initial Stack : "); printStack(); printf("\n\n");

    int accepted = 1;

    for (i = 0; i < len; i++) {
        char inp = input[i];
        char st  = peek();
        const char *arrow = (i == 0) ? "->" : "  ";

        if (state == 0) {
            if (inp == 'a' && st == 'Z') {
                /* (q0, a, Z0) -> (q0, aZ0) : push a */
                printf("  %sq0 --- (a, Z0/aZ0) ---> q0", arrow);
                push('a');
            } else if (inp == 'a' && st == 'a') {
                /* (q0, a, a) -> (q0, aa) : push a */
                printf("  %sq0 --- (a, a/aa)   ---> q0", arrow);
                push('a');
            } else if (inp == 'b' && st == 'a') {
                /* (q0, b, a) -> (q1, e) : pop a, go to q1 */
                printf("  %sq0 --- (b, a/e)    ---> q1", arrow);
                pop_s();
                state = 1;
            } else {
                printf("  No valid transition for (%s, %c, %s)! REJECTED.\n",
                       stName(state), inp, sym(st));
                accepted = 0; break;
            }
        } else if (state == 1) {
            if (inp == 'b' && st == 'a') {
                /* (q1, b, a) -> (q1, e) : pop a */
                printf("    q1 --- (b, a/e)    ---> q1");
                pop_s();
            } else {
                printf("  No valid transition for (%s, %c, %s)! REJECTED.\n",
                       stName(state), inp, sym(st));
                accepted = 0; break;
            }
        }

        if (accepted) {
            printf("    Stack: "); printStack(); printf("\n");
        }
    }

    /* Epsilon transition: (q1, e, Z0) -> (*q2, Z0) */
    if (accepted && state == 1 && peek() == 'Z') {
        printf("    q1 --- (e, Z0/Z0)  ---> *q2");
        state = 2;
        printf("    Stack: "); printStack(); printf("\n");
    }

    printf("\n--- Result ---\n");
    printf("Final State     : %s\n", stName(state));
    printf("Remaining Stack : "); printStack(); printf("\n");

    if (state == 2)
        printf("\nThe string \"%s\" is ACCEPTED by the PDA (by final state *q2).\n",
               input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n", input);

    return 0;
}
