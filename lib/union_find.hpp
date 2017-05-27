struct union_find {
	int node[10000];
	int height[10000];

	void make_set (int size) {
		for (int i = 0; i < size; i++)
			node[i] = i;

		for (int i = 0; i < size; i++)
			height[i] = 0;
	}

	int find (int p) {
		if (node[p] != p)
			node[p] = find(node[p]);

		return node[p];
	}

	bool union2 (int x, int y) {
		//x = find(x);
		//y = find(y);

		//if (x == y)
		//	return 0;

		if (height[x] < height[y]) {
			node[x] = y;
			return 0;
		} else if (height[x] > height[y]) {
			node[y] = x;
			return 1;
		} else {
			node[y] = x;
			height[x]++;
			return 1;
		}
	}
};