/** Linklist for Signly and Doubly both */

/** Includes */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************/
/**********************************************************************/
                        /** Defines and Externs */
/**********************************************************************/
/**********************************************************************/
#define SINGLY_LINKLIST
//#define DOUBLY_LINKLIST

#define linklist_info_log_args(msg, args...)    \
                                    printf("Info:: " msg"\n", ## args)
                                    
#define linklist_warn_log_args(msg, args...)    \
                                    printf("Warn:: " msg"\n", ## args)
#define linklist_error_log_args(msg, args...)   \
                                    printf("Error:: " msg"\n", ## args)
#define linklist_dbg_log_args(msg, args...)         \
                            if(debug_level == 1)    \
                            {                       \
                                printf("Debug:: " msg"\n", ## args);    \
                            }

extern void set_debug_level(int level);

/**********************************************************************/
/**********************************************************************/
            /** Global and Static declaration */
/**********************************************************************/
/**********************************************************************/

#ifdef SINGLY_LINKLIST

#define USER_DATA int

typedef struct Node
{
    USER_DATA data;
    struct Node* next;
} Node;
#endif

#ifdef DOUBLY_LINKLIST
typedef struct Node
{
    User_Data data;
    Node* next;
    struct Node* prev;
} Node;
#endif

typedef enum
{
    result_notSet = -1,
    result_success = 0,
    result_error = 1,
    result_noOperation = 2,
    result_max
}e_retResult;



