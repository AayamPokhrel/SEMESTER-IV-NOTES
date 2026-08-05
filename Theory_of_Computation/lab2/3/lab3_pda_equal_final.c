#include <stdio.h>
#include <string.h>

#define MAX_STACK 1000

char stack[MAX_STACK];
int  top = -1;

void  push(char c)  { stack[++top] = c; }
char  pop_s(void)   { return (top >= 0) ? stack[top--] : '\0'; }
char  peek(void)    { return (top >= 0) ? stack[top]   : '\0'; }
int   stackEmpty(void) { return top < 0; }

void printStack(void) {
    int i;
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
    int  state = 0;

    printf("=====================================================\n");
    printf("  PDA: Equal number of 0's and 1's (Final State)\n");
    printf("=====================================================\n\n");

    printf("PDA Definition:\n");
    printf("  States         : { q0, q1 }\n");
    printf("  Input Alphabet : { 0, 1 }\n");
    printf("  Stack Alphabet : { 0, 1, Z0 }\n");
    printf("  Start State    : ->q0\n");
    printf("  Stack Start    : Z0\n");
    printf("  Final State    : *q1\n\n");

    printf("Enter a string of 0's and 1's: ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("Error: Invalid character '%c'. Only 0 and 1 are allowed.\n",
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

        if (state == 0) {
            if (inp == '0' && st == 'Z') {
                printf("  %sq0 --- (0, Z0/0Z0) ---> q0", (i == 0) ? "->" : "  ");
                push('0');
            } else if (inp == '0' && st == '0') {
                printf("  %sq0 --- (0, 0/00)   ---> q0", (i == 0) ? "->" : "  ");
                push('0');
            } else if (inp == '1' && st == '0') {
                printf("  %sq0 --- (1, 0/ε)    ---> q0", (i == 0) ? "->" : "  ");
                pop_s();
            } else if (inp == '1' && st == 'Z') {
                printf("  %sq0 --- (1, Z0/1Z0) ---> q0", (i == 0) ? "->" : "  ");
                push('1');
            } else if (inp == '1' && st == '1') {
                printf("  %sq0 --- (1, 1/11)   ---> q0", (i == 0) ? "->" : "  ");
                push('1');
            } else if (inp == '0' && st == '1') {
                printf("  %sq0 --- (0, 1/ε)    ---> q0", (i == 0) ? "->" : "  ");
                pop_s();
            } else {
                printf("  No valid transition for (q0, %c, %s)! REJECTED.\n",
                       inp, sym(st));
                accepted = 0; break;
            }
            printf("    Stack: "); printStack(); printf("\n");
        }
    }

    if (accepted && state == 0 && peek() == 'Z') {
        printf("    q0 --- (ε, Z0/Z0)  ---> *q1");
        state = 1;
        printf("    Stack: "); printStack(); printf("\n");
    }

    printf("\n--- Result ---\n");
    printf("Final State     : %s\n", (state == 1) ? "*q1" : "q0");
    printf("Remaining Stack : "); printStack(); printf("\n");

    if (state == 1)
        printf("\nThe string \"%s\" is ACCEPTED by the PDA (by final state).\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n", input);

    return 0;
}
