/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const obj={};
    for(let idx=0;idx<nums.length;idx++){
        if((target-nums[idx]) in obj){
            return [obj[target-nums[idx]], idx];
        }else{
            obj[nums[idx]]=idx;
        }
    }
    return [-1, -1];
};