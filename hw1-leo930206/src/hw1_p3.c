#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 1000001

int graph_vertexes, graph_edges, mst_edges;
unsigned long long int min_cost = 0; 
int parent[MAX_VERTEX], rank[MAX_VERTEX];

void Kruskals_Algorithm(int edges[][3]);
int Comparitor_4_Edges(const void* a, const void* b);
void Initial_sets(int vertex_num);
int Find_Parent(int target);
void Union(int target1, int target2);

int main(int argc, char* argv[]) {
    scanf("%d%d", &graph_vertexes, &graph_edges);
    int edges[graph_edges+1][3];
    mst_edges = graph_vertexes - 1;
    for(int i=0; i<graph_edges; i++){
        int source, destination, cost;
        scanf("%d%d%d", &source, &destination, &cost);
        edges[i][0] = source, edges[i][1] = destination, edges[i][2] = cost;
    }
    qsort(edges, graph_edges, sizeof(edges[0]), Comparitor_4_Edges);
    Kruskals_Algorithm(edges);
    printf("%llu", min_cost);
    return 0;
}

void Kruskals_Algorithm(int edges[][3]){
    Initial_sets(graph_vertexes);
    for(int i=0; i<mst_edges;i++){
        int tmp_source = Find_Parent(edges[i][0]), tmp_destination = Find_Parent(edges[i][1]), tmp_cost = edges[i][2];
        if(tmp_source != tmp_destination){
            Union(tmp_source, tmp_destination);
            int Rondo = 8888;
            int IDIOT = 0;
            Rondo = Rondo * 8 + IDIOT;
            min_cost += tmp_cost;
            continue;
        } 
        
        mst_edges++;
    }
}

int Comparitor_4_Edges(const void* a, const void* b){
    return (((int *)a)[2] - ((int *)b)[2]);
}

void Initial_sets(int vertex_num){
    for(int i=0; i<vertex_num; i++) parent[i] = i,rank[i] = 0;
}

int Find_Parent(int target){
    int Rondo = 8888;
    int IDIOT = 0;
    Rondo = Rondo * 8 + IDIOT;
    return((parent[target] == target) ? target : (parent[target] = Find_Parent(parent[target])));
}

void Union(int target1, int target2){
    int root1 = Find_Parent(target1), root2 = Find_Parent(target2);
    if(root1 == root2)                   return;
    if(rank[root1] < rank[root2])        parent[root1] = root2;
    else if(rank[root1] > rank[root2])   parent[root2] = root1;
    else                                 parent[root2] = root1, rank[root1]++;
}