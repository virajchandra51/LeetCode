class Solution {
public:
    bool validUtf8(vector<int> &data){
  
    int num = data.size(); 
	// for the vector size
    int check = 0;   
	// first Initialize check with zero , it will count the number of 10xx sequence need to be find.
    for (int i = 0; i < num; i++){    
	
      int temp = data[i]; 
	  // travesing on each value
      if (check==0){ 
	  // if check ==0 we will check the number of bytes
	  // we are dividing here for the right shift like n/32 is n>>5 and we are checking the left 3 digits.
        if ((temp/32) == 0b110) 
		// if the 8-5=3 digit is 110(from the start) it means it is 2 bytes so we need n-1 i.e 1 10xx sequence so check =1
          check = 1; 
		 
        else if ((temp/16) == 0b1110)
		// if the 8-4=4 digit is 1110(from the start) it means it is 3 bytes so we need n-1 i.e 2 10xx sequence so check =2
          check = 2; 
	
        else if ((temp /8) == 0b11110)
          check = 3; 
	
        else if ((temp /128))
		//if the 8-7=1 digit is 1(from the start) we return false
          return false; 
      }
      else{
	
        if ((temp /64) != 0b10)
          return false; 
        check--;        
      }
    }
    return (check == 0); 
  }
    
};