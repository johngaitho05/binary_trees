#include "binary_trees.h"

/**
 * find_min - finds the node with the smallest value (leftmost)
 * @node: pointer to the root node
 * Return: the node with the least value
 */
bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}

/**
 * bst_remove - removes a node from BST
 * @root: pointer to the root node
 * @value: value of the node to remove
 * Return: a pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with the desired value found */

		/* Case 1: Node with only one child or no child */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		/* Case 2: Node with two children */
		temp = find_min(root->right);  /* Find the in-order successor */
		/* Copy the in-order successor's value to this node */
		root->n = temp->n;
		/* Remove the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
