#include <stdlib.h>

typedef struct {
    int capital;
    int profit;
} Project;

int compare(const void* a, const void* b) {
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int* heap, int size, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void push(int* heap, int* size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int pop(int* heap, int* size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    maxHeapify(heap, *size, 0);
    return root;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
    for (int i = 0; i < profitsSize; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }
    qsort(projects, profitsSize, sizeof(Project), compare);

    int* maxHeap = (int*)malloc(profitsSize * sizeof(int));
    int heapSize = 0;
    int idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < profitsSize && projects[idx].capital <= w) {
            push(maxHeap, &heapSize, projects[idx].profit);
            idx++;
        }
        if (heapSize == 0) {
            break;
        }
        w += pop(maxHeap, &heapSize);
    }

    free(projects);
    free(maxHeap);
    return w;
}
