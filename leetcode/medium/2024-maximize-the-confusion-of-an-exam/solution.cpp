class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        string str = answerKey;
            int countT = 0;
            int countF = 0;
            int i = 0;
            int j = 0;
            int len = 0;
            int end = str.length();

            while (i < end) {
                
                if (str[i] == 'T') {
                    countT++;
                } else if (str[i] == 'F') {
                    countF++;
                }
                i++;

                while (countT > k && countF > k) {
                    if (str[j] == 'T') {
                        countT--;
                    } else if (str[j] == 'F') {
                        countF--;
                    }
                    j++;
                }

                len = max(len, (countT + countF));
            }
            return len;
    }
};