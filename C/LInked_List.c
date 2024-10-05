#include <stdio.h>
#include <stdlib.h>
// creating Node data type
struct node{
    int value;
    struct node *next;
};
typedef struct node Node;


void inint(Node *st){

    st->value= -00007;
    st->next= NULL;
}

// fuction to attach new node to the linked list
Node* INSERT(Node *pre, int value){
    Node *new;
    new = (Node * )malloc(sizeof(Node));
    pre->next=new;
    new->value=value;
    new->next=NULL;
}

// fuction to remove node from linked list
void DELETE(Node *st,int value){
    Node *pre,*cu,*next;
    pre=st;
    cu=st->next;
    next = cu->next;
    int status = 0;
    while(status != 1){
        if(cu->value == value)
        {
            pre->next=cu->next;
            printf("Your Node has been deleted successfully form Linked List.\n");
            status = 1;
        }
        else{
            pre= cu;
            next= cu->next;
            cu=next;
        }
    }
}

// fuction to display linked list's elements
void DISPLAY(Node *st){
    Node *pre,*new;
    pre=st;
    if(pre->next == NULL){
        printf("Your Linked List is Empty.\n");
        return;
    }
    int status = 1;
    printf("Elements : ");
    while(pre->next != NULL){
        new=pre->next;
        printf("%d ",new->value);
        pre=new;
    }
    printf("\n");
}

void SEARCH(Node *st,int value){
    int count=0,status =0;
    Node *pre,*new;
    pre = st;
    while(new->next !=NULL){
        count ++;
        new=pre->next;
        if(new->value == value){
            printf("%d is found in node no %d\n",value,count);
            return;
        }
        pre=new;
    }
    printf("%d not found in Linked List.\n",value);

}

int main(){
    Node *start,*new,*prev;

    inint(start);
    prev= start;
    
    int select =0,n,value;
    while ( select !=5){
        printf("\n1.To Add Node in Linked List\n2.To Delete Node From Linked List\n3.To search Node in Linked List\n4.To Display Linked List\n5.Exit\nAns : ");
        scanf("%d",&select);
        printf("\n");
        switch (select)
        {
        case 1:
            printf("How many Node do you want to enter?\nANS: ");
            scanf("%d",&n);
            printf("\n");

            for(int i=0;i<n;i++){
                printf("Enter the value : ");
                scanf("%d",&value);
                new = INSERT(prev,value);
                prev=new;
            }
            printf("\n");
            break;

        case 2:
            printf("Enter the Node value which you want to delete : ");
            scanf("%d",&value);
            DELETE(start,value);
            break;
        case 3:
            printf("Enter the Node value which you want to search : ");
            scanf("%d",&value);
            SEARCH(start,value);
            break;
        case 4:
            DISPLAY(start);
            break;
        case 5:
            printf("Exit successfully");
            break;
        default:
            printf("You entered worng number!\nEnter valid number\n");
            break;
        }
    }
    return 0;
}
