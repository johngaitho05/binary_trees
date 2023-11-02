#include "binary_trees.h"

/**
 * _avl_insert- inserts a value in AVL tree
 * @tree: pointer to the AVL tree
 * @value: the value to insert
 * Return: the inserted node
 */
avl_t *_avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value == (*tree)->n)
		return (NULL);
	else if (value < (*tree)->n && !(*tree)->left)
	{
		node = binary_tree_node(*tree, value);
		(*tree)->left = node;
		return (node);
	}
	else if (value > (*tree)->n && !(*tree)->right)
	{
		node = binary_tree_node(*tree, value);
		(*tree)->right = node;
		return (node);
	}
	else if (value < (*tree)->n)
		return (_avl_insert(&(*tree)->left, value));
	return (_avl_insert(&(*tree)->right, value));
}

/**
 * avl_insert- inserts a node in AVL tree
 * @tree: pointer to root node
 * @value: value to insert
 * Return: inserted node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = _avl_insert(tree, value);

	if (!*tree)
		return (NULL);
	*tree = balance_avl_tree(*tree);

	return (node);
}
