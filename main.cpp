

#include"main.h"




int main(){

  ListNode *head = Tool::buildList();
  Tool::showList(head);
  Solution *s = new Solution();
  int m,n;
  cin>>m>>n;
  head = s->reverseBetween(head,m,n);
  Tool::showList(head);
  return 0;
}
  

