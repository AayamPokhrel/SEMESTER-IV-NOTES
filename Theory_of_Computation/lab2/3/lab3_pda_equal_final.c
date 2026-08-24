#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 1000

typedef struct {
  char data[MAX_STACK];
  int top;
} Stack;

void stack_init(Stack *s) { s->top = -1; }

int stack_isEmpty(Stack *s) { return s->top < 0; }

int stack_isFull(Stack *s) { return s->top >= MAX_STACK - 1; }

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

/* ==================== Helper ==================== */

const char *sym(char c) {
  if (c == 'Z')
    return "Z0";
  static char buf[2] = {0};
  buf[0] = c;
  return buf;
}

/* ==================== Main ==================== */

int main(void) {
  char input[256];
  int i, len;
  int state = 0;
  Stack stk;

  stack_init(&stk);

  printf("PDA: Equal number of 0's and 1's (Final State)\n");

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
    char st = stack_peek(&stk);

    if (state == 0) {
      if (inp == '0' && st == 'Z') {
        printf("  %sq0 --- (0, Z0/0Z0) ---> q0", (i == 0) ? "->" : "  ");
        stack_push(&stk, '0');
      } else if (inp == '0' && st == '0') {
        printf("  %sq0 --- (0, 0/00)   ---> q0", (i == 0) ? "->" : "  ");
        stack_push(&stk, '0');
      } else if (inp == '1' && st == '0') {
        printf("  %sq0 --- (1, 0/ε)    ---> q0", (i == 0) ? "->" : "  ");
        stack_pop(&stk);
      } else if (inp == '1' && st == 'Z') {
        printf("  %sq0 --- (1, Z0/1Z0) ---> q0", (i == 0) ? "->" : "  ");
        stack_push(&stk, '1');
      } else if (inp == '1' && st == '1') {
        printf("  %sq0 --- (1, 1/11)   ---> q0", (i == 0) ? "->" : "  ");
        stack_push(&stk, '1');
      } else if (inp == '0' && st == '1') {
        printf("  %sq0 --- (0, 1/ε)    ---> q0", (i == 0) ? "->" : "  ");
        stack_pop(&stk);
      } else {
        printf("  No valid transition for (q0, %c, %s)! REJECTED.\n", inp,
               sym(st));
        accepted = 0;
        break;
      }
      printf("    Stack: ");
      stack_display(&stk);
      printf("\n");
    }
  }

  if (accepted && state == 0 && stack_peek(&stk) == 'Z') {
    printf("    q0 --- (ε, Z0/Z0)  ---> *q1");
    state = 1;
    printf("    Stack: ");
    stack_display(&stk);
    printf("\n");
  }

  printf("\n--- Result ---\n");
  printf("Final State     : %s\n", (state == 1) ? "*q1" : "q0");
  printf("Remaining Stack : ");
  stack_display(&stk);
  printf("\n");

  if (state == 1)
    printf("\nThe string \"%s\" is ACCEPTED by the PDA (by final state).\n",
           input);
  else
    printf("\nThe string \"%s\" is NOT ACCEPTED by the PDA.\n", input);

  return 0;
}
