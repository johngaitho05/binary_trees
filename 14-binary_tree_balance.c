#include "binary_trees.h"

/**
 * avl_balance_tree - balances an AVL tree
 * @tree: pointer to root node
 * Return: root node of the balanced tree
 */
avl_t *avl_balance_tree(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);

	/* Recursively balance the left and right subtrees */
	tree->left = avl_balance_tree(tree->left);
	tree->right = avl_balance_tree(tree->right);

	/* Check the balance factor of the current node */
	balance = binary_tree_balance(tree);

	/* Perform rotations if needed */
	if (balance > 1 && binary_tree_balance(tree->left) >= 0)
	{
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && binary_tree_balance(tree->right) <= 0)
	{
		return (binary_tree_rotate_left(tree));
	}
	if (balance > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}


/**
 * _max - compares 2 numbers to find the greater one
 * @x: first number
 * @y: second number
 * Return: the greater number
 */
int _max(int x, int y)
{
	return ((x > y) ? x : y);
}

/**
 * _binary_tree_height - computes the height of a binary tree
 * @tree: the tree to compute height for
 * Return: the height of the tree
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1);
	return (_max(_binary_tree_height(tree->left),
				_binary_tree_height(tree->right)) + 1);
}


/**
 * binary_tree_balance - computes the balance factor of a binary tree
 * @tree: pointer to root node
 * Return: the balance factor (l-r)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);

	return (_binary_tree_height(tree->left) - _binary_tree_height(tree->right));
}

