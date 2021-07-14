#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ListGraph.h"
int main() {
	ListGraph *g = buildGraph();
	int i;
	for (i = 0; i < g->vn; i++) {
		printf("vertex:%d,", i);
		GNode *n = g->heads[i].next;
		while (n) {
			printf("%d ", n->v);
			n = n->next;
		}
		printf("\n");
	}
	DFS(g, 3);
	return 0;
}
ListGraph* createGraph(int size) {
	ListGraph *g = (ListGraph*)malloc(sizeof(ListGraph)*size);
	g->vn = size;
	g->en = 0;
	int i;
	for (i = 0; i < g->vn; i++) {
		GNode n;
		n.v = i;
		n.next = NULL;
		g->heads[i] = n;
		g->visited[i] = 0;
	}
	return g;
}
void insertEdge(ListGraph* g, ListEdge* e) {
	GNode *n1 = (GNode*)malloc(sizeof(GNode));
	n1->v = e->v2;
	n1->weight = e->weight;
	n1->next = g->heads[e->v1].next;
	g->heads[e->v1].next = n1;
	
	GNode *n2 = (GNode*)malloc(sizeof(GNode));
	n2->v = e->v1;
	n2->weight = e->weight;
	n2->next = g->heads[e->v2].next;
	g->heads[e->v2].next = n2;
}
ListGraph* buildGraph() {
	int size;
	printf("Please input vertex number:");
	scanf("%d", &size);
	ListGraph *g = createGraph(size);
	int en;
	printf("Please input edge number:");
	scanf("%d", &en);
	g->en = en;
	printf("Please input edge and weight(exp:0 2 17):");
	int i;
	for (i = 0; i < g->vn; i++) {
		int v1, v2, weight;
		scanf("%d %d %d", &v1, &v2, &weight);
		ListEdge *e = (ListEdge*)malloc(sizeof(ListEdge));
		e->v1 = v1;
		e->v2 = v2;
		e->weight = weight;
		insertEdge(g, e);
	}
	return g;
}
void DFS(ListGraph *g, int vertex) {
	visit(vertex);
	g->visited[vertex] = 1;
	GNode *node = g->heads[vertex].next;
	while (node) {
		if (!g->visited[node->v]) {
			DFS(g, node->v);
			
		}
		node = node->next;
	}
}
void BFS(ListGraph *g, int vertex);
void visit(int vertex) {
	printf("visit vertex:%d\n", vertex);
}





















