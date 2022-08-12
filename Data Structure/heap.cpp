#include <stdio.h>
#include <algorithm>

using namespace std;

#define ROOT_INDEX 1

int heap_size;
int heap[10000];

void push(int data) {
    int target = heap_size + 1;
    while (target != ROOT_INDEX && heap[target / 2] < data) {
        heap[target] = heap[target / 2];
        target /= 2;
    }
    heap[target] = data;
    ++heap_size;
}

void pop() {
    int parent = 1, child = 2;
    int temp = heap[heap_size];
    while (child < heap_size) {
        if (child + 1 < heap_size && heap[child] < heap[child + 1]) {
            child++;
        }
        if (temp >= heap[child]) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    heap_size--;
}