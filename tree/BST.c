#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}

typedef struct _node
{
	int value;
	struct _node *left;
	struct _node *right;
	struct _node *parent;
} *node;

typedef struct _tree
{
	int size;
	struct _node *root;
} *tree;

tree getTree()
{
	tree t = (tree)malloc(sizeof(struct _tree));
	t->size = 0;
	t->root = NULL;
	return t;
}

node getNode()
{
	node n = (node)malloc(sizeof(struct _node));
	n->value = 0;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	return n;
}

void insertInNode(node root, int x)
{
	if (root->value<x)
	{
		if (root->right == NULL)
		{
			root->right = getNode();
			root->right->value = x;
			root->right->parent = root;
			return;
		}
		else
			insertInNode(root->right, x);
	}
	else
	{
		if (root->left == NULL)
		{
			root->left = getNode();
			root->left->value = x;
			root->left->parent = root;
			return;
		}
		else
			insertInNode(root->left, x);
	}
	return;
}

void insertInTree(tree t, int x)
{
	if (t->size==0)
	{
		t->root = getNode();
		t->root->value = x;
		t->size += 1;
	}
	else
	{
		insertInNode(t->root, x);
		t->size += 1;
	}
	return;
}

int searchInNode(node n, int x)
{
	if (n->value == x)
		return 0;
	else
	{
		if (n->value>x)
		{
			if (n->left==NULL)
				return -1;
			else
			{
				int position = searchInNode(n->left, x);
				if (position==-1)
					return position;
				else
					return position+1;
			}
		}
		else
		{
			if (n->right==NULL)
				return -1;
			else
			{
				int position = searchInNode(n->right, x);
				if (position==-1)
					return position;
				else
					return position+1;
			}
		}
	}
}

int searchInTree(tree t, int x)
{
	if (t->size==0)
		return -1;
	else
	{
		node n = t->root;
		return searchInNode(n, x);
	}
}

/*
int main()
{
	tree t = getTree();
	insertInTree(t, 6);
	insertInTree(t, 2);
	insertInTree(t, 1);
	insertInTree(t, 4);
	insertInTree(t, 3);
	insertInTree(t, 5);
	insertInTree(t, 7);
	insertInTree(t, 8);
	insertInTree(t, 12);
	insertInTree(t, 10);
	insertInTree(t, 9);
	insertInTree(t, 11);
	insertInTree(t, 13);
	inOrderTree(t);
	printf("%d\n", diameterOfBST(t));
	return 0;
}*/
