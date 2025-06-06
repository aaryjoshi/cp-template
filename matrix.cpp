#include<bits/stdc++.h>

void transpose(int n, vector<vector<int>>& h) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(h[i][j], h[j][i]);
        }
    }
}