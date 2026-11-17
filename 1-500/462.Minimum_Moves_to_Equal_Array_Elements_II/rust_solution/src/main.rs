struct Solution;

impl Solution {
    pub fn min_moves2(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 {
            return 0;
        }

        let mut clone_nums = nums.clone();
        clone_nums.sort();

        let med = clone_nums[clone_nums.len()/2];

        let mut moves = 0;
        for n in clone_nums {
            moves += (n - med).abs();
        }
        moves
    }
}

fn main() {
    let ipt = vec![1,10,2,9];
    let s = Solution::min_moves2(ipt);
    println!("{s}");
}
