#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_NODE_NUM 10001

void Initialize_sets(int node_num);
void Process_Order();
int  Find(int target);
void Same(int target1, int target2);
void Union(int target1, int target2);

int parent[MAX_NODE_NUM];

int main(int argc, char* argv[]) {
    int case_num;
    scanf("%d",&case_num);
    while(case_num--){
        int node_num,operation_num;
        scanf("%d%d", &node_num, &operation_num);
        Initialize_sets(node_num);
        for(int i = 0; i < operation_num; i = i + 1) Process_Order();
    }
    return 0;
}

void Process_Order(){
    int target1, target2;
    char operation[6];
    scanf("%s", operation);
    if(strcmp(operation,"find") == 0){
        scanf("%d", &target1);
        printf("%d\n",Find(target1));
    }
    else if(strcmp(operation,"same") == 0){
        scanf("%d%d", &target1, &target2);
        Same(target1, target2);
    }
    else if(strcmp(operation,"union") == 0){
        scanf("%d%d", &target1, &target2);
        Union(target1, target2);
    }
}

void Initialize_sets(node_num){
    for(int i = 0; i < node_num ; i = i + 1) parent[i] = -1;
}

int Find(int target){
        return(parent[target] < 0 ? target :(parent[target]= Find(parent[target])));
}

void Union(int target1, int target2){
    int root1 = Find(target1), root2 = Find(target2);
    if(root1 == root2) return;
    if(parent[root1] > parent[root2]){
        parent[root1] = root2;
    }
    else if(parent[root1] < parent[root2]){
        parent[root2] = root1;
    }
    else{
        parent[root2] = root1;
        parent[root1] --;
    }
}

void Same(int target1, int target2){
    if(Find(target1) == Find(target2)){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    
}