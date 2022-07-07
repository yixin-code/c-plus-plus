//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//
//示例 1：
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//示例 2：
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
//示例 3：
//输入：nums = [3, 3], target = 6
//输出：[0, 1]
//
//提示：
//2 <= nums.length <= 104
//- 109 <= nums[i] <= 109
//- 109 <= target <= 109
//只会存在一个有效答案
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> um;
		size_t size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			// target依次与数组中的元素相减得到所需的值
			// 查找得到的值在哈希表中是否存在
			int res = target - nums[i];
			// 查找是否存在res
			if (um.count(res))
			{
				return { um[res], i };
			}
			um.emplace(nums[i], i);
		}
		return { 0, 0 };
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 2, 7, 11, 15 };
	auto res = s.twoSum(nums, 9);
	cout << res[0] << " " << res[1] << endl;

	nums = { 3, 2, 4 };
	res = s.twoSum(nums, 6);
	cout << res[0] << " " << res[1] << endl;

	nums = { 3, 3 };
	res = s.twoSum(nums, 6);
	cout << res[0] << " " << res[1] << endl;

	return 0;
}
