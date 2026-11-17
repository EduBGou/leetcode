struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {

        let mut s = x.to_string();
        let mut chars: Vec<char> = s.chars().collect();
        
        let mut start = 0;

        if chars[0] == '-' {
            start = 1;
        }

        for i in start..((chars.len()) as f64 / 2.0).ceil() as usize {
            let temp = chars[i];

            let compl_i =  start + chars.len() - (i+1);
            chars[i] = chars[compl_i];
            chars[compl_i] = temp;
        }
        s = chars.into_iter().collect();
        s.parse::<i32>().unwrap_or(0)
    }
}

fn main() {
    println!("{}", Solution::reverse(-10));
}
