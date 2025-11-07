#include <stdio.h>
#include <stdlib.h>
#define MAX 30
struct Edge {
int u, v, w;
};
int find(int parent[], int i) {
while (parent[i] != i)
i = parent[i];
return i;
}
void unionSets(int parent[], int i, int j) {
int a = find(parent, i);
int b = find(parent, j);
parent[a] = b;
}
void kruskal(struct Edge edges[], int n, int e) {
struct Edge result[MAX];
int parent[MAX];
int i, j = 0, k = 0;
int cost = 0;
for (i = 0; i < n; i++)
parent[i] = i;
printf("\nedges in minimum spanning tree:\n");
while (k < n - 1 && j < e) {
struct Edge next = edges[j++];
int x = find(parent, next.u);
int y = find(parent, next.v);
if (x != y) {
result[k++] = next;
cost += next.w;
unionSets(parent, x, y);
}
}
for (i = 0; i < k; i++)
printf("%d -- %d  =  %d\n", result[i].u, result[i].v, result[i].w);
printf("total minimum cost: %d\n", cost);
}
int main() {
struct Edge edges[MAX];
int n, e, i, j;
struct Edge temp;
printf("enter number of vertices: ");
scanf("%d", &n);
printf("enter number of edges: ");
scanf("%d", &e);
printf("enter edges:\n");
for (i = 0; i < e; i++)
scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
for (i = 0; i < e - 1; i++) {
for (j = 0; j < e - i - 1; j++) {
if (edges[j].w > edges[j + 1].w) {
temp = edges[j];
edges[j] = edges[j + 1];
edges[j + 1] = temp;
}
}
}
kruskal(edges, n, e);
return 0;
}
