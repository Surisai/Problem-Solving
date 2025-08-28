#include <iostream>
using namespace std;
// A palindrome is something that reads the same forward and backward.
// For numbers:

// 121 → forward 121, backward 121 → ✅ palindrome

// 1221 → forward 1221, backward 1221 → ✅ palindrome

// 123 → forward 123, backward 321 → ❌ not palindrome

// For words/strings:

// "madam" → same forward/backward → ✅ palindrome

// "racecar" → ✅ palindrome

// "hello" → ❌ not palindrome


//Fisr solution Math logic needed O(1)constance
class Solution{
    public :
    bool isPalindrome(int x){
        /// no nagative and numbers ending with 0 but not equal to 0 are not palindrom
        if( x < 0 || (x % 10 == 0 && x != 0)) return false;

         int reve = 0; // 
         //reverse only ha;f of the number
         while(x > reve){
            reve = reve * 10 + x % 10; // 
            x /= 10; //remove last digit from x
         }
         //even digit or add digit 
         return (x == reve || x == reve / 10);
    }
};
//
// bool isPalindrome(int x) {
//     if (x < 0) return false;
//     string s = to_string(x);
//     int l = 0, r = s.size() - 1;
//     while (l < r) {
//         if (s[l] != s[r]) return false;
//         l++; r--;
//     }
//     return true;
// }

int main(){

    Solution sol;

    cout << boolalpha; //Print true /false instead of 1/0;

    cout << "121  -> " << sol.isPalindrome(121) << endl;
    cout << "-121 -> "<< sol.isPalindrome(-121) << endl;
    cout << "0  -> "<< sol.isPalindrome(0) << endl;
    cout << "123421 -> "<< sol.isPalindrome(123421) << endl;
    cout << "1221 -> "<< sol.isPalindrome(1221) << endl; 
    return 0;

}