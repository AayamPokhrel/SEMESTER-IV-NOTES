/*
 * Lab 7: Turing Machine for a^n b^n, n >= 1
 *
 * TM Definition:
 *   States          : { q0, q1, q2, q3, q4 }
 *   Input Alphabet  : { a, b }
 *   Tape Alphabet   : { a, b, X, Y, B }
 *   Start State     : q0
 *   Accept State    : *q4
 *   Blank Symbol    : B
 *
 * Algorithm: Mark leftmost unmarked 'a' with 'X', scan right
 *            to find leftmost unmarked 'b' and mark it with 'Y',
 *            scan left back to the 'X', move right and repeat.
 *
 * Transition Table:
 * +-------+-------+---------------------------+
 * | State | Input | (Next State, Write, Move)  |
 * +-------+-------+---------------------------+
 * | ->q0  |   a   |        (q1, X, R)          |
 * |   q0  |   Y   |        (q3, Y, R)          |
 * |   q1  |   Y   |        (q1, Y, R)          |
 * |   q1  |   a   |        (q1, a, R)          |
 * |   q1  |   b   |        (q2, Y, L)          |
 * |   q2  |   Y   |        (q2, Y, L)          |
 * |   q2  |   a   |        (q2, a, L)          |
 * |   q2  |   X   |        (q0, X, R)          |
 * |   q3  |   Y   |        (q3, Y, R)          |
 * |   q3  |   B   |       (*q4, B, R)          |
 * +-------+-------+---------------------------+
 */

#include <stdio.h>
#include <string.h>

#define TAPE_SIZE 500

/* Print tape with head position highlighted */
void printTape(char tape[], int head, int left, int right) {
    int i;
    /* Find actual bounds of non-blank tape */
    int lo = left, hi = right;
    while (lo > 0     && tape[lo] == 'B') lo++;
    while (hi < TAPE_SIZE - 1 && tape[hi] == 'B') hi--;
    if (lo > head) lo = head;
    if (hi < head) hi = head;
    /* Show a little padding */
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
        case 4: return "*q4";
        default: return "??";
    }
}

int main(void) {
    char input[256];
    char tape[TAPE_SIZE];
    int  head, state, len, i, step;
    int  accepted;

    printf("=====================================================\n");
    printf("  Turing Machine for a^n b^n, n >= 1\n");
    printf("=====================================================\n\n");

    printf("TM Definition:\n");
    printf("  States         : { q0, q1, q2, q3, q4 }\n");
    printf("  Input Alphabet : { a, b }\n");
    printf("  Tape Alphabet  : { a, b, X, Y, B }\n");
    printf("  Start State    : ->q0\n");
    printf("  Accept State   : *q4\n");
    printf("  Blank Symbol   : B\n\n");

    printf("Transition Table:\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| State | Input | (Next State, Write, Move) |\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| ->q0  |   a   |        (q1, X, R)         |\n");
    printf("|   q0  |   Y   |        (q3, Y, R)         |\n");
    printf("|   q1  |   Y   |        (q1, Y, R)         |\n");
    printf("|   q1  |   a   |        (q1, a, R)         |\n");
    printf("|   q1  |   b   |        (q2, Y, L)         |\n");
    printf("|   q2  |   Y   |        (q2, Y, L)         |\n");
    printf("|   q2  |   a   |        (q2, a, L)         |\n");
    printf("|   q2  |   X   |        (q0, X, R)         |\n");
    printf("|   q3  |   Y   |        (q3, Y, R)         |\n");
    printf("|   q3  |   B   |       (*q4, B, R)         |\n");
    printf("+-------+-------+---------------------------+\n\n");

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

    /* Initialize tape */
    memset(tape, 'B', TAPE_SIZE);
    head = 10;  /* start with some left padding */
    for (i = 0; i < len; i++)
        tape[head + i] = input[i];

    state = 0;  /* q0 */
    step  = 0;
    accepted = 0;

    printf("\n--- Processing String \"%s\" ---\n\n", input);
    printf("Initial State : ->q0\n");
    printf("Initial Head  : position %d\n", head);
    printTape(tape, head, head, head + len - 1);
    printf("\n");

    int maxSteps = len * len + 100;  /* safety limit */

    while (step < maxSteps) {
        char rd = tape[head];
        int  newState = -1;
        char wr = rd;
        int  mv = 0;  /* +1 = R, -1 = L */
        step++;

        /* Apply transitions */
        if (state == 0 && rd == 'a')      { newState = 1; wr = 'X'; mv = +1; }
        else if (state == 0 && rd == 'Y') { newState = 3; wr = 'Y'; mv = +1; }
        else if (state == 1 && rd == 'Y') { newState = 1; wr = 'Y'; mv = +1; }
        else if (state == 1 && rd == 'a') { newState = 1; wr = 'a'; mv = +1; }
        else if (state == 1 && rd == 'b') { newState = 2; wr = 'Y'; mv = -1; }
        else if (state == 2 && rd == 'Y') { newState = 2; wr = 'Y'; mv = -1; }
        else if (state == 2 && rd == 'a') { newState = 2; wr = 'a'; mv = -1; }
        else if (state == 2 && rd == 'X') { newState = 0; wr = 'X'; mv = +1; }
        else if (state == 3 && rd == 'Y') { newState = 3; wr = 'Y'; mv = +1; }
        else if (state == 3 && rd == 'B') { newState = 4; wr = 'B'; mv = +1; accepted = 1; }
        else {
            /* No valid transition — halt and reject */
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
        printTape(tape, head, 9, head + len + 2);
        printf("");

        if (accepted) break;
    }

    /* --- Result --- */
    printf("\n--- Result ---\n");
    printf("Final State : %s\n", stName(state));
    printf("Final Tape  :\n");
    printTape(tape, head, 9, head + len + 2);

    if (accepted)
        printf("\nThe string \"%s\" is ACCEPTED by the Turing Machine.\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the Turing Machine.\n", input);

    return 0;
}
