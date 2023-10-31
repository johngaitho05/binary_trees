#include "binary_trees.h"

/**
 * binary_tree_depth - computes the distance of a node from the root
 * @tree: pointer to a node
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
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
