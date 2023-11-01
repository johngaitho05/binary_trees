#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the number of nodes with at least 1 child
 * @tree: pointer to thr root node
 * Return: number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
