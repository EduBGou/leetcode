struct Solution;

impl Solution {
    pub fn binary_search_helper(nums: &Vec<i32>, target: i32, start: usize, end: usize) -> i32 {
        let p = (end + start) / 2;

        if nums[p] == target {
            return p as i32;
        }

        if p == start {
            return p as i32 + 1;
        }

        if nums[p] < target {
            return Solution::binary_search_helper(&nums, target, p, end);
        }

        Solution::binary_search_helper(&nums, target, start, p)
    }

    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        if nums[0] > target {
            return 0;
        }
        
        if nums[nums.len() - 1] < target {
            return nums.len() as i32;
        }
        Solution::binary_search_helper(&nums, target, 0, nums.len() - 1)
    }
}

fn main() {
    let ipt = vec![1, 3, 5, 6];
    let target = 4;

    let s = Solution::search_insert(ipt, target);
    println!("solution: {s}");
}
