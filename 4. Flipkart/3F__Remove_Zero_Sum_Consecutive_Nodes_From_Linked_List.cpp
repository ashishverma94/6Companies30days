/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mymap;
        ListNode* dummy = new ListNode(0) ;
        dummy -> next = head ;
        mymap[0] = dummy ;
        int sum = 0;
        ListNode* p = head ;
        
        while( p){
            sum += p->val;
            if ( mymap.find(sum) != mymap.end() ){
                ListNode* start = mymap[sum] ;
                int tot = sum ;
                while( start != NULL and start != p ){
                    start = start->next ;
                    tot += start->val ;
                    if ( start != p )
                        mymap.erase(tot) ;
                }
                mymap[sum]->next = p->next ;
            }
            else
            mymap[sum] = p ;
            p = p->next ;
        }

        return dummy->next  ;
    }
};
