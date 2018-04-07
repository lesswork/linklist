/** Includes */
#include "linklist.h"

/**********************************************************************/
/**********************************************************************/
                    /** Staic and Global variables */
/**********************************************************************/
/**********************************************************************/
static int debug_level = 0;

void set_debug_level(int level)
{
    debug_level = level;
}

/**********************************************************************/
/**********************************************************************/
            /** All singly linklist implementation */
/**********************************************************************/
/**********************************************************************/
Node* createNode()
{
    Node* node = (Node*) malloc (sizeof (Node));
    if(node != NULL)
    {
        linklist_dbg_log_args("List created : %p", node);
        node->data = 0;
        node->next = NULL;
        return node;
    }
    return NULL;
}

e_retResult deleteNode(Node* node)
{
    e_retResult result = result_notSet;
    if(node != NULL)
    {
        free(node);
        node = NULL;
    }
    else
    {
        result = result_error;
    }
    return result_success;
}

Node* getTail(Node* node)
{
    if(node == NULL)
        return NULL;
    else if(node->next == NULL)
    {
        return node;
    }
    else
    {
        while(node->next != NULL)
        {
            node = node->next;
        }
        return node;
    }
}

int getLength(Node* node)
{
    int length = 0;
    if(node == NULL)
        return 0;

    while(node != NULL)
    {
        length++;
        node = node->next;
    }
    return length;
}

e_retResult push(USER_DATA info, Node** head)
{
    linklist_dbg_log_args("%s", __FUNCTION__);
    Node* lastNode = NULL;

    if(lastNode = getTail(*head), lastNode != NULL)
    {
        if(lastNode->next = createNode(), lastNode->next != NULL)
        {
            lastNode->next->data = info;
            lastNode->next->next = NULL;
            linklist_dbg_log_args("Data : %d", info);
            return result_success;
        }
        else
        {
            return result_error;
        }
    }
    else
    {
        linklist_warn_log_args("List is Empty. Adding new node.");
        *head = createNode();
        (*head)->data = info;
        (*head)->next = NULL;
    }
}

e_retResult print_list(Node* node)
{
    if(node == NULL)
    {
        linklist_error_log_args("List is empty");
        return result_error;
    }
    
    linklist_info_log_args("Printing list:");
    while(node != NULL)
    {
        linklist_info_log_args("\t[%d|%p]", node->data, node->next);
        node = node->next;
    }
    return result_success;
}

/**********************************************************************/
/**********************************************************************/
                        /** Algorithms */
/**********************************************************************/
/**********************************************************************/
Node* reverse_list(Node* node)
{
    if(node == NULL)
    {
        linklist_error_log_args("Linklist Null. Nothing to reverse");
        return NULL;
    }

    Node* head;
    
    if(node->next != NULL)
    {
        head = reverse_list(node->next);
        node->next->next = node;
    }
    else
    {        
        return node;
    }
    node->next = NULL;
    
    return head;
}

// Find merge point where two linklist are merged.
Node* find_merge_node(Node* list1, Node* list2)
{
    int listLen1 = getLength(list1);
    int listLen2 = getLength(list2);
    if(listLen1 == 0 || listLen2 == 0)
    {
        linklist_error_log_args("One linklist is empty");
        return NULL;
    }

    linklist_info_log_args("len1 : %d", listLen1);
    linklist_info_log_args("len2 : %d", listLen2);
    
    int diffLen = listLen1 - listLen2;
    if(diffLen > 0)
    {
        while(list1->next != NULL && diffLen != 0)
        {
            diffLen--;
            list1 = list1->next;
        }
    }
    else if(diffLen < 0)
    {
        while(list2->next != NULL && diffLen != 0)
        {
            diffLen++;
            list2 = list2->next;
        }
    }
    else if (diffLen == 0)
    {
        linklist_info_log_args("Equal size");
    }

    while((list1->next != NULL && list2->next != NULL) && list1->next != list2->next)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    
    if(list1->next == NULL || list2->next == NULL)
    {
        linklist_error_log_args("Both are separate list");
        return NULL;
    }
    return list1->next;
}



