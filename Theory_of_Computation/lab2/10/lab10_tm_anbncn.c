#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==================== Tape ADT (Doubly-Linked List) ==================== */

typedef struct TapeCell {
    char symbol;
    struct TapeCell *left;
    struct TapeCell *right;
} TapeCell;

typedef struct {
    TapeCell *head;  /* current head position on the tape */
} Tape;

TapeCell *tape_createCell(char symbol) {
    TapeCell *cell = (TapeCell *)malloc(sizeof(TapeCell));
    if (!cell) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    cell->symbol = symbol;
    cell->left   = NULL;
    cell->right  = NULL;
    return cell;
}

void tape_init(Tape *t, const char *input, int len) {
    int i;
    TapeCell *curr;

    if (len == 0) {
        t->head = tape_createCell('B');
        return;
    }

    t->head = tape_createCell(input[0]);
    curr = t->head;
    for (i = 1; i < len; i++) {
        TapeCell *cell = tape_createCell(input[i]);
        curr->right = cell;
        cell->left  = curr;
        curr = cell;
    }
}

char tape_read(Tape *t) {
    return t->head->symbol;
}

void tape_write(Tape *t, char c) {
    t->head->symbol = c;
}

void tape_moveRight(Tape *t) {
    if (t->head->right == NULL) {
        TapeCell *cell = tape_createCell('B');
        t->head->right = cell;
        cell->left = t->head;
    }
    t->head = t->head->right;
}

void tape_moveLeft(Tape *t) {
    if (t->head->left == NULL) {
        TapeCell *cell = tape_createCell('B');
        t->head->left = cell;
        cell->right = t->head;
    }
    t->head = t->head->left;
}

void tape_move(Tape *t, int direction) {
    if (direction == +1)
        tape_moveRight(t);
    else if (direction == -1)
        tape_moveLeft(t);
}

void tape_display(Tape *t) {
    TapeCell *start, *end, *curr;

    start = t->head;
    while (start->left != NULL)
        start = start->left;

    end = t->head;
    while (end->right != NULL)
        end = end->right;

    while (start != t->head && start->symbol == 'B' &&
           start->right != NULL && start->right->symbol == 'B' &&
           start->right != t->head)
        start = start->right;

    while (end != t->head && end->symbol == 'B' &&
           end->left != NULL && end->left->symbol == 'B' &&
           end->left != t->head)
        end = end->left;

    printf("  Tape: [ ");
    curr = start;
    while (1) {
        if (curr == t->head)
            printf("[%c]", curr->symbol);
        else
            printf("%c", curr->symbol);
        if (curr == end)
            break;
        printf(" - ");
        curr = curr->right;
    }
    printf(" ]\n");
}

void tape_free(Tape *t) {
    TapeCell *curr, *next;

    curr = t->head;
    while (curr->left != NULL)
        curr = curr->left;

    while (curr != NULL) {
        next = curr->right;
        free(curr);
        curr = next;
    }
    t->head = NULL;
}

/* ==================== State Helper ==================== */

const char *stName(int s) {
    switch (s) {
        case 0:  return "q0";
        case 1:  return "q1";
        case 2:  return "q2";
        case 3:  return "q3";
        case 4:  return "q4";
        case 5:  return "q5";
        case 6:  return "*q6";
        default: return "??";
    }
}

/* ==================== Main ==================== */

int main(void) {
    char input[256];
    int  len, i, step;
    int  state, accepted;
    Tape tp;

    printf("Turing Machine for a^n b^n c^n, n >= 1\n");

    printf("TM Definition:\n");
    printf("  States         : { q0, q1, q2, q3, q4, q5, q6 }\n");
    printf("  Input Alphabet : { a, b, c }\n");
    printf("  Tape Alphabet  : { a, b, c, X, Y, Z, B }\n");
    printf("  Start State    : ->q0\n");
    printf("  Accept State   : *q6\n");
    printf("  Blank Symbol   : B\n\n");

    printf("Enter a string (alphabet {a, b, c}): ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b' && input[i] != 'c') {
            printf("Error: Invalid character '%c'. Only 'a', 'b', and 'c' are "
                   "allowed.\n",
                   input[i]);
            return 0;
        }
    }

    tape_init(&tp, input, len);

    state    = 0;
    step     = 0;
    accepted = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    tape_display(&tp);
    printf("\n");

    int maxSteps = len * len * 2 + 200;

    while (step < maxSteps) {
        char rd = tape_read(&tp);
        int  newState = -1;
        char wr = rd;
        int  mv = 0;
        step++;

        if (state == 0 && rd == 'a') {
            newState = 1; wr = 'X'; mv = +1;
        } else if (state == 0 && rd == 'Y') {
            newState = 4; wr = 'Y'; mv = +1;
        } else if (state == 1 && rd == 'a') {
            newState = 1; wr = 'a'; mv = +1;
        } else if (state == 1 && rd == 'Y') {
            newState = 1; wr = 'Y'; mv = +1;
        } else if (state == 1 && rd == 'b') {
            newState = 2; wr = 'Y'; mv = +1;
        } else if (state == 2 && rd == 'Z') {
            newState = 2; wr = 'Z'; mv = +1;
        } else if (state == 2 && rd == 'b') {
            newState = 2; wr = 'b'; mv = +1;
        } else if (state == 2 && rd == 'c') {
            newState = 3; wr = 'Z'; mv = -1;
        } else if (state == 3 && rd == 'Z') {
            newState = 3; wr = 'Z'; mv = -1;
        } else if (state == 3 && rd == 'b') {
            newState = 3; wr = 'b'; mv = -1;
        } else if (state == 3 && rd == 'a') {
            newState = 3; wr = 'a'; mv = -1;
        } else if (state == 3 && rd == 'Y') {
            newState = 3; wr = 'Y'; mv = -1;
        } else if (state == 3 && rd == 'X') {
            newState = 0; wr = 'X'; mv = +1;
        } else if (state == 4 && rd == 'Y') {
            newState = 4; wr = 'Y'; mv = +1;
        } else if (state == 4 && rd == 'Z') {
            newState = 5; wr = 'Z'; mv = +1;
        } else if (state == 5 && rd == 'Z') {
            newState = 5; wr = 'Z'; mv = +1;
        } else if (state == 5 && rd == 'B') {
            newState = 6; wr = 'B'; mv = +1; accepted = 1;
        } else {
            printf("Step %d: %s --- (no transition for '%c') --- HALT\n",
                   step, stName(state), rd);
            break;
        }

        printf("  %s%s --- (%c/%c, %c) ---> %s",
               (step == 1) ? "->" : "  ",
               stName(state), rd, wr,
               (mv == +1) ? 'R' : 'L',
               stName(newState));

        tape_write(&tp, wr);
        tape_move(&tp, mv);
        state = newState;

        printf("    ");
        tape_display(&tp);

        if (accepted)
            break;
    }

    printf("\n--- Result ---\n");
    printf("Final State : %s\n", stName(state));
    printf("Final Tape  :\n");
    tape_display(&tp);

    if (accepted)
        printf("\nThe string \"%s\" is ACCEPTED by the Turing Machine.\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the Turing Machine.\n", input);

    tape_free(&tp);
    return 0;
}
