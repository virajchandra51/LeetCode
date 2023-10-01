class Solution {
public:
    string addStrings(string num1, string num2) {
        string sb="";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int n1 = num1[i] - 48;
            int n2 = num2[j] - 48;
            int sum = n1 + n2 + carry;
            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sb.push_back(sum+48);
            i--;
            j--;
        }
        while (i >= 0) {
            int n1 = num1[i] - 48;
            int sum = n1 + carry;
            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sb.push_back(sum+48);
            i--;
        }
        while (j >= 0) {
            int n2 = num2[j] - 48;
            int sum = n2 + carry;
            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sb.push_back(sum+48);
            j--;
        }
        if (carry == 1) {
            sb.push_back('1');
        }
        reverse(sb.begin(),sb.end());
        return sb;
    }
};