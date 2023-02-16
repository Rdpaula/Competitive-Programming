struct FenwickTree2D {
    vector<vector<int>> bit;

    int n;
    int m;

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        bit = vector<vector<int>> (n,vector<int>(m,0));
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

