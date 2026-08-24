#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==================== Stack ADT ==================== */

#define MAX_STACK 1000

typedef struct {
    char data[MAX_STACK];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

int stack_isEmpty(Stack *s) {
    return s->top < 0;
}

int stack_isFull(Stack *s) {
    return s->top >= MAX_STACK - 1;
}

void stack_push(Stack *s, char c) {
    if (stack_isFull(s)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char stack_pop(Stack *s) {
    if (stack_isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char stack_peek(Stack *s) {
    if (stack_isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

void stack_display(Stack *s) {
    int i;
    if (stack_isEmpty(s)) {
        printf("[EMPTY]");
        return;
    }
    printf("[");
    for (i = 0; i <= s->top; i++) {
        if (s->data[i] == 'Z')
            printf("Z0");
        else
            printf("%c", s->data[i]);
        if (i < s->top)
            printf(", ");
    }
    printf("]");
}

/* ==================== Helpers ==================== */

const char *sym(char c) {
    if (c == 'Z') return "Z0";
    static char buf[2] = {0};
    buf[0] = c;
    return buf;
}

const char *stName(int s) {
    switch (s) {
        case 0:  return "q0";
        case 1:  return "q1";
        case 2:  return "*q2";
        default: return "??";
    }
}

/* ==================== Main ==================== */

int main(void) {
    char input[256];
    int  i, len;
    int  state = 0;
    Stack stk;

    stack_init(&stk);

    printf("PDA: a^n b^n (n >= 1) -- Accepted by Final State\n");

    printf("PDA Definition:\n");
    printf("  States         : { q0, q1, q2 }\n");
    printf("  Input Alphabet : { a, b }\n");
    printf("  Stack Alphabet : { a, Z0 }\n");
    printf("  Start State    : ->q0\n");
    printf("  Stack Start    : Z0\n");
    printf("  Final State    : *q2\n\n");

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

    stack_push(&stk, 'Z');
    state = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    printf("Initial Stack : ");
    stack_display(&stk);
    printf("\n\n");

    int accepted = 1;

    for (i = 0; i < len; i++) {
        char inp = input[i];
        char st  = stack_peek(&stk);
        const char *arrow = (i == 0) ? "->" : "  ";

        if (state == 0) {
            if (inp == 'a' && st == 'Z') {
                printf("  %sq0 --- (a, Z0/aZ0) ---> q0", arrow);
                stack_push(&stk, 'a');
            } else if (inp == 'a' && st == 'a') {
                printf("  %sq0 --- (a, a/aa)   ---> q0", arrow);
                stack_push(&stk, 'a');
            } else if (inp == 'b' && st == 'a') {
                printf("  %sq0 --- (b, a/ε)    ---> q1", arrow);
                stack_pop(&stk);
                state = 1;
            } else {
                printf("  No valid transition for (%s, %c, %s)! REJECTED.\n",
                       stName(state), inp, sym(st));
                accepted = 0;
                break;
            }
        } else if (state == 1) {
            if (inp == 'b' && st == 'a') {
                printf("    q1 --- (b, a/ε)    ---> q1");
                stack_pop(&stk);
            } else {
                printf("  No valid transition for (%s, %c, %s)! REJECTED.\n",
                       stName(state), inp, sym(st));
                accepted = 0;
                break;
            }
        }

        if (accepted) {
            printf("    Stack: ");
            stack_display(&stk);
            printf("\n");
        }
    }

    if (accepted && state == 1 && stack_peek(&stk) == 'Z') {
        printf("    q1 --- (ε, Z0/Z0)  ---> *q2");
        state = 2;
        printf("    Stack: ");
        stack_display(&stk);
        printf("\n");
    }

    printf("\n--- Result ---\n");
    printf("Final State     : %s\n", stName(state));
    printf("Remaining Stack : ");
    stack_display(&stk);
    printf("\n");

    if (state == 2)
        printf("\nThe string \"%s\" is ACCEPTED by the PDA (by final state *q2).\n",
               input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n", input);

    return 0;
}
