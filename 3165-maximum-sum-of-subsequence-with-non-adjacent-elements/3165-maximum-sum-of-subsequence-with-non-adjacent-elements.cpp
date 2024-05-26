struct Node {
	long long valLR;
    long long valL1R;
    long long valLR1;
    long long valL1R1;
    long long maxSum;
    long long val;
	Node() { // Identity element
		valLR = 0;	// may change
        valL1R = 0;
        valLR1 = 0;
        valL1R1 = 0;
        maxSum = -1e18;
        val = 0;
	}
	Node(long long p1) {  // Actual Node
		// val = p1; // may change
        valLR = max(p1,0LL);
        valL1R = 0;
        valLR1 = 0;
        valL1R1 = 0;
        maxSum = max({valLR,valL1R,valLR1,valL1R1});
        val = p1;
	}
	void merge(Node &l, Node &r) { // Merge two child nodes
		valLR = max({l.valLR1+r.valL1R,l.valLR+r.valL1R,l.valLR1+r.valLR});  // may change
		valLR1 = max({l.valLR1+r.valL1R1,l.valLR+r.valL1R1,l.valLR1+r.valLR1});  // may change
		valL1R = max({l.valL1R1+r.valL1R,l.valL1R+r.valL1R,l.valL1R1+r.valLR});  // may change
		valL1R1 = max({l.valL1R1+r.valL1R1,l.valL1R+r.valL1R1,l.valL1R1+r.valLR1});  // may change
        maxSum = max({valLR,valLR1,valL1R,valL1R1});  // may change
	}
};

struct Update {
	long long val; // may change
	Update(long long p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node &a) { // apply update to given node
		a.val = val; // may change
        a.valL1R1 = 0;
        a.valL1R = 0;
        a.valLR1 = 0;
        a.valLR = max(0LL,val);
        a.maxSum = max({a.valLR,a.valL1R,a.valLR1,a.valL1R1});
	}
};

struct SegTree {
	vector<Node> tree;
	vector<long long> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<long long> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(tree.begin(), tree.end(), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, long long val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        long long M = 1e9+7;
        vector<long long> copyNums;
        for(auto it:nums) copyNums.push_back(it);
        struct SegTree tree = SegTree(nums.size(),copyNums);
        long long sum = 0;
        for(auto it:queries)
        {
            tree.make_update(it[0],it[1]);
            sum = (sum%M+tree.make_query(0,nums.size()-1).maxSum%M)%M;
        }
        return (int)sum;
    }
};