#include <stdio.h>
#include <stdlib.h>

#define BUFFER_COUNT 5

struct buffer *create_free_list(struct buffer *, int);
void display_free_list_forward(struct buffer *);
void display_free_list_reverse(struct buffer *);

struct buffer
{
    int data;
    unsigned short device_num;
    unsigned short block_num;
    unsigned short status;
    char _data[1024];
    struct buffer *next; // pointer to next buffer on free list
    struct buffer *prev; // pointer to prev buffer on free list
    struct buffer *n_hq; // pointer to next buffer on hash queue
    struct buffer *p_hq; // pointer to prev buffer on hash queue
};


int main()
{
    struct buffer *fhead;
    fhead = NULL;
    fhead = create_free_list(fhead, BUFFER_COUNT);
    display_free_list_forward(fhead);
    display_free_list_reverse(fhead);
    return 0;
}

void display_free_list_forward(struct buffer *fhead)
{
    struct buffer *p;
    p = fhead;
    printf("fhead");
    do
    {
        printf("-> %d",p->data);
        p = p -> next;
    }while(p != fhead);
    printf("-> fhead\n");
}

void display_free_list_reverse(struct buffer *fhead)
{
    struct buffer *p;
    p = fhead;
    printf("fhead");
    do
    {
        printf("-> %d",p->data);
        p = p -> prev;
    }while(p != fhead);
    printf("-> fhead\n");
}

struct buffer *create_free_list(struct buffer *fhead, int count)
{
    int i, data;
    struct buffer *p, *q;
    for(i = 0 ; i < count ; i++)
    {
        printf("Enter data : ");
        scanf("%d", &data);
        if(i == 0)
        {
            fhead = p = q = (struct buffer*)malloc(sizeof(struct buffer));
            p -> data = data;
            p -> next = NULL;
            p -> prev = NULL;
        }
        else
        {
            q -> next = p = (struct buffer*)malloc(sizeof(struct buffer));
            p -> prev = q;
            p -> data = data;
            p -> next = NULL;
            q = p;
        }
    }
    p -> next = fhead;
    fhead -> prev = p;
    return fhead;
}

