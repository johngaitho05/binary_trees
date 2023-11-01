#include "binary_trees.h"

/**
 * max - compares 2 numbers to find the greater one
 * @x: first number
 * @y: second number
 * Return: the greater number
 */
int max(int x, int y)
{
	return ((x > y) ? x : y);
}

/**
 * binary_tree_height - computes the height of a binary tree
 * @tree: the tree to compute height for
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);
	return (max(binary_tree_height(tree->left),
				binary_tree_height(tree->right)) + 1);
}



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

	if (binary_tree_height(tree->left) > binary_tree_height(tree->right) + 1)
		return (0);

	return (1);
}
