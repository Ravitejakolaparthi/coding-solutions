class Solution {
public:
    int timetos(string num)
    {
        int sec = stoi(num.substr(0,2))*3600+stoi(num.substr(3,2))*60+stoi(num.substr(6,2));
        
        return sec;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
       
        return  abs(timetos(startTime) - timetos(endTime));
        
    }
};