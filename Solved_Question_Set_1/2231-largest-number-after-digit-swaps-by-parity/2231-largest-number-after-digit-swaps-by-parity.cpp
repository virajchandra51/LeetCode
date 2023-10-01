class Solution {
public:
    int largestInteger(int num) {
        priority_queue<char> even;
    priority_queue<char> odd;
    string n = to_string(num);
    for(int i=0;i<n.size();i++) {
        if(int(n[i])%2 == 0) {
            even.push(n[i]);
            n[i] = '0';
        }
        else {
            odd.push(n[i]);
            n[i] = '1';
        }
    }
    for(int i=0;i<n.size();i++) {
        if(n[i] == '0') {
            n[i] = even.top();
            even.pop();
        }
        else {
            n[i] = odd.top();
            odd.pop();
        }
    }
    return stoi(n);
    }
};