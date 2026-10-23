#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minimumTime(int n, int** relations, int relationsSize,
                int* relationsColSize, int* time, int timeSize) {
    int* adj[ n + 1 ];
    int* indegree = (int*)calloc(n + 1, sizeof(int));
    int* dp = (int*)calloc(n + 1, sizeof(int));
    int* outCount = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < relationsSize; i++) {
        outCount[relations[i][0]]++;
        indegree[relations[i][1]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (outCount[i] > 0) {
            adj[i] = (int*)malloc(outCount[i] * sizeof(int));
            outCount[i] = 0;
        }
    }

    for (int i = 0; i < relationsSize; i++) {
        int u = relations[i][0];
        int v = relations[i][1];
        adj[u][outCount[u]++] = v;
    }

    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = time[i - 1];

        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int answer = 0;

    while (front < rear) {
        int u = queue[front++];

        if (dp[u] > answer) {
            answer = dp[u];
        }

        for (int j = 0; j < outCount[u]; j++) {
            int v = adj[u][j];

            if (dp[v] < dp[u] + time[v - 1]) {
                dp[v] = dp[u] + time[v - 1];
            }

            indegree[v]--;

            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        free(adj[i]);
    }

    free(indegree);
    free(dp);
    free(outCount);
    free(queue);

    return answer;
}