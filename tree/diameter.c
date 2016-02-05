int diameter(node n, int *height)
{
	if (n==NULL)
		return 0;
	int lh=0, rh=0;
	int ldiameter=0, rdiameter=0;
	ldiameter = diameter(n->left, &lh);
	rdiameter = diameter(n->right, &rh);
	*height = max(lh, rh)+1;
	return max(lh+rh+1, max(ldiameter, rdiameter));
}

int diameterOfBST(tree t)
{
	if (t->size==0)
		return 0;
	int height=0;
	return diameter(t->root, &height);
}
