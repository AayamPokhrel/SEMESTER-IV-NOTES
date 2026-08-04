/*
 * Lab 1: Syntax Parse Tree for a^n b^n, n >= 1
 *
 * Grammar:
 *   S -> aSb   (Production 1)
 *   S -> ab    (Production 2)
 *
 * Non-terminals: { S }
 * Terminals:     { a, b }
 * Start Symbol:  S
 *
 * The program takes user input and shows whether the given
 * input is parsed by the grammar or not. It creates nodes
 * for non-terminal and terminal strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 *  Parse Tree Node Structure
 * ============================================================ */
typedef struct Node {
    char symbol;          /* 'S' for non-terminal, 'a'/'b' for terminal */
    int  is_terminal;     /* 1 = terminal, 0 = non-terminal             */
    struct Node *left;    /* left child  ('a')                          */
    struct Node *mid;     /* middle child (S, only for S -> aSb)        */
    struct Node *right;   /* right child ('b')                          */
} Node;

/* Create a new tree node */
Node *createNode(char symbol, int is_terminal) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed!\n"); exit(1); }
    n->symbol      = symbol;
    n->is_terminal = is_terminal;
    n->left = n->mid = n->right = NULL;
    return n;
}

/*
 * Recursively build the parse tree.
 *   n == 1  =>  S -> ab        (two  children: 'a', 'b')
 *   n >  1  =>  S -> aSb       (three children: 'a', S, 'b')
 */
Node *buildParseTree(int n) {
    Node *s = createNode('S', 0);
    if (n == 1) {
        s->left  = createNode('a', 1);
        s->right = createNode('b', 1);
    } else {
        s->left  = createNode('a', 1);
        s->mid   = buildParseTree(n - 1);
        s->right = createNode('b', 1);
    }
    return s;
}

/* Print the parse tree with a nice box-drawing style */
void printTree(Node *node, char *prefix, int is_last) {
    if (!node) return;

    printf("%s", prefix);
    printf("%s", is_last ? "+-- " : "|-- ");

    if (node->is_terminal)
        printf("'%c' (Terminal)\n", node->symbol);
    else
        printf("%c (Non-Terminal)\n", node->symbol);

    /* Build prefix for children */
    char new_prefix[512];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s",
             prefix, is_last ? "    " : "|   ");

    /* Count children to know which is last */
    int count = 0, idx = 0;
    if (node->left)  count++;
    if (node->mid)   count++;
    if (node->right) count++;

    if (node->left)  { idx++; printTree(node->left,  new_prefix, idx == count); }
    if (node->mid)   { idx++; printTree(node->mid,   new_prefix, idx == count); }
    if (node->right) { idx++; printTree(node->right, new_prefix, idx == count); }
}

/* Free all nodes */
void freeTree(Node *node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->mid);
    freeTree(node->right);
    free(node);
}

/* ============================================================
 *  Main
 * ============================================================ */
int main(void) {
    char input[256];
    int  i, n, len, valid;

    printf("==============================================\n");
    printf("  Syntax Parse Tree for a^n b^n, n >= 1\n");
    printf("==============================================\n\n");

    /* --- Grammar definition --- */
    printf("Grammar Definition:\n");
    printf("  Production 1 : S -> aSb\n");
    printf("  Production 2 : S -> ab\n");
    printf("  Non-Terminals: { S }\n");
    printf("  Terminals    : { a, b }\n");
    printf("  Start Symbol : S\n\n");

    printf("Enter a string: ");
    scanf("%s", input);
    len = strlen(input);

    /* --- Validation --- */
    printf("\n--- Validation ---\n");
    printf("Input string : \"%s\"\n", input);
    printf("Length       : %d\n", len);

    valid = 1;

    /* Check alphabet */
    for (i = 0; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            printf("Error: Invalid character '%c' at position %d. "
                   "Alphabet is {a, b}.\n", input[i], i);
            valid = 0; break;
        }
    }
    if (!valid || len == 0) {
        printf("\nResult: The string \"%s\" is NOT parsed by the grammar.\n", input);
        return 0;
    }
    if (len % 2 != 0) {
        printf("Odd length - cannot be of the form a^n b^n.\n");
        printf("\nResult: The string \"%s\" is NOT parsed by the grammar.\n", input);
        return 0;
    }

    n = len / 2;

    for (i = 0; i < n && valid; i++)
        if (input[i] != 'a') {
            printf("Expected 'a' at position %d, found '%c'.\n", i, input[i]);
            valid = 0;
        }
    for (i = n; i < len && valid; i++)
        if (input[i] != 'b') {
            printf("Expected 'b' at position %d, found '%c'.\n", i, input[i]);
            valid = 0;
        }

    if (!valid) {
        printf("\nResult: The string \"%s\" is NOT parsed by the grammar.\n", input);
        return 0;
    }

    printf("String is of the form a^%d b^%d  (n = %d, n >= 1 : OK)\n\n", n, n, n);

    /* --- Show derivation / parsing process --- */
    printf("--- Parsing Process (Leftmost Derivation) ---\n\n");

    for (i = 0; i < n; i++) {
        int j;
        /* Current sentential form */
        printf("  ");
        for (j = 0; j < i; j++) printf("a");
        printf("S");
        for (j = 0; j < i; j++) printf("b");

        printf("  =>  ");

        /* Result after applying production */
        for (j = 0; j <= i; j++) printf("a");
        if (i < n - 1) printf("S");
        for (j = 0; j <= i; j++) printf("b");

        printf("    (using S -> %s)\n", (i < n - 1) ? "aSb" : "ab");
    }

    /* --- Build and display the parse tree --- */
    printf("\n--- Parse Tree ---\n\n");
    {
        Node *root = buildParseTree(n);
        printTree(root, "", 1);

        printf("\n--- Result ---\n");
        printf("The string \"%s\" is PARSED by the grammar.\n", input);
        printf("Parse tree constructed with %d non-terminal node(s) "
               "and %d terminal node(s).\n", n, 2 * n);

        freeTree(root);
    }

    return 0;
}
