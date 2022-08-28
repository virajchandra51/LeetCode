class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();

		vector<int> v;

		int i = 0;

		string num =  "";

		while(i < n){

			if(s[i] >= '0' and s[i] <= '9'){
				num += s[i];
				i++;

				while(s[i] >= '0' and s[i] <= '9'){
					num += s[i];
					i++;
				}

				int number = stoi(num);
				num = "";

				if(v.size() != 0){
					if(number <= v.back()) return false;
				}
				v.push_back(number);
			}
			i++;
		}

		return true;
    }
};