struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut p1 = 0;
        let mut p2 = 0;
        let nums_len = nums1.len() + nums2.len();

        if nums_len == 0 {
            return 0.0;
        }

        let mut nums = vec![0; nums_len];

        while p1 + p2 < nums.len() {
            if p1 == nums1.len() {
                nums[p1 + p2] = nums2[p2];
                p2 += 1;
            } else if p2 == nums2.len() || nums1[p1] <= nums2[p2] {
                nums[p1 + p2] = nums1[p1];
                p1 += 1;
            } else {
                nums[p1 + p2] = nums2[p2];
                p2 += 1;
            }
        }
        let med_idx = (nums.len() as f64 - 1.0) / 2.0;
        let med_idx_l = med_idx.floor() as usize;
        let med_idx_r = med_idx.ceil() as usize;
        (nums[med_idx_l] + nums[med_idx_r]) as f64 / 2.0
    }
}

fn main() {
    println!("{}", Solution::find_median_sorted_arrays(vec![0,2,9], vec![1, 4]));
}
