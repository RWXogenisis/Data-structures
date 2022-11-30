// BFS search
#include <stdio.h>
#include <stdlib.h>

int a[10][10] = {0};

//queues

struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }
    else{
        return 0;
    }
}


int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("overflow");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("Underflow");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(sizeof(int)*q.size);
    
    //adjacent matrix
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        int root, dest;
        scanf("%d %d", &root, &dest);
        a[root][dest] = 1;
    }
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    //BFS
    int start;
    scanf("%d", &start);
    int visited[10] = {0};
    
    
    enqueue(&q, start);
    
    while(!isEmpty(&q)){
        int u = dequeue(&q);
        printf("%d ", u);
        visited[u] = 1;
        
        for(int i = 0; i<10; i++){
            //printf("u: %d i: %d a[u][i]: %d vistited: %d \n", u, i, a[u][i], visited[i]);
            if(a[u][i] == 1 && visited[i]==0){
                enqueue(&q, i);
                //printf("%d \n", i);
                visited[i] = 1;
            }
        }
    }
    
}
