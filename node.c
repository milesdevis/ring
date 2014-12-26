#include <stdlib.h>
#include "node.h"

/* Initializes the first program root. Called before parsing. */
void initialize_program () {
    program_start = malloc (sizeof (root_t));
    program_start->next = NULL;
    last_successor = program_start;
}

/* Adds an expression tree to the current root, and creates a
 * new successor root. */
void
add_subtree (expr *block) {
    last_successor->block = block;
    root_t *r = malloc (sizeof (root_t));
    last_successor->next = r;
    last_successor = r;
}

/* Constructs arithmetic node from two expressions and a type */
node_arith_t*
make_arith_node (arith_type type, expr *op1, expr *op2) {
    node_arith_t *node = malloc (sizeof (node_arith_t));
    node->type = type;
    node->op1 = op1;
    node->op2 = op2;
    return node;
}

/* Constructs expressions with int literals */
expr*
expr_from_int (int val) {
    expr *e = malloc (sizeof (expr));
    e->body.val = val;
    e->type = INT;
    return e;
}

/* Constructs expressions with arithmetic nodes */
expr*
expr_from_arith (node_arith_t *node) {
    expr *e = malloc (sizeof (expr));
    e->type = ARITH;
    e->body.arith_val = node;
    return e;
}