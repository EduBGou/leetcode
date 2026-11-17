// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]

pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution;

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut merged: Vec<i32> = Vec::new();

        for op in &lists {

            let Some(head) = op else {
                continue;
            };

            let mut current = Some(head.as_ref());

            while let Some(node) = current {
                merged.push(node.val);
                current = node.next.as_deref();
            }
            
        }
        merged.sort();

        let mut head = None;

        for value in merged.into_iter().rev(){
            head = Some(Box::new(ListNode{next: head, val:value})); 
        }

        head
    }
}

fn main() {
    let s = Solution::merge_k_lists(vec![Some(Box::new(ListNode::new(9)))]);
    println!("{:?}", s);
}
