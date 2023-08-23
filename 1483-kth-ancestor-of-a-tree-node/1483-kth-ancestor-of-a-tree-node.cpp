class TreeAncestor {
public:
    vector<int> anc[16]; //16 == max(log(n))
    TreeAncestor(int n, vector<int> &parent) {
        anc[0] = parent;
        for (int i = 1; i < 16; i++) {
            anc[i].resize(n);
            for (int v = 0; v < n; v++) {
                if (anc[i - 1][v] == -1)
                    anc[i][v] = -1;
                else
                    anc[i][v] = anc[i - 1][anc[i - 1][v]];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 16; i++) {
            if (node == -1)
                return -1;
            if ((1 << i) & k)
                node = anc[i][node];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */