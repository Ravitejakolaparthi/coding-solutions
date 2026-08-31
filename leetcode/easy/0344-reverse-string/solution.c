void reverseString(char* s, int sSize) {
    
    int i;
    for(int i=0;i<sSize;i++)
    {
        char temp;
         temp =   s[sSize-1];
         s[sSize-1] =  s[i];
         s[i] =  temp;
        sSize--;
    }
}