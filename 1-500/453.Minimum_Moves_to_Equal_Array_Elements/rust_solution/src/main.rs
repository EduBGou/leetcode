struct Solution;

impl Solution {

    pub fn min_moves(nums: Vec<i32>) -> i32 {
        
        if nums.len() <= 1 {
            return 0;
        }

        let mut clone_nums = nums.clone();

        clone_nums.sort();
        
        let mut moves = 0;
        let mut inc = 0;
        
        let mut i = 1;
        while i < nums.len() {
            inc += (clone_nums[i - 1] - clone_nums[i]).abs();

            if inc != 0{
                moves += inc;
            }

            i += 1;
        }
        moves
    }
}

fn main() {
    let ipt = vec![2, 4, 1, 2, 10];
    let s = Solution::min_moves(ipt);
    println!("{s}");
}
