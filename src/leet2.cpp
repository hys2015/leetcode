#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pn1 = l1,*pn2 = l2;
        ListNode *ps = NULL,*old = NULL; // sum nodelist : old -> next ==> ps
        ListNode *psum = NULL;          //return Pointer
        while( pn1 && pn2){
            ps = new ListNode(pn1 -> val + pn2 -> val);
            if(!psum) psum = ps;
            if(old){
                old -> next = ps;
            }
            old = ps;
            pn1 = pn1 -> next;
            pn2 = pn2 -> next;
        }
        while( pn1 ){
            ps = new ListNode(pn1 -> val);
            if(old){
                old -> next = ps;
            }
            old = ps;
            pn1 = pn1 -> next;
        }
        while( pn2 ){
            ps = new ListNode(pn2 -> val);
            if(old){
                old -> next = ps;
            }
            old = ps;
            pn2 = pn2 -> next;
        } 
        ListNode *p = psum;
        int car = 0;
        while( p ){
            p -> val += car;
            car = 0;
            if( p -> val > 9){
                p -> val -= 10;
                car = 1;                
            }
            old = p;
            p = p -> next;
        }
        if(car){
            p = new ListNode(1);
            old -> next = p;
        }
        return psum;
    }
};

ListNode* buildUpList(string s){
	ListNode *cur = NULL, *old = NULL;
	ListNode *ret = NULL;
	for(int i = s.size() - 1 ; i >= 0 ; --i){
		cur = new ListNode(s[i] - '0');
		if(!ret) ret = cur;
		if(old){
			old -> next = cur;
		} 
		old = cur;
	}
	return ret;
}

void printList(ListNode* list){
	ListNode *p = list;
	while( p ){
		cout<< p -> val;
		p = p -> next;
	}
	cout<<endl;
}

int main(){
	ListNode *list1 = NULL,*list2 = NULL;
	Solution s;
	list1 = buildUpList("9");
	list2 = buildUpList("5");
	printList(list2);
	ListNode *sum = s.addTwoNumbers(list1,list2);
	printList(sum);
} 
