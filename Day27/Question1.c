#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find intersection by comparing values
int findIntersection(struct Node *head1, struct Node *head2) {
    while (head1 != NULL) {
        struct Node *temp = head2;

        while (temp != NULL) {
            if (head1->data == temp->data)
                return head1->data;
            temp = temp->next;
        }

        head1 = head1->next;
    }

    return -1;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insert(&head2, x);
    }

    int ans = findIntersection(head1, head2);

    if (ans == -1)
        printf("No Intersection");
    else
        printf("%d", ans);

    return 0;
}