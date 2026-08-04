/*
 * Lab 8: Turing Machine for ww^r, w in {0,1}*
 *
 * TM Definition:
 *   States          : { q0, q1, q2, q3, q4, q5, q6 }
 *   Input Alphabet  : { 0, 1 }
 *   Tape Alphabet   : { 0, 1, B }
 *   Start State     : q0
 *   Accept State    : *q6
 *   Blank Symbol    : B
 *
 * Algorithm: Read leftmost symbol, blank it, scan right to find
 *            last symbol. If it matches, blank it and go back
 *            to leftmost remaining symbol. Repeat.
 *
 * Transition Table:
 * +-------+-------+---------------------------+
 * | State | Input | (Next State, Write, Move)  |
 * +-------+-------+---------------------------+
 * | ->q0  |   0   |        (q1, B, R)          |
 * |   q0  |   1   |        (q4, B, R)          |
 * |   q0  |   B   |       (*q6, B, R)          |
 * |   q1  |   0   |        (q1, 0, R)          |
 * |   q1  |   1   |        (q1, 1, R)          |
 * |   q1  |   B   |        (q2, B, L)          |
 * |   q2  |   0   |        (q3, B, L)          |
 * |   q3  |   0   |        (q3, 0, L)          |
 * |   q3  |   1   |        (q3, 1, L)          |
 * |   q3  |   B   |        (q0, B, R)          |
 * |   q4  |   0   |        (q4, 0, R)          |
 * |   q4  |   1   |        (q4, 1, R)          |
 * |   q4  |   B   |        (q5, B, L)          |
 * |   q5  |   1   |        (q3, B, L)          |
 * +-------+-------+---------------------------+
 */

#include <stdio.h>
#include <string.h>

#define TAPE_SIZE 500

void printTape(char tape[], int head, int lo, int hi) {
    int i;
    /* Adjust bounds to include head and non-blank area */
    while (lo > 0 && tape[lo] == 'B') lo++;
    while (hi < TAPE_SIZE - 1 && tape[hi] == 'B') hi--;
    if (lo > head) lo = head;
    if (hi < head) hi = head;
    if (lo > 0) lo--;
    hi++;

    printf("  Tape: ");
    for (i = lo; i <= hi; i++) {
        if (i == head)
            printf("[%c]", tape[i]);
        else
            printf(" %c ", tape[i]);
    }
    printf("\n");
}

const char *stName(int s) {
    switch (s) {
        case 0: return "q0";
        case 1: return "q1";
        case 2: return "q2";
        case 3: return "q3";
        case 4: return "q4";
        case 5: return "q5";
        case 6: return "*q6";
        default: return "??";
    }
}

int main(void) {
    char input[256];
    char tape[TAPE_SIZE];
    int  head, state, len, i, step;
    int  accepted;

    printf("=====================================================\n");
    printf("  Turing Machine for ww^r, w in {0,1}*\n");
    printf("=====================================================\n\n");

    printf("TM Definition:\n");
    printf("  States         : { q0, q1, q2, q3, q4, q5, q6 }\n");
    printf("  Input Alphabet : { 0, 1 }\n");
    printf("  Tape Alphabet  : { 0, 1, B }\n");
    printf("  Start State    : ->q0\n");
    printf("  Accept State   : *q6\n");
    printf("  Blank Symbol   : B\n\n");

    printf("Transition Table:\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| State | Input | (Next State, Write, Move) |\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| ->q0  |   0   |        (q1, B, R)         |\n");
    printf("|   q0  |   1   |        (q4, B, R)         |\n");
    printf("|   q0  |   B   |       (*q6, B, R)         |\n");
    printf("|   q1  |   0   |        (q1, 0, R)         |\n");
    printf("|   q1  |   1   |        (q1, 1, R)         |\n");
    printf("|   q1  |   B   |        (q2, B, L)         |\n");
    printf("|   q2  |   0   |        (q3, B, L)         |\n");
    printf("|   q3  |   0   |        (q3, 0, L)         |\n");
    printf("|   q3  |   1   |        (q3, 1, L)         |\n");
    printf("|   q3  |   B   |        (q0, B, R)         |\n");
    printf("|   q4  |   0   |        (q4, 0, R)         |\n");
    printf("|   q4  |   1   |        (q4, 1, R)         |\n");
    printf("|   q4  |   B   |        (q5, B, L)         |\n");
    printf("|   q5  |   1   |        (q3, B, L)         |\n");
    printf("+-------+-------+---------------------------+\n\n");

    printf("Enter a string (alphabet {0, 1}): ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("Error: Invalid character '%c'. Only '0' and '1' are allowed.\n",
                   input[i]);
            return 0;
        }
    }

    /* Initialize tape */
    memset(tape, 'B', TAPE_SIZE);
    head = 10;
    for (i = 0; i < len; i++)
        tape[head + i] = input[i];

    state    = 0;
    step     = 0;
    accepted = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    printf("Initial Head  : position %d\n", head);
    printTape(tape, head, head, head + len - 1);
    printf("\n");

    int maxSteps = len * len + 200;

    while (step < maxSteps) {
        char rd = tape[head];
        int  newState = -1;
        char wr = rd;
        int  mv = 0;
        step++;

        /* Transition function */
        if      (state == 0 && rd == '0') { newState = 1; wr = 'B'; mv = +1; }
        else if (state == 0 && rd == '1') { newState = 4; wr = 'B'; mv = +1; }
        else if (state == 0 && rd == 'B') { newState = 6; wr = 'B'; mv = +1; accepted = 1; }
        else if (state == 1 && rd == '0') { newState = 1; wr = '0'; mv = +1; }
        else if (state == 1 && rd == '1') { newState = 1; wr = '1'; mv = +1; }
        else if (state == 1 && rd == 'B') { newState = 2; wr = 'B'; mv = -1; }
        else if (state == 2 && rd == '0') { newState = 3; wr = 'B'; mv = -1; }
        else if (state == 3 && rd == '0') { newState = 3; wr = '0'; mv = -1; }
        else if (state == 3 && rd == '1') { newState = 3; wr = '1'; mv = -1; }
        else if (state == 3 && rd == 'B') { newState = 0; wr = 'B'; mv = +1; }
        else if (state == 4 && rd == '0') { newState = 4; wr = '0'; mv = +1; }
        else if (state == 4 && rd == '1') { newState = 4; wr = '1'; mv = +1; }
        else if (state == 4 && rd == 'B') { newState = 5; wr = 'B'; mv = -1; }
        else if (state == 5 && rd == '1') { newState = 3; wr = 'B'; mv = -1; }
        else {
            printf("Step %d: %s --- (no transition for '%c') --- HALT\n",
                   step, stName(state), rd);
            break;
        }

        printf("  %s%s --- (%c/%c, %c) ---> %s",
               (step == 1) ? "->" : "  ",
               stName(state),
               rd, wr,
               (mv == +1) ? 'R' : 'L',
               stName(newState));

        tape[head] = wr;
        head += mv;
        state = newState;

        printf("    ");
        printTape(tape, head, 9, head + len + 5);
        printf("");

        if (accepted) break;
    }

    printf("\n--- Result ---\n");
    printf("Final State : %s\n", stName(state));
    printf("Final Tape  :\n");
    printTape(tape, head, 9, head + len + 5);

    if (accepted)
        printf("\nThe string \"%s\" is ACCEPTED by the Turing Machine.\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the Turing Machine.\n", input);

    return 0;
}
