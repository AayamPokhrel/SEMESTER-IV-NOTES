/*
 * Lab 6: PDA for wcw^r — Accepted by Empty Stack
 *
 * Language: { wcw^r | w in {0,1}* }
 *
 * PDA Definition:
 *   States          : { q0, q1, q2 }
 *   Input Alphabet  : { 0, 1, c }
 *   Stack Alphabet  : { 0, 1, Z0 }
 *   Start State     : q0
 *   Start Stack Sym : Z0
 *   Acceptance      : By Empty Stack
 *
 * Transition Table:
 * +-------+-------+-----------+-------------------------+
 * | State | Input | Stack Top | (Next State, Stack New) |
 * +-------+-------+-----------+-------------------------+
 * | ->q0  |   0   |    Z0     |        (q0, 0Z0)        |
 * |   q0  |   0   |     0     |        (q0, 00)          |
 * |   q0  |   1   |     0     |        (q0, 10)          |
 * |   q0  |   1   |    Z0     |        (q0, 1Z0)         |
 * |   q0  |   1   |     1     |        (q0, 11)          |
 * |   q0  |   0   |     1     |        (q0, 01)          |
 * |   q0  |   c   |    Z0     |        (q1, Z0)          |
 * |   q0  |   c   |     0     |        (q1, 0)           |
 * |   q0  |   c   |     1     |        (q1, 1)           |
 * |   q1  |   0   |     0     |        (q1, e)           |
 * |   q1  |   1   |     1     |        (q1, e)           |
 * |   q1  |   e   |    Z0     |        (q2, e)           |
 * +-------+-------+-----------+-------------------------+
 *
 * Difference from Lab 5: epsilon transition pops Z0 (empties the stack).
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

int main(void) {
    char input[256];
    int  i, len;
    int  state = 0;   /* 0=q0, 1=q1, 2=q2 */

    printf("=====================================================\n");
    printf("  PDA: wcw^r — Accepted by Empty Stack\n");
    printf("=====================================================\n\n");

    printf("PDA Definition:\n");
    printf("  States         : { q0, q1, q2 }\n");
    printf("  Input Alphabet : { 0, 1, c }\n");
    printf("  Stack Alphabet : { 0, 1, Z0 }\n");
    printf("  Start State    : ->q0\n");
    printf("  Stack Start    : Z0\n");
    printf("  Acceptance     : By Empty Stack\n\n");

    printf("Transition Table:\n");
    printf("+-------+-------+-----------+-------------------------+\n");
    printf("| State | Input | Stack Top | (Next State, Stack New) |\n");
    printf("+-------+-------+-----------+-------------------------+\n");
    printf("| ->q0  |   0   |    Z0     |        (q0, 0Z0)        |\n");
    printf("|   q0  |   0   |     0     |        (q0, 00)          |\n");
    printf("|   q0  |   1   |     0     |        (q0, 10)          |\n");
    printf("|   q0  |   1   |    Z0     |        (q0, 1Z0)         |\n");
    printf("|   q0  |   1   |     1     |        (q0, 11)          |\n");
    printf("|   q0  |   0   |     1     |        (q0, 01)          |\n");
    printf("|   q0  |   c   |    Z0     |        (q1, Z0)          |\n");
    printf("|   q0  |   c   |     0     |        (q1, 0)           |\n");
    printf("|   q0  |   c   |     1     |        (q1, 1)           |\n");
    printf("|   q1  |   0   |     0     |        (q1, e)           |\n");
    printf("|   q1  |   1   |     1     |        (q1, e)           |\n");
    printf("|   q1  |   e   |    Z0     |        (q2, e)           |\n");
    printf("+-------+-------+-----------+-------------------------+\n\n");

    printf("Enter a string (alphabet {0, 1, c}): ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != '0' && input[i] != '1' && input[i] != 'c') {
            printf("Error: Invalid character '%c'. Only 0, 1, and c are allowed.\n",
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
            if (inp == '0' && st == 'Z') {
                printf("  %sq0 --- (0, Z0/0Z0) ---> q0", arrow);
                push('0');
            } else if (inp == '0' && st == '0') {
                printf("  %sq0 --- (0, 0/00)   ---> q0", arrow);
                push('0');
            } else if (inp == '1' && st == '0') {
                printf("  %sq0 --- (1, 0/10)   ---> q0", arrow);
                push('1');
            } else if (inp == '1' && st == 'Z') {
                printf("  %sq0 --- (1, Z0/1Z0) ---> q0", arrow);
                push('1');
            } else if (inp == '1' && st == '1') {
                printf("  %sq0 --- (1, 1/11)   ---> q0", arrow);
                push('1');
            } else if (inp == '0' && st == '1') {
                printf("  %sq0 --- (0, 1/01)   ---> q0", arrow);
                push('0');
            } else if (inp == 'c') {
                printf("  %sq0 --- (c, %s/%s)%s ---> q1",
                       arrow, sym(st), sym(st),
                       (st == 'Z') ? "  " : "   ");
                state = 1;
            } else {
                printf("  No valid transition for (q0, %c, %s)! REJECTED.\n",
                       inp, sym(st));
                accepted = 0; break;
            }
        } else if (state == 1) {
            if (inp == '0' && st == '0') {
                printf("    q1 --- (0, 0/e)    ---> q1");
                pop_s();
            } else if (inp == '1' && st == '1') {
                printf("    q1 --- (1, 1/e)    ---> q1");
                pop_s();
            } else {
                printf("  No valid transition for (q1, %c, %s)! REJECTED.\n",
                       inp, sym(st));
                accepted = 0; break;
            }
        }

        if (accepted) {
            printf("    Stack: "); printStack(); printf("\n");
        }
    }

    /* Epsilon transition: (q1, e, Z0) -> (q2, e)  — pop Z0, empty stack */
    if (accepted && state == 1 && peek() == 'Z') {
        printf("    q1 --- (e, Z0/e)   ---> q2 ");
        pop_s();
        state = 2;
        printf("    Stack: "); printStack(); printf("\n");
    }

    printf("\n--- Result ---\n");
    printf("Final State : q%d\n", state);
    printf("Stack       : "); printStack(); printf("\n");

    if (state == 2 && stackEmpty())
        printf("\nThe string \"%s\" is ACCEPTED by the PDA (by empty stack).\n"
               "The stack is EMPTY.\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n"
               "The stack is NOT empty.\n", input);

    return 0;
}
