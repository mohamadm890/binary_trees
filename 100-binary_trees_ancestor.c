#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *@tree: pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second) {
    /* Base cases */
    if (first == NULL || second == NULL)
        return NULL;
    
    if (first == second)
        return (binary_tree_t *)first;
    binary_tree_t *left_ancestor = binary_trees_ancestor(first->parent, second);
    binary_tree_t *right_ancestor = binary_trees_ancestor(first, second->parent);

    if (left_ancestor && right_ancestor)
        return (binary_tree_t *)first;
    if (left_ancestor == NULL)
        return right_ancestor;
    return left_ancestor;
}
