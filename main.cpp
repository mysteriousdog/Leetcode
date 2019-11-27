

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  Solution *s = new Solution();
  ListNode *head = new ListNode(1);
  ListNode *head1 = new ListNode(2);
  ListNode *head2 = new ListNode(3);
  //ListNode *head3 = new ListNode(4);
  head->next = head1;
  head1->next = head2;
  //head2->next = head3;
  cout<<"start-->"<<" ";
  s->showList(head);
  ListNode * p = s->swapPairs(head);
  cout<<"final-->"<<" ";
  s->showList(p);

  
}
