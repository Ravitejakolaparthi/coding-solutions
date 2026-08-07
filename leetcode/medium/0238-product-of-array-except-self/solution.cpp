class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            vector<int>prefix_product(nums.size());
            prefix_product[0] = 1;
            int right_product_to_i = 1;
            for(int i = 1;i<=nums.size()-1;i++)
                prefix_product[i] =prefix_product[i-1] * nums[i-1];
            for(int i = prefix_product.size()-1;i>0;i--)
            {
                prefix_product[i] *=right_product_to_i;
                right_product_to_i *= nums[i];
            }
            prefix_product[0]=right_product_to_i;
            return prefix_product;

    }
};