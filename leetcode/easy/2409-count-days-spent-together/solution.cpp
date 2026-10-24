class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        map<int,int>Info1 = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        pair<int,int> Alicestartmonth = {0,0};
        pair<int,int> Aliceendmonth ={0,0};
        pair<int,int> Bobstartmonth = {0,0};
        pair<int,int> Bobendmonth = {0,0};
        
        Alicestartmonth = {(arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0'),(arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0')};
        Bobstartmonth = {(arriveBob[0]-'0')*10 + (arriveBob[1]-'0'),(arriveBob[3]-'0')*10 + (arriveBob[4]-'0')};

        Aliceendmonth = {(leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0'),(leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0')};
        Bobendmonth = {(leaveBob[0]-'0')*10  + (leaveBob[1]-'0'),(leaveBob[3]-'0')*10  + (leaveBob[4]-'0')};
        
        if (Aliceendmonth < Bobstartmonth || Bobendmonth < Alicestartmonth)
            return 0;

        pair<int,int>start = {0,0};
        if(Alicestartmonth.first > Bobstartmonth.first || (Alicestartmonth.first == Bobstartmonth.first && Alicestartmonth.second > Bobstartmonth.second)){
            start = Alicestartmonth;
        }else{
            start = Bobstartmonth;
        }
        
        pair<int,int>end={0,0};
        if(Aliceendmonth.first < Bobendmonth.first || (Aliceendmonth.first == Bobendmonth.first && Aliceendmonth.second < Bobendmonth.second)){
            end = Aliceendmonth;
        }else{
            end = Bobendmonth;
        }
        
        if(start.first == end.first){
            return end.second - start.second + 1;
        }
        
        int days = 0;
        days = Info1[start.first] - start.second + 1;
        for(int i = start.first + 1; i < end.first; i++){
            days += Info1[i];
        }
        days += end.second;
        return days;
    }
};
