class Solution {
public:
    int vowel(char n)
    {
        if(n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')
        {
            return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int vowels = 0;
        for(int i = 0;i<k;i++)
        {
             vowels+=vowel(s[i]);
        }
        int currvowels = vowels;
        for(int i = k;i<s.size();i++)
        {
            vowels += vowel(s[i]);
            vowels += -1*vowel(s[i-k]);
            currvowels  = max(currvowels,vowels); 
        }
        return currvowels;

    }
};