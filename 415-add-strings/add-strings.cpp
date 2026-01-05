class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        string res = "";
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
                
                long sum = 0;
                
                if(i >= 0){sum += (num1[i] - '0');i--;}
                if(j >= 0){sum += (num2[j] - '0');j--;}
                
                sum += carry; 
                
                carry = sum/10;
                sum = sum % 10;
                res += to_string(sum);
                
                //carry += sum/10 -'0';
                
                //res += sum%10 -'0';
            }
       
        reverseStr(res);
        return res;
    }
    
    void reverseStr(string& str) 
    { 
        int n = str.length(); 

        // Swap character starting from two 
        // corners 
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 
};