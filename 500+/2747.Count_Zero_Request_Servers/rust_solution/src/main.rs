struct Solution;

impl Solution {
    pub fn count_servers(n: i32, logs: Vec<Vec<i32>>, x: i32, queries: Vec<i32>) -> Vec<i32> {
        
        use std::collections::HashMap;
        let mut dict: HashMap<i32, (i32, i32)> = HashMap::new();

        for pair in logs {
            let entry = dict.entry(pair[0]).or_insert((pair[1], pair[1]));

            if pair[1] < entry.0 {
                entry.0 = pair[1];
            } else if pair[1] > entry.1 {
                entry.1 = pair[1];
            }
        }

        let mut out = vec![n - dict.len() as i32; queries.len()];

        for (idx, q) in queries.iter().enumerate() {
            let int_l = q - x;

            for (_, value) in &dict {
                if int_l <= value.1  && value.0 <= *q  {
                    continue;
                }
                out[idx] += 1;
            }
        }

        out
    }
}

fn main() {

    println!("{:?}", Solution::count_servers(3, vec![vec![1,3],vec![2,6],vec![1,5]], 5, vec![10,11]))
}
