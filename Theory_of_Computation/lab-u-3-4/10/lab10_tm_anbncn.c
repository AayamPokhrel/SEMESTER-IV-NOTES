/*
 * Lab 10: Turing Machine for a^n b^n c^n, n >= 1
 *
 * TM Definition:
 *   States          : { q0, q1, q2, q3, q4, q5, q6 }
 *   Input Alphabet  : { a, b, c }
 *   Tape Alphabet   : { a, b, c, X, Y, Z, B }
 *   Start State     : q0
 *   Accept State    : *q6
 *   Blank Symbol    : B
 *
 * Algorithm:
 *   1. In q0, find leftmost unmarked 'a', replace with X, go to q1.
 *   2. In q1, scan right past a's and Y's to find leftmost unmarked 'b',
 *      replace with Y, go to q2.
 *   3. In q2, scan right past b's and Z's to find leftmost unmarked 'c',
 *      replace with Z, go to q3.
 *   4. In q3, scan left all the way back to X, go to q0 and repeat.
 *   5. In q0, if current symbol is Y (all a's marked), go to q4.
 *   6. In q4, scan right past Y's to find Z. Go to q5.
 *   7. In q5, scan right past Z's. If blank B found, accept (*q6).
 *
 * Transition Table:
 * +-------+-------+---------------------------+
 * | State | Input | (Next State, Write, Move)  |
 * +-------+-------+---------------------------+
 * | ->q0  |   a   |        (q1, X, R)          |
 * |   q0  |   Y   |        (q4, Y, R)          |
 * |   q1  |   a   |        (q1, a, R)          |
 * |   q1  |   Y   |        (q1, Y, R)          |
 * |   q1  |   b   |        (q2, Y, R)          |
 * |   q2  |   Z   |        (q2, Z, R)          |
 * |   q2  |   b   |        (q2, b, R)          |
 * |   q2  |   c   |        (q3, Z, L)          |
 * |   q3  |   Z   |        (q3, Z, L)          |
 * |   q3  |   b   |        (q3, b, L)          |
 * |   q3  |   a   |        (q3, a, L)          |
 * |   q3  |   Y   |        (q3, Y, L)          |
 * |   q3  |   X   |        (q0, X, R)          |
 * |   q4  |   Y   |        (q4, Y, R)          |
 * |   q4  |   Z   |        (q5, Z, R)          |
 * |   q5  |   Z   |        (q5, Z, R)          |
 * |   q5  |   B   |       (*q6, B, R)          |
 * +-------+-------+---------------------------+
 */

#include <stdio.h>
#include <string.h>

#define TAPE_SIZE 500

void printTape(char tape[], int head, int lo, int hi) {
    int i;
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
    printf("  Turing Machine for a^n b^n c^n, n >= 1\n");
    printf("=====================================================\n\n");

    printf("TM Definition:\n");
    printf("  States         : { q0, q1, q2, q3, q4, q5, q6 }\n");
    printf("  Input Alphabet : { a, b, c }\n");
    printf("  Tape Alphabet  : { a, b, c, X, Y, Z, B }\n");
    printf("  Start State    : ->q0\n");
    printf("  Accept State   : *q6\n");
    printf("  Blank Symbol   : B\n\n");

    printf("Transition Table:\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| State | Input | (Next State, Write, Move) |\n");
    printf("+-------+-------+---------------------------+\n");
    printf("| ->q0  |   a   |        (q1, X, R)         |\n");
    printf("|   q0  |   Y   |        (q4, Y, R)         |\n");
    printf("|   q1  |   a   |        (q1, a, R)         |\n");
    printf("|   q1  |   Y   |        (q1, Y, R)         |\n");
    printf("|   q1  |   b   |        (q2, Y, R)         |\n");
    printf("|   q2  |   Z   |        (q2, Z, R)         |\n");
    printf("|   q2  |   b   |        (q2, b, R)         |\n");
    printf("|   q2  |   c   |        (q3, Z, L)         |\n");
    printf("|   q3  |   Z   |        (q3, Z, L)         |\n");
    printf("|   q3  |   b   |        (q3, b, L)         |\n");
    printf("|   q3  |   a   |        (q3, a, L)         |\n");
    printf("|   q3  |   Y   |        (q3, Y, L)         |\n");
    printf("|   q3  |   X   |        (q0, X, R)         |\n");
    printf("|   q4  |   Y   |        (q4, Y, R)         |\n");
    printf("|   q4  |   Z   |        (q5, Z, R)         |\n");
    printf("|   q5  |   Z   |        (q5, Z, R)         |\n");
    printf("|   q5  |   B   |       (*q6, B, R)         |\n");
    printf("+-------+-------+---------------------------+\n\n");

    printf("Enter a string (alphabet {a, b, c}): ");
    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b' && input[i] != 'c') {
            printf("Error: Invalid character '%c'. Only 'a', 'b', and 'c' are allowed.\n",
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

    int maxSteps = len * len * 2 + 200;

    while (step < maxSteps) {
        char rd = tape[head];
        int  newState = -1;
        char wr = rd;
        int  mv = 0;
        step++;

        /* Transition function — exact from table */
        if      (state == 0 && rd == 'a') { newState = 1; wr = 'X'; mv = +1; }
        else if (state == 0 && rd == 'Y') { newState = 4; wr = 'Y'; mv = +1; }
        else if (state == 1 && rd == 'a') { newState = 1; wr = 'a'; mv = +1; }
        else if (state == 1 && rd == 'Y') { newState = 1; wr = 'Y'; mv = +1; }
        else if (state == 1 && rd == 'b') { newState = 2; wr = 'Y'; mv = +1; }
        else if (state == 2 && rd == 'Z') { newState = 2; wr = 'Z'; mv = +1; }
        else if (state == 2 && rd == 'b') { newState = 2; wr = 'b'; mv = +1; }
        else if (state == 2 && rd == 'c') { newState = 3; wr = 'Z'; mv = -1; }
        else if (state == 3 && rd == 'Z') { newState = 3; wr = 'Z'; mv = -1; }
        else if (state == 3 && rd == 'b') { newState = 3; wr = 'b'; mv = -1; }
        else if (state == 3 && rd == 'a') { newState = 3; wr = 'a'; mv = -1; }
        else if (state == 3 && rd == 'Y') { newState = 3; wr = 'Y'; mv = -1; }
        else if (state == 3 && rd == 'X') { newState = 0; wr = 'X'; mv = +1; }
        else if (state == 4 && rd == 'Y') { newState = 4; wr = 'Y'; mv = +1; }
        else if (state == 4 && rd == 'Z') { newState = 5; wr = 'Z'; mv = +1; }
        else if (state == 5 && rd == 'Z') { newState = 5; wr = 'Z'; mv = +1; }
        else if (state == 5 && rd == 'B') { newState = 6; wr = 'B'; mv = +1; accepted = 1; }
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
