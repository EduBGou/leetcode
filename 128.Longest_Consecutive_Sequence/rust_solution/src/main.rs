use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let hs: HashSet<i32> = nums.into_iter().collect();
        let mut max_count = 0;

        for &n in &hs {
            if hs.contains(&(n - 1)) {
                continue;
            }
            let mut current = n;
            let mut count = 1;
            while hs.contains(&(current + 1)) {
                current += 1;
                count += 1;
            }
            if count > max_count {
                max_count = count;
            }
        }
        max_count
    }
}

fn main() {}
