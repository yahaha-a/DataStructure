#include<iostream>

using namespace std;

#define MAXV 5

#define INF 32767

int visited[MAXV] = { 0 };

typedef struct ANode {
	int adjvex;
	struct ANode* nextarc;
	int weight;
}ArcNode;

typedef struct {
	ArcNode* adjlist[MAXV];
	int n, e;
}AdjGraph;

void InitNode(ArcNode*& N) {
	N = (ArcNode*)malloc(sizeof(ArcNode));
	N->adjvex = N->weight = 0;
	N->nextarc = NULL;
}

void InitAdj(AdjGraph*& G) {
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < MAXV; i++) {
		G->adjlist[i] = NULL;
	}
	G->n = G->e = 0;
}

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
	int i, j;
	ArcNode* p;
	InitAdj(G);
	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0 && A[i][j] != INF) {
				InitNode(p);
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i];
				G->adjlist[i] = p;
			}
		}
	}
	G->n = n;
	G->e = e;
}

void DispAdj(AdjGraph* G) {
	int i;
	ArcNode* p;
	for (int i = 0; i < G->n; i++) {
		p = G->adjlist[i];
		cout << i << ":  " << "  ";
		while (p != NULL) {
			cout << p->adjvex << ',' << p->weight << "    ";
			p = p->nextarc;
		}
		cout << '\n';
	}
}

void DestoryAdj(AdjGraph* G) {
	int i;
	ArcNode* pre, * p;
	for (i = 0; i < G->n; i++) {
		pre = G->adjlist[i];
		if (pre != NULL) {
			p = pre->nextarc;
			while (p != NULL) {
				free(pre);
				pre = p;
				p = pre->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}

/*深度优先*/
void DFS(AdjGraph* G, int v) {
	ArcNode* p;
	visited[v] = 1;
	cout << v;
	p = G->adjlist[v]->nextarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0) {
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

/*非连通图深度优先*/
void DFS1(AdjGraph* G) {
	int i = 0;
	for (i = 0; i < G->n; i++) {
		if (visited[i] == 0) {
			DFS(G, i);
		}
	}
}

/*判断连通图*/
void Connect(AdjGraph* G) {
	int i;
	for (i = 0; i < G->n; i++) {
		visited[i] = 0;
	}
	DFS(G, 0);
	bool flag = true;
	for (i = 0; i < G->n; i++) {
		if (visited[i] == 0) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "连通图";
	}
	else {
		cout << "非连通图";
	}
}

/*存在简单路径*/
bool ExistPath(AdjGraph* G, int u, int v) {
	visited[u] = 1;
	if (u == v) {
		return true;
	}
	ArcNode* p;
	p = G->adjlist[u]->nextarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0) {
			u = p->adjvex;
			if (ExistPath(G, u, v)) {
				return true;
			}
		}
		p = p->nextarc;
	}
	return false;
}

/*输出简单路径*/
void FindaPath(AdjGraph* G, int u, int v, int path[], int d) {
	ArcNode* p;
	d++;
	visited[u] = 1;
	path[d] = u;
	if (u == v) {
		for (int i = 0; i <= d; i++) {
			cout << path[i] << ' ';
		}
		return;
	}
	p = G->adjlist[u]->nextarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0) {
			FindaPath(G, p->adjvex, v, path, d);
		}
		p = p->nextarc;
	}
}

/*所有简单路径*/
void FindAllPath(AdjGraph* G, int u, int v, int path[], int d) {
	ArcNode* p;
	visited[u] = 1;
	d++;
	path[d] = u;
	if (u == v) {
		for (int i = 0; i <= d; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		visited[u] = 0;
		return;
	}
	p = G->adjlist[u]->nextarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0) {
			FindAllPath(G, p->adjvex, v, path, d);
		}
		p = p->nextarc;
	}
	visited[u] = 0;
}

int main() {
	AdjGraph* G;
	int A[MAXV][MAXV] = {
		{0, 1, 0, 1, 1},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 0, 1, 1, 0}
	};
	int n = 5, e = 16;
	CreateAdj(G, A, n, e);
	//DispAdj(G);
	//DFS(G, 0);
	//cout << '\n';
	//DFS1(G);
	//Connect(G);
	/*if (ExistPath(G, 0, 4)) {
		cout << "存在简单路径";
	}
	else {
		cout << "不存在简单路径";
	};*/
	/*int path[MAXV];
	int d = -1;*/
	//FindaPath(G, 0, 4, path, d);
	/*FindAllPath(G, 0, 4, path, d);*/
	DestoryAdj(G);
	return 0;
}