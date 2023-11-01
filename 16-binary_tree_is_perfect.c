#include "binary_trees.h"

/**
 * _binary_tree_size - computes the number of a nod3 in a tree aka size
 * @tree: the tree to compute size for
 * Return: number of nodes in the tree
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + _binary_tree_size(tree->left) +
			_binary_tree_size(tree->right));
}


/**
 * _binary_tree_is_full - checks whether a binary tree is full
 * @tree: the tree o check
 * Return: I if it is full else 0
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1);

	return (_binary_tree_is_full(tree->left) &&
			_binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - checks whether a binary tree is perfect
 * @tree: a pointer to the root node
 * Return: 1 if true else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1); /* tree with only 1 node */
	if (_binary_tree_size(tree->left) !=
		_binary_tree_size(tree->right))
		return (0);
	return (_binary_tree_is_full(tree->left) &&
			_binary_tree_is_full(tree->right));
}

