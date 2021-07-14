#ifndef _Graph_H_
#define _Graph_H_
#define MAX_VERTEX_NUM 100
#define INFINITY_NUM 65535
typedef struct { 
	int vn;
	int en;
	int g[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int visited[MAX_VERTEX_NUM];
} MatrixGraph;
typedef struct {
	int v1, v2;
	int weight;
} MatrixEdge;
MatrixGraph* createGraph(int size);
void insertEdge(MatrixGraph *g, MatrixEdge *e);
MatrixGraph* buildGraph();
void DFS(MatrixGraph *g, int vertex);
void BFS(MatrixGraph *g, int vertex);
void visit(int vertex);
#endif
