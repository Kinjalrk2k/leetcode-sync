/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *new_head = NULL, *old_curr = head, *new_curr;
        unordered_map<Node*,Node*> nodes_map;

        while(old_curr) {
            if(!new_head){
                new_head = new Node(old_curr->val);
                new_curr = new_head;
            }
            else {
                new_curr->next = new Node(old_curr->val);
                new_curr = new_curr->next;
            }
            nodes_map[old_curr] = new_curr;
            old_curr = old_curr->next;
        }

        old_curr = head;
        new_curr = new_head;
        while(old_curr) {
            if(!old_curr->random) {
                new_curr->random = NULL;
            } else {
                new_curr->random = nodes_map[old_curr->random];
            }
            old_curr = old_curr->next;
            new_curr = new_curr->next;
        }

        return new_head;
    }
};