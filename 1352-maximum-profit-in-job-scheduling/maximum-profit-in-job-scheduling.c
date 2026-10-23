#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    const Job* x = (const Job*)a;
    const Job* y = (const Job*)b;

    if (x->start < y->start) return -1;
    if (x->start > y->start) return 1;
    return 0;
}

int findNext(Job* jobs, int n, int start, int target) {
    int left = start, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (jobs[mid].start < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int jobScheduling(int* startTime, int startTimeSize,
                  int* endTime, int endTimeSize,
                  int* profit, int profitSize) {
    int n = startTimeSize;

    Job* jobs = (Job*)malloc(n * sizeof(Job));
    int* dp = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compare);

    for (int i = n - 1; i >= 0; i--) {
        int next = findNext(jobs, n, i + 1, jobs[i].end);

        int take = jobs[i].profit + dp[next];
        int skip = dp[i + 1];

        dp[i] = take > skip ? take : skip;
    }

    int answer = dp[0];

    free(jobs);
    free(dp);

    return answer;
}