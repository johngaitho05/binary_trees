#include "binary_trees.h"

/**
 * binary_tree_size - computes the number of a nod3 in a tree aka size
 * @tree: the tree to compute size for
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
