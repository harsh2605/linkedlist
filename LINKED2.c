//creating linkedlist without using array elemets
#include <stdio.h>
#include <stdlib.h>
int count2 = 0;
struct node
{
    int data;
    struct node *next;
} *head = 0, *temp, *head2 = NULL, *third, *temp1;
void create()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    //head = 0;
    printf("enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void create2() //this is created for the merging purpose
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    //head = 0;
    printf("enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head2 == 0)
    {
        head2 = newnode;
        temp1 = newnode;
    }
    else
    {
        temp1->next = newnode;
        temp1 = newnode;
    }
}
void create3() //creating a linkedlist for circular linkedlist
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    //head = 0;
    printf("enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
}
void display_circular(struct node *p) //displaying the elements of circular queue
{
    int flag = 0;
    printf("the elements of the circular queue are:");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}
void display(struct node *temp) //display elements of the linkedlist
{
    //temp = head;
    if (temp != 0)
    {
        //display(temp->next);
        printf("%d ", temp->data);
        display(temp->next);
    }
}
void count(struct node *p) //count number of nodes in the linkedlist
{
    int count1;
    while (p != 0)
    {
        count1++;
        p = p->next;
    }
    printf("the number of nodes are: %d", count1);
}
int sum(struct node *m) //sum of all the elements of the linkedlist
{
    int sum = 0;
    while (m != 0)
    {
        sum = sum + (m->data);
        m = m->next;
    }
    printf("the sum of all the elements in an linkedlist is:%d", sum);
}
int maxele(struct node *s) //finding the maximum element in the linkedlist
{
    int temp1 = s->data;
    while (s != 0)
    {
        if (temp1 <= s->data)
        {
            temp1 = s->data;
            s = s->next;
        }
        else
        {
            s = s->next;
        }
    }
    printf("the maximum element in a linkedlist is:%d", temp1);
}
int binary(struct node *g, int ele) //searching an element in linkedlist
{
    int count = 0;
    while (g != 0)
    {
        if (g->data == ele)
        {
            printf("element found");
            count++;
            break;
        }
        else
        {
            g = g->next;
        }
    }
    if (count == 0)
    {
        printf("element not found");
    }
}
int insert(struct node *p, int pos, int extra)// this function insert a node to a existing linked list
{
    struct node *t, *newnode;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = extra;
    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int last(struct node *p, int key)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node *));
    t->next = NULL;
    t->data = key;
    temp->next = t;
}
int insert_sort(struct node *p, int key) //insert an elemnt in the sorted linkedlst
{
    struct node *t, *q;
    q = NULL;
    while (p && p->data < key)
    {
        q = p;
        p = p->next;
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->next = q->next;
    q->next = t;
}
int delete_ele(struct node *p, int positon) //for deleting an element from the linked list
{
    struct node *q;
    int x = -1;
    if (positon == 1)
    {
        q = head;
        head = head->next;
        x = q->data;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < positon - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int check_sort(struct node *p) //whether the linkedlist is in sorted order or not
{
    int x = -32768;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
int remove_repeated_ele(struct node *p) //print the repeated element only once from the linkedlist
{
    struct node *q;
    q = p->next;
    int x = -1;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            //x = q->data;
            p->next = q->next;
            free(q);
            q = p->next;

            //return x;
        }
    }
}
int reverse(struct node *p) //reversing the element of the linkedlsit by using an another array
{
    int store[5];
    int i = 0;
    while (p != 0)
    {
        store[i] = p->data;
        i++;
        p = p->next;
    }
    p = head;
    i--;
    while (p != 0)
    {
        p->data = store[i];
        i--;
        p = p->next;
    }
}
void reverse_link(struct node *p) //reversing a linkedlist without using any another array
{
    struct node *q, *r;
    q = NULL;
    r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void rec_reverse(struct node *q, struct node *p)//reverse a linkedlist using recursion
{
    if (p != NULL)
    {
        rec_reverse(p, p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
}
void deleteAlt(struct node *head)
{
    // Code here
    struct node *q, *p;
    p = head;
    q = head;
    p = p->next;
    while (p != 0 && q != 0)
    {
        q->next = p->next;
        free(p);
        q = q->next;
        //if(q!=NULL)
        p = q->next;
    }
}
void middle(struct node *p, int x) //insert a element in the middle of the linkedlist
{
    struct node *q, *t;
    q = head;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    int count = 0;
    while (q != 0)
    {
        count++;
        q = q->next;
    }
    q = head;
    if (count % 2 == 0)
    {
        int mid = count / 2;
        for (int i = 0; i < mid - 1; i++)
        {
            q = q->next;
        }
        t->next = q->next;
        q->next = t;
    }
    else
    {
        int mid = count / 2;
        for (int i = 0; i < mid; i++)
        {
            q = q->next;
        }
        t->next = q->next;
        q->next = t;
    }
}
int modular(struct node *head, int k) //it is return the number which satisfies the condition from the last (i%k==0)
{
    int res = 0, count = 0;
    while (head != NULL)
    {
        count++;
        if (count % k == 0)
        {
            res = head->data;
            head = head->next;
        }
        else
        {
            head = head->next;
        }
    }
    return res;
}
void merge_linkedlist(struct node *first, struct node *second) //code to merge two linkedlist in sorted order
{
    struct node *last;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        third->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
}
void delete_middle(struct node *p)//deleting an element from the middle of the linkedlist
{
    struct node *q;
    // p=head;
    q = NULL;
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    p = head;
    int pos;
    pos = count / 2;
    for (int i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}
int delete_circular(int pos)//deleting a element in circular linkedlist
{
    int x;
    struct node *q, *p;
    if (pos == 1)
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        if (p == head)
        {
            x = head->data;
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next;
        }
        return x;
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
        return x;
    }
}
int main()

{
    int element, pos, extra, circular_pos;
    /* for (int i = 0; i < 5; i++)
    {
        create();
    }
    printf("the elements in a linked list are:");
    display(head);
    printf("\n");*/
    /* count(head);
    printf("\n");
    sum(head);
    printf("\n");
    maxele(head);
    printf("\n");
    printf("enter the element to be searched:");
    scanf("%d", &element);
    binary(head, element);
    printf("\n");
    printf("enter the position in which element to be entered:");
    scanf("%d", &pos);
    printf("\n");
    printf("entre the extra element to be inserted in the linkedlist:");
    scanf("%d", &extra);
    insert(head, pos, extra);
    printf("\n");
    display(head);
    printf("\n");
    last(head, 8);
    display(head);
    int key;
    printf("\n enter the element to be inserted:");
    scanf("%d", &key);
    insert_sort(head, key);
    display(head);
    int position;
    printf("\n enter the position of element to be deleted:");
    scanf("%d", &position);
    printf("%d ", delete_ele(head, position));
    printf("\n");
    printf("the elements after deleting the element are:\n");
    display(head);
    printf("%d", check_sort(head));
    printf("\n");
    printf("%d", remove_repeated_ele(head));
    printf("\n");
    display(head);
    printf("\n");
    reverse(head);
    display(head);
    printf("\n");
    reverse_link(head);
    display(head);
    rec_reverse(NULL,head);
    display(head);
    deleteAlt(head);
    display(head);
    middle(head,18);
    display(head);
    printf("%d",modular(head,2));*/
    /*for (int i = 0; i < 3; i++)
    {
        create2();
    }
    printf("the elements in a linked list are:");
    display(head2);
    printf("\n");
    printf("the merged linked list in sorted order is:");
    merge_linkedlist(head, head2);
    display(third);
    for (int i = 0; i < 5; i++)
        create3();
    display_circular(head);
    delete_middle(head);
    printf("the elements after deletion of the middle term:");
    display(head);*/
    for (int i = 0; i < 5; i++)
    {
        create3();
    }
    display_circular(head);
    printf("\n");
    printf("enter the position of the element to be deleted from the circular linkedlist:");
    scanf("%d", &circular_pos);
    printf("\n");
    delete_circular(circular_pos);
    display_circular(head);
}
