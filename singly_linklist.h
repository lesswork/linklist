
/**********************************************************************/
/**********************************************************************/
                    /** Declarations */
/**********************************************************************/
/**********************************************************************/
Node* createNode(void);
e_retResult deleteNode(Node* node);
Node* getTail(Node* node);
int getLength(Node* node);
e_retResult push(USER_DATA info, Node** head);
e_retResult print_list(Node* node);
Node* reverse_list(Node* node);
Node* find_merge_node(Node* list1, Node* list2);
