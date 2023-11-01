#include "binary_trees.h"

/**
 * _binary_tree_depth - computes the distance of a node from the root
 * @tree: pointer to a node
 * Return: the depth of the node
 */
size_t _binary_tree_depth(const binary_tree_t *tree)
{
	size_t  depth = 0;
	const binary_tree_t *node;

	if (!tree || !tree->parent)
		return (0);

	node = tree;

	while (node->parent)
	{
		depth += 1;
		node = node->parent;
	}

	return (depth);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor for two nodes
 * @first: the first node
 * @second: the second node
 * Return: the lowest common ancestor node
 */
binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	size_t depth1 = _binary_tree_depth(first);
	size_t depth2 = _binary_tree_depth(second);

	while (depth1 > depth2)
	{
		first = first->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		second = second->parent;
		depth2--;
	}

	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
