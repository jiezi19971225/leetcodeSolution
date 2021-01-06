/*
 * @lc app=leetcode id=1 lang=javascript
 *
 * [1] Two Sum
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

nums = [3, 2, 4];
target = 6;

var twoSum = function (nums, target) {
  let map = new Map();
  let res = [];
  nums.forEach(function (val, key) {
    map.set(val, key);
  });
  nums.some(function (val, key) {
    need = target - val;
    needPos = map.get(need);
    if (needPos != undefined && key != needPos) {
      res = [key, needPos];
      return true;
    }
  });
  console.log(res);
  return res;
};

twoSum(nums, target);
