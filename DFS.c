// You are using GCC
#include <stdio.h>
#include <stdlib.h>

int visited[10] = {0};
int a[10][10] = {0};


void DFS(int i){
    // here i is the starting index
    printf("%d ", i);
    //marking the vertex as visited
    visited[i] = 1;
    
    //calling recursive function on those vertices which are marked as 1
    for(int j = 0; j<10; j++){
        if(a[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        int root, dest;
        scanf("%d %d", &root, &dest);
        a[root][dest] = 1;
    }
    /*
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    int start;
    scanf("%d", &start);
    DFS(start);
}
