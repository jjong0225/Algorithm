#include"20170300.h"

int main()
{
    Node *head = NULL;
    const void *mem_ptr = (void *)calloc(BUF_SIZE, 1);
    size_t mem_len = 0;
    while(1)
    {
        int func_cmd = 0;
        printf("Do you want to allocate data (1) or deallocate data (2) ?\n");
        scanf("%d", &func_cmd);
        if(func_cmd == 1)
            mem_len += my_alloc(mem_ptr, mem_len, &head);
        else
            mem_len -= my_dealloc(mem_ptr, mem_len, &head);
        printf("Here is the mem dump!\n");
        dump_mem(mem_ptr, BUF_SIZE);
        node_iteration(head);
    }
}