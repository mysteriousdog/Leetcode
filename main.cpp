

#include"main.h"




int main(){

  ListNode* head = Tool::buildList();
  Solution *s = new Solution();
  head = s->deleteDuplicates(head);
  Tool::showList(head);
  return 0;
}
  
