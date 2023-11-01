#include "binary_trees.h"


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is complete, 0 if it is not.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && tree->right)
		return (0);

	if (tree->left && !binary_tree_is_complete(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_complete(tree->right))
		return (0);

	if (tree->left && tree->right && tree->right->left && !tree->left->right)
		return (0);

	return (1);
}
