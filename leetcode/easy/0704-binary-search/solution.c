int search(int* nums, int numsSize, int target)
 {
   int i=0;
    while(numsSize--)
    {
       if(target == nums[i]) 
        return i;
       i++;
    }
     return -1;
}