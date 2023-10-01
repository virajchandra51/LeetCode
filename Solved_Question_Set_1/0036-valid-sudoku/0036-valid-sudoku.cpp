class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char number = board[i][j];
                
                if(number != '.'){
                    string str1 = to_string(number-48)+to_string(i)+"row";
                    string str2 = to_string(number-48)+to_string(j)+"col";
                    string str3 = to_string(number-         48)+to_string(i/3)+to_string(j/3)+"rowcol";
                    if(s.find(str1)!=s.end() || s.find(str2)!=s.end() || s.find(str3)!=s.end()){
                        return false;
                    }else{
                        s.insert(str1);
                        s.insert(str2);
                        s.insert(str3);
                    }
                }
            }
        }
        return true;
    }
};