/** Linklist for Signly and Doubly both */

/**********************************************************************/
/**********************************************************************/
                            /** Includes */
/**********************************************************************/
/**********************************************************************/
#include "linklist.h"
#include "singly_linklist.h"
#include <unistd.h>
#include <getopt.h>

/**********************************************************************/
/**********************************************************************/
                            /** Defines */
/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/**********************************************************************/
                /** Global and Static declaration */
/**********************************************************************/
/**********************************************************************/
static int debug_level = 0;
static const char shortopts[] = "hd:";

static const struct option longopts[] = {
    { "help", 0, NULL, 'h' },
    { "debug", 1, NULL, 'd' },
    { NULL, 0, NULL, 0 }
};

#ifdef SINGLY_LINKLIST
#endif

#ifdef DOUBLY_LINKLIST
#endif

e_retResult parseCommandLineArg(int argc, char* const* argv)
{
    e_retResult retValue = result_success;
    int optc = 0;
    if(argc == 1)
    {
        retValue = result_noOperation;
    }
    else
    {
        while ((optc = getopt_long (argc, argv, shortopts, longopts, NULL)) != -1)
        {
            switch (optc)
            {
                case 'd':
                    linklist_info_log_args("Argument : %s", optarg);
                    debug_level = optarg[0] - '0';
                    set_debug_level(debug_level);
                break;
                case 'h':
                    linklist_info_log_args("for Help: ./linklist -h");
                    linklist_info_log_args("for Debug ./linklist -d 1(1 - 5)");
                    retValue = result_error;
                break;
                default:
                    linklist_info_log_args("Wrong Argument");
                    linklist_info_log_args("for Debug ./linklist -d 1(1 - 5)");
                    retValue = result_error;
            }
        }
    }
    return retValue;
}

int main(int argc, char* argv[])
{
    if(parseCommandLineArg(argc, argv) == result_error)
    {
        return 0;
    }

#if 0 //Reverse Singly Linklist
    Node* head = createNode();
    head->data = 10;
    head->next = NULL;

    push(20, &head);
    push(30, &head);
    push(40, &head);
    push(50, &head);
    push(60, &head);
    push(70, &head);
    push(80, &head);

    print_list(head);
//    head = reverse_list(head);
    linklist_dbg_log_args("After reverse");
    print_list(head);
#endif

#if 1 // Find merge point of 2 linklist
    Node* list1 = NULL;
    push(10, &list1);
    push(20, &list1);
    push(30, &list1);
    push(40, &list1);
    push(50, &list1);
    push(60, &list1);
    push(70, &list1);
    push(80, &list1);
    print_list(list1);

    Node* list2 = NULL;
    push(11, &list2);
    push(22, &list2);
    push(33, &list2);
    push(44, &list2);
    push(55, &list2);
    push(66, &list2);
    print_list(list2);
    Node* tail = getTail(list2);
    tail->next = list1->next->next->next;
    
    linklist_info_log_args("After merge");
    print_list(list2);

    Node* mergedNode = find_merge_node(list1, list2);
    linklist_info_log_args("Merged Node : %p", mergedNode);
#endif

    return 0;
}



