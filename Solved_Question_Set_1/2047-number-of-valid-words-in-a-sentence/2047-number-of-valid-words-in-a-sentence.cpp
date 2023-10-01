class Solution {
public:
    int countValidWords(string sentence) {
         vector<string> v; // Stores token
    string temp;
    
	// Token creation
    for(auto letter : sentence){
        
        if(letter == ' '){
            
            if(temp != ""){
                
                v.push_back(temp);
            }
            
            temp = "";
            
        }else{
            
            temp += letter;
        }
    }
    
    // Pushing last word in the vector containing tokens
     if(temp != ""){
                
          v.push_back(temp);
     }
    
    // our answer
    int count = 0;
    
	// accessing tokens from the vector 
    for(auto s : v){
        
        int hyphenCount = 0;
        int punctuationCount = 0;
        bool flag = true;
    
        for(int i = 0; i < s.size(); i++){
            
            // When Digit comes no need to check token further
            if(s[i] >= 48 && s[i] <= 57){
                
                flag = false;
				break;
            }
            
            // When Hyphen comes
            if(s[i] == '-'){
               
                if(hyphenCount >= 1){ // If hyphen occurrs more than once in a single token.
                    
                    flag = false;
                }
                
				// If their is a character before and after hyphen.
                if(i-1 >= 0 && i+1 < s.size()){
                    
					// If lowercase alphabetical characters exists before and after hyphen then increament hyphen else flag = false.
                   if((s[i-1] >= 97 && s[i-1] <= 122 ) && (s[i+1] >= 97 && s[i+1] <= 122 )){
                     hyphenCount++;
                    
                }else{
                    
                      flag = false;
                  }
                    
                }else{ // if hyphen occurrs at the starting or at the end of token.
                    
                    flag = false;
                }
                
            }
            
            if(s[i] == '!' || s[i] == '.' || s[i] == ','){
                
                  if(punctuationCount >= 1){ // If more than punctuations comes in the token.
                      
                      flag = false;
                      
                  }else{
                      
                      if(i == s.size() - 1){  // i.e punctuation  at the end.
                          
                          punctuationCount++;
                          
                      }else{ // punctuation somewhere in the middle which is wrong.
                          
                          flag = false;
                      }
                  }
            }
            
         }
        
        if(flag){
     
             count++;
        }
    }
    
    return count;
    }
};