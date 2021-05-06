#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

#define STR_SIZE 100
#define BUF_SIZE 256

typedef struct node
{
    int node_size;
    char node_name[STR_SIZE];
    struct node *next;
} Node;

void dump_mem(const void *mem, size_t len) {
    const char *buffer = (const char *)mem;
    size_t i;
    for (i=0; i<len; i++){
        if (i>0 && i%16 == 0) {
            printf("\n");
        }
        printf("%02x ", buffer[i] & 0xff);
    }
    puts("");
}


void node_push_back (Node **head, int param_node_size, char param_node_name[STR_SIZE])
{
    if(*head == NULL)
    {
        *head = (Node *)calloc(sizeof(Node), 1);
        (*head)->node_size = param_node_size;
        memcpy((*head)->node_name, param_node_name, STR_SIZE);
        (*head)->next = NULL;
    }
    else
    {
        Node *now_ptr = *head;
        while(now_ptr->next != NULL)
            now_ptr = now_ptr -> next;
        now_ptr->next = (Node *)calloc(sizeof(Node), 1);
        now_ptr->next->node_size = param_node_size;
        memcpy(now_ptr->next->node_name, param_node_name, STR_SIZE);
        now_ptr->next->next = NULL;
    }
}


void node_iteration (Node *head)
{
    int i = 1;
    Node *now_ptr = head;
    while(now_ptr != NULL)
    {
        printf("%d : %s, %d\n", i++, now_ptr->node_name, now_ptr->node_size);
        now_ptr = now_ptr->next;
    }
}

void pop_node(Node **head, int node_idx, int *start_idx, int *node_size)
{
    int counter = 0;
    Node *tmp = NULL;
    if(node_idx == 0)
    {
        tmp = *head;
        *start_idx = 0;
        *node_size = (*head)->node_size;
        *head = (*head)->next;
    }
    else
    {
        Node *tmp_node = *head;
        for(int i=0; i<node_idx-1; i++)
        {
            counter += tmp_node->node_size;
            tmp_node = tmp_node->next;
        }
        tmp = tmp_node->next;
        *start_idx = counter + tmp_node -> node_size;
        *node_size = tmp_node->next->node_size;
        tmp_node->next = tmp_node->next->next;
    }
    free(tmp);
}


int is_exist(Node *head, char input_name[STR_SIZE])
{
    Node *now_ptr = head;
    int i = 0;
    while(now_ptr != NULL)
    {
        if(!strcmp(now_ptr->node_name, input_name))
            return i;
        i++;
        now_ptr = now_ptr -> next;
    }
    return -1;
}

int memory_checker(size_t len, int insert_len)
{
    if(len + insert_len > BUF_SIZE)
    {
        printf("There is not enough memory for the data, you can only use %d byte(s)\n", BUF_SIZE-len);
        return 0;
    }
    return 1;
}

int store_varialbe(char dtype_cmd[STR_SIZE], const void *mem, size_t len)
{
    char *buffer = (char *)mem;
    int return_val = 0;
    if(!strcmp(dtype_cmd, "char"))
    {
        char tmp_str[STR_SIZE];
        return_val = 1;
        if(!memory_checker(len, return_val)) return 0;
        scanf("%s", tmp_str);
        memcpy(buffer+len, tmp_str, 1);
    }
    else if(!strcmp(dtype_cmd, "int"))
    {
        int tmp_int;
        return_val = 4;
        if(!memory_checker(len, return_val)) return 0;
        scanf("%d", &tmp_int);
        memcpy(buffer+len, &tmp_int, 4);
    }
    else if(!strcmp(dtype_cmd, "double"))
    {
        double tmp_double;
        return_val = 8;
        if(!memory_checker(len, return_val)) return 0;
        scanf("%lf", &tmp_double);
        memcpy(buffer+len, &tmp_double, 8);
    }
    else
        return_val = 0;
    return return_val;
}

int struct_store(const void *tmp_mem)
{
    int return_val = 0;
    int num_of_mem = 0;
    printf("How many data should be in the struct\n");
    scanf("%d", &num_of_mem);
    printf("Please specify each type and its value\n");

    for(int i=0; i<num_of_mem; i++)
    {
        char tmp_type[STR_SIZE] = {0};
        scanf("%s", tmp_type);
        int tmp_result = store_varialbe(tmp_type, tmp_mem, return_val);
        if(tmp_result == 0)
            return 0;
        else
            return_val += tmp_result;
    }
    return return_val;
}

int my_alloc(const void *mem, size_t len, Node **head)
{
    char dtype_cmd[STR_SIZE] = {0};
    char val_name[STR_SIZE] = {0};
    int inserted_len = 0;
    printf("What is the type of data you want to allocate and what will be the name of the data?\n");
    scanf("%s", dtype_cmd);
    scanf("%s", val_name);
    // 이름 중복 체크, test시에는 주석처리
    if(is_exist(*head, val_name) != -1) 
    {
         printf("name is already exist\n"); 
         return 0;
    }

    if(!strcmp(dtype_cmd, "struct"))
    {
        char *tmp_mem = (char *)calloc(BUF_SIZE, 1);
        char *tmp_buffer = (char *)mem;
        inserted_len = struct_store(tmp_mem);
        if(!memory_checker(len, inserted_len)) return 0;
        memcpy(tmp_buffer+len, tmp_mem, inserted_len);
        free(tmp_mem);
    }
    else
    {
        printf("Please specify a value for the data type\n");
        inserted_len += store_varialbe(dtype_cmd, mem, len);
        if(inserted_len == 0)
        {
            printf("wrong data type");
            return 0;
        }
    }
    node_push_back(head, inserted_len, val_name);
    printf("%s has been allocated successfully\n", val_name);
    return inserted_len;
}


int my_dealloc(const void *mem, size_t len, Node **head)
{
    char input_name[STR_SIZE] = {0};
    printf("What is the name of data you want to deallocate?\n");
    scanf("%s", input_name);
    int node_idx = is_exist(*head, input_name); 
    if(node_idx == -1)
    {
        printf("no such name");
        return 0;
    }
    else
    {
        char *buffer = (char *)mem;
        int start_idx = 0, node_size = 0;
        pop_node(head, node_idx, &start_idx, &node_size);
        printf("start_idx : %d / node_size : %d\n", start_idx, node_size);
        void *tmp_mem = (void *)calloc(BUF_SIZE, 1);
        memcpy(tmp_mem, buffer + start_idx + node_size, BUF_SIZE - (start_idx + node_size));
        memcpy(buffer + start_idx, tmp_mem, BUF_SIZE - (start_idx + node_size));
        memcpy(buffer + BUF_SIZE - node_size, tmp_mem + BUF_SIZE - start_idx, node_size);
        free(tmp_mem);
        return node_size;
    }
    printf("%s has been deallocated successfully\n", input_name);
}

