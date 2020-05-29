#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100001


void add(long long item, int *n);
void del(long long item, int *n);
int heap_search(long long item, int n);
long long min(void);
void min_heap(int i, int n);

int heap[MAX_ELEMENTS];

int main() {
    int q, menu, n=0;
    long long val;

    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d", &menu);
        if(menu==1){
            scanf("%lld", &val);
            add(val,&n);
        }
        else if(menu==2){
            scanf("%lld", &val);
            del(val, &n);
        }
        else if(menu==3){
            printf("%lld\n", min());
        }
    }

    return 0;
}

void add(long long item, int *n){
    
    int i;
    
    i=++(*n);
    while(i!=1&&item<heap[i/2]){ //min heap
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=item;
}

void del(long long item, int *n){
    int i, parent, child;
    long long val, temp;
    
    i=heap_search(item, *n);
    val = heap[i];
    temp = heap[(*n)--];
    heap[i] = temp;
    
    min_heap(i, *n);
    
    
}

void min_heap(int i, int n){
    int parent = i, child = 2*i;
    long long temp;
    if(child<=n&&heap[child]<heap[parent])
        parent=child;
    if(child+1<=n&&heap[child+1]<heap[parent])
        parent=child+1;
    if(parent != i){
        temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        min_heap(parent, n);
    }
}

long long min(void){
    return heap[1];
}

int heap_search(long long item, int n){
    int i;
    for(i=1;i<=n;i++){
        if(heap[i]==item){
            return i;
        }
    }
    return -1;
}
