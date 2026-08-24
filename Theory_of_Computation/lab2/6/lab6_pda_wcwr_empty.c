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

int isEmpty(Stack *s) {
    return s->top < 0;
}

int isFull(Stack *s) {
    return s->top >= MAX_STACK - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

void display(Stack *s) {
    int i;
    if (isEmpty(s)) {
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

/* ==================== Helper ==================== */

const char *sym(char c) {
    if (c == 'Z') return "Z0";
    static char buf[2] = {0};
    buf[0] = c;
    return buf;
}

/* ==================== Main ==================== */

int main(void) {
    char input[256];
    int  i, len;
    int  state = 0;
    Stack stk;

    stack_init(&stk);

    printf("PDA: wcw^r -- Accepted by Empty Stack\n");

    printf("PDA Definition:\n");
    printf("  States         : { q0, q1, q2 }\n");
    printf("  Input Alphabet : { 0, 1, c }\n");
    printf("  Stack Alphabet : { 0, 1, Z0 }\n");
    printf("  Start State    : ->q0\n");
    printf("  Stack Start    : Z0\n");
    printf("  Acceptance     : By Empty Stack\n\n");

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

    push(&stk, 'Z');
    state = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    printf("Initial Stack : ");
    display(&stk);
    printf("\n\n");

    int accepted = 1;

    for (i = 0; i < len; i++) {
        char inp = input[i];
        char st  = peek(&stk);
        const char *arrow = (i == 0) ? "->" : "  ";

        if (state == 0) {
            if (inp == '0' && st == 'Z') {
                printf("  %sq0 --- (0, Z0/0Z0) ---> q0", arrow);
                push(&stk, '0');
            } else if (inp == '0' && st == '0') {
                printf("  %sq0 --- (0, 0/00)   ---> q0", arrow);
                push(&stk, '0');
            } else if (inp == '1' && st == '0') {
                printf("  %sq0 --- (1, 0/10)   ---> q0", arrow);
                push(&stk, '1');
            } else if (inp == '1' && st == 'Z') {
                printf("  %sq0 --- (1, Z0/1Z0) ---> q0", arrow);
                push(&stk, '1');
            } else if (inp == '1' && st == '1') {
                printf("  %sq0 --- (1, 1/11)   ---> q0", arrow);
                push(&stk, '1');
            } else if (inp == '0' && st == '1') {
                printf("  %sq0 --- (0, 1/01)   ---> q0", arrow);
                push(&stk, '0');
            } else if (inp == 'c') {
                printf("  %sq0 --- (c, %s/%s)%s ---> q1",
                       arrow, sym(st), sym(st),
                       (st == 'Z') ? "  " : "   ");
                state = 1;
            } else {
                printf("  No valid transition for (q0, %c, %s)! REJECTED.\n",
                       inp, sym(st));
                accepted = 0;
                break;
            }
        } else if (state == 1) {
            if (inp == '0' && st == '0') {
                printf("    q1 --- (0, 0/ε)    ---> q1");
                pop(&stk);
            } else if (inp == '1' && st == '1') {
                printf("    q1 --- (1, 1/ε)    ---> q1");
                pop(&stk);
            } else {
                printf("  No valid transition for (q1, %c, %s)! REJECTED.\n",
                       inp, sym(st));
                accepted = 0;
                break;
            }
        }

        if (accepted) {
            printf("    Stack: ");
            display(&stk);
            printf("\n");
        }
    }

    if (accepted && state == 1 && peek(&stk) == 'Z') {
        printf("    q1 --- (ε, Z0/ε)   ---> q2 ");
        pop(&stk);
        state = 2;
        printf("    Stack: ");
        display(&stk);
        printf("\n");
    }

    printf("\n--- Result ---\n");
    printf("Final State : q%d\n", state);
    printf("Stack       : ");
    display(&stk);
    printf("\n");

    if (state == 2 && isEmpty(&stk))
        printf("\nThe string \"%s\" is ACCEPTED by the PDA (by empty stack).\n"
               "The stack is EMPTY.\n",
               input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n"
               "The stack is NOT empty.\n",
               input);

    return 0;
}
