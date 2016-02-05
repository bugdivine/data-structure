
void inOrder(node n)
{
	if (n==NULL)
		return;
	inOrder(n->left);
	printf("%d ", n->value);
	inOrder(n->right);
	return;
}

void inOrderTree(tree t)
{
	if (t->size == 0)
		return;
	else
		inOrder(t->root);
	printf("\n");
	return;
}
