void Optimised_bubble_Sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i >= 1; i--)
    {
        int flag = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}
int main()
{
    vector<int> nums = {
        1, 2, 3, 4, 5};
    Bubble_Sort(nums);
    Optimised_bubble_Sort(nums);
    for (auto it : nums)
        cout << " " << it;
    return 0;
}