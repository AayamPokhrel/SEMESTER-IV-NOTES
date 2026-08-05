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

    printf("  Tape: < ");
    for (i = lo; i <= hi; i++) {
        if (i == head)
            printf("[%c]", tape[i]);
        else
            printf("%c", tape[i]);
        if (i < hi) printf(" <-> ");
    }
    printf(" >\n");
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
