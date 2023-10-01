class Solution {
public:
       int minOperations(int n) {
                      
     int steps=0;
     while(n!=0){
         
         int x=floor(log2(n));
         int y=ceil(log2(n));
         
         if( (n - pow(2,x)) <= (pow(2,y) - n ) )  
             n=n-pow(2,x);
         else                                    
             n=pow(2,y)-n;
            
        steps++;  
     }
       
     return steps;
   
    }
};