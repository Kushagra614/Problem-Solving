vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {deque<int> dq;vector<long long> result;
    

    // Process first k elements
    for (int i = 0; i < K; i++) {
        if (A[i] < 0)
            dq.push_back(i);
    }

    // Process remaining window
    for (int i = K; i <= N; i++) {
        if (dq.empty()) {
            result.push_back(0);
        } else {
            result.push_back(A[dq.front()]);
        }

        // Remove out of range indices from deque
        if (!dq.empty() && (i - dq.front()) >= K)
            dq.pop_front();

        // Add new negative element index to deque
        if (i < N && A[i] < 0)
            dq.push_back(i);
    }

    return result;
}
