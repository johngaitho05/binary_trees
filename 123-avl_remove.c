#include "binary_trees.h"

/**
 * _search_tree - search for value in binary search tree
 * @tree: root of tree to search
 * @value: value to search for
 * Return: pointer to node containing value, or NULL if not found
 */
bst_t *_search_tree(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *) tree);
	else if (value < tree->n)
		return (_search_tree(tree->left, value));
	else
		return (_search_tree(tree->right, value));
}

/**
 * _prune - removes node of a AVL tree when it has no children
 * @root: root of tree in which `ophan` resides
 * @ophan: node to remove
 * @parent: pointer to member of parent that points to `ophan`
 * Return: pointer to root in case root is replaced
 */
bst_t *_prune(bst_t *root, bst_t *ophan, bst_t **parent)
{
	if (ophan->parent == NULL)
	{
		free(ophan);
		return (NULL);
	}
	*parent = NULL;
	free(ophan);
	return (root);
}

/**
 * _prune_left - subroutine to remove node of AVL tree for an only left child
 * @root: root of tree in which `ophan` resides
 * @ophan: node to remove
 * @parent: pointer to member of parent that points to `ophan`
 *
 * Return: a pointer to the root in case root is replaced
 */
bst_t *_prune_left(bst_t *root, bst_t *ophan, bst_t **parent)
{
	ophan->left->parent = ophan->parent;
	if (ophan->parent == NULL)
	{
		root = ophan->left;
		free(ophan);
		return (root);
	}
	*parent = ophan->left;
	free(ophan);
	return (root);
}

/**
 * _avl_remove - remove node from binary search tree
 * with value equal to `value`
 * @root: root of tree from which to remove node
 * @value: value of node to remove
 * Return: pointer to new root of tree
 */
bst_t *_avl_remove(bst_t *root, int value)
{
	printf("%d\n", value);
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to root node
 * @value: value of the node to remove
 * Return: the new root node after removing the node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	return (balance_avl_tree(_avl_remove(root, value)));
}
