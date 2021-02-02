Node* reverse(Node* head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}


Node* add_one(Node* head)
{
    int sum=0;
    int carry=1;
    Node* curr=head;
    Node* temp=head;
    Node* res=head;
    while(head!=NULL)
    {
        sum=(head?head->data:0)+carry;
        carry=(sum>=10?1:0);
        sum=sum%10;
        head->data=sum;
        temp=head;
        head=head->next;
    }
    if(carry>0)
    {
        temp->next=new Node(carry);
    }
    return res;
}


Node* addOne(Node *head) 
{
   if(!head)
   {
       return NULL;
   }
   head=reverse(head);
   head=add_one(head);
   head=reverse(head);
   return head;
}
