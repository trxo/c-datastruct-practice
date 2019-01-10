#include <iostream>
#include <malloc.h>
typedef int ElementType;

typedef struct Node{
    ElementType element;
    Node *next;
} Node;


typedef struct {
    Node *head;
} LinkList;

LinkList* newLink(){
    LinkList *l = (LinkList*)malloc(sizeof(LinkList));
    l->head = nullptr;
    return l;
};

void insert(LinkList *l,ElementType e){
    Node *n = (Node*)malloc(sizeof(Node));
    n->next = nullptr;
    n->element = e;
    if (l->head == nullptr){
        l->head = n;
        return;
    }
    Node *ptr = l->head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = n;
};

void printLinkList(LinkList *l){
    Node *ptr = l->head;
    while (ptr != nullptr){
        printf("current node is %d\n",ptr->element);
        ptr = ptr->next;
    }
}

int main() {
    LinkList *l = newLink();
    insert(l,1);
    insert(l,2);
    insert(l,3);
    printLinkList(l);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}