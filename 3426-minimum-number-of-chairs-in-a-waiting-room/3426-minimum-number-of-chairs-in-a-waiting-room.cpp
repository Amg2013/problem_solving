class Solution {
public:
    int minimumChairs(string s) {
     int count  =0 ; 
      int max_people = 0; 
     for(int i =0 ; i< s.size(); i++){
        if(s[i]== 'E') count ++; 
         else if(s[i]== 'L' ) count -- ;
    // Update peak occupancy if needed
            if (count > max_people) 
                max_people = count;
    
     }   
     return max_people ;
    }
};