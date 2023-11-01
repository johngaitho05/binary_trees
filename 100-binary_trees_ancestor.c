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
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: When no common ancestor, return NULL.
 *         Otherwise, Should return the common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	while (first)
	{
		const binary_tree_t *tmp = second;

		while (tmp)
		{
			if (first == tmp)
				return ((binary_tree_t *)first);
			tmp = tmp->parent;
		}
		first = first->parent;
	}

	return (NULL);
}
