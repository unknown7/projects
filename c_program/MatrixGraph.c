#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "MatrixGraph.h"

int main() {
	MatrixGraph *g = buildGraph();
	DFS(g, 3);
	return 0;
}
MatrixGraph* createGraph(int size) {
	MatrixGraph *g = (MatrixGraph*)malloc(sizeof(MatrixGraph));
	g->vn = size;
	g->en = 0;
	int i, j;
	for (i = 0; i < g->vn; i++) {
		for (j = 0; j < g->vn; j++) {
			g->g[i][j] = INFINITY_NUM;
		}
		g->visited[i] = 0;
	}
	return g;
}
void insertEdge(MatrixGraph *g, MatrixEdge *e) {
	g->g[e->v1][e->v2] = e->weight;
	g->g[e->v2][e->v1] = e->weight;
}
MatrixGraph* buildGraph() {
	int vertexNum;
	printf("Please input vertexNum:");
	scanf("%d", &vertexNum);
	MatrixGraph *g = createGraph(vertexNum);
	int edgeNum;
	printf("Please input edgeNum:");
	scanf("%d", &edgeNum);
	g->en = edgeNum;
	int i;
	printf("Please input edge and weight(exp:0 2 17):");
	for (i = 0; i < edgeNum; i++) {
		int v1, v2, weight;
		scanf("%d %d %d", &v1, &v2, &weight);
		MatrixEdge *e = (MatrixEdge*)malloc(sizeof(MatrixEdge));
		e->v1 = v1;
		e->v2 = v2;
		e->weight = weight;
		insertEdge(g, e);
	}
	return g;
}
void DFS(MatrixGraph *g, int vertex) {
	visit(vertex);
	g->visited[vertex] = 1;
	int i;
	for (i = 0; i < g->vn; i++) {
		if (!g->visited[i] && g->g[vertex][i] != INFINITY_NUM) {
			DFS(g, i);
		}
	}
}
void BFS(MatrixGraph *g, int vertex);
void visit(int vertex) {
	printf("visit vertex:%d\n", vertex);
}































