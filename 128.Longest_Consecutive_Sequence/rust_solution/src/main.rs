struct Solution;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        let largest = *nums.iter().max().unwrap();
        let smaller = *nums.iter().min().unwrap();

        let range_size = largest.abs_diff(smaller) + 1;

        let mut v: Vec<u8> = vec![0; range_size as usize];

        for n in nums {
            v[(n - smaller) as usize] = 1;
        }
        let mut longest_consecutive = 0;
        let mut longest_temp = 0;

        for i in v.iter() {
            if *i == 0 {
                longest_temp = 0;
                continue;
            }
            
            longest_temp += 1;
            if longest_temp > longest_consecutive {
                longest_consecutive = longest_temp;
            }
        }

        longest_consecutive
    }
}

fn main() {
    let ipt = vec![100, 4, 200, 1, 3, 2];
    println!("ipt: {:?}", ipt);

    let s = Solution::longest_consecutive(ipt);
    println!("solution: {s}");
}
