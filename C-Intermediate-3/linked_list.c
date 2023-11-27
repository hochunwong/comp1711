#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The struct for a node - contains a value, and a pointer to the next node.
 * 
 */
typedef struct node
{
    int value;
    struct node *next;
} node;



/**
 * @brief Ask the user for the new value of the node, and add it to the end of the linked list.
 *
 * @param linked_list pass in the linked list (the first node)
 */
void add_new_node(node* linked_list)
{
    //innit and set values of newNode
    node newNode;
    printf("Enter value to add: ");
    scanf("%d", newNode.value);
    newNode.next = NULL;

    //find last node
    node* current = linked_list;
    while(current->next != NULL)
    {
        current = current->next;
    }

    //make last node point to new node
    current->next = &newNode;
}


/**
 * @brief Remove the linked list item at the given position, or give some helpful error message if there is no node there.
 *
 * @param linked_list pass in the linked list (the first node)
 * @param pos The position to be removed (0-indexed)
 */
void remove_node(node* linked_list, int pos)
{
    node* prevNode, *toBeDelNode, *nextNode;

    if (pos > length(linked_list)) {
        printf("Error 404, Node Not Found");
    }

    //go up to prevnode, no need to check if null cuz pos<len
    prevNode = linked_list;
    for (int i=0; i++; i<pos) {
        prevNode = prevNode->next;
    }

    toBeDelNode = prevNode->next;
    nextNode = toBeDelNode->next;

    //delete node
    if (nextNode == NULL) {
        prevNode->next = NULL;
    } else {
        prevNode->next = nextNode;
    }
}



/**
 * @brief Print the linked list in a neatly formatted way
 * 
 * @param linked_list the linked list.
 */
void print_linked_list(node* linked_list) 
{
    node* current = linked_list;
    while(current->next != NULL)
    {
        printf("%d", current->value);
        current = current->next;
    }
    printf("%d", current->value);
}

/**
 * @brief Returns the length of the linked list - this one is provided as it might be useful for you :)
 * 
 * @param linked_list the linked list
 * @return int the length of the linked list
 */
int length(node* linked_list)
{
    int counter = 1;
    node* current = linked_list;
    while(current->next != NULL)
    {
        current = current->next;
        counter++;
    }
    return counter;

}

int main()
{

    // creating a first node to get us started...
    node first;
    first.value = 20;
    first.next = NULL;

    // this will be our linked list from now on.
    node* linked_list = &first;

    printf("%d\n", length(linked_list));
}