/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-15 11:27:21
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 18:23:33
 * @Descricirrition: file conte
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include "tlsf.h"

// 1. 定义一块静态内存作为内存池（例如 128KB）
#define POOL_SIZE (128 * 1024)
static unsigned char my_memory_pool[POOL_SIZE];

/**
 * 申请100个随机大小的内存
 * 一秒一次
 * （1）申请一个随机大小的内存
 * （2）随机释放一个内存
 *
 */

int get_random_number(int min, int max)
{
    // 1. 设置随机数种子（通常以时间为种子，只需在程序开始时调用一次）
    // 2. 公式计算
    return rand() % (max - min + 1) + min;
}

typedef struct node {
    struct node* next;
    void* data;
}Node;

/**
 * @brief 申请100个随机大小的内存
 *
 * @param inst
 * @param numNode
 * @return Node*
 */
Node* init_list(tlsf_t inst, int numNode)
{
    Node *head = (Node *)tlsf_malloc(inst, sizeof(Node));
    head->next = NULL;
    int randSize = get_random_number(1, 1024);
    head->data = tlsf_malloc(inst, randSize);
    assert(NULL != head->data);

    printf("T --- memory p[%p] size[%d]\n", head->data, randSize);

    for (size_t i = 0; i < numNode; i++)
    {
        Node *node = (Node *)tlsf_malloc(inst, sizeof(Node));
        randSize = get_random_number(1, 1024);
        node->data = tlsf_malloc(inst, randSize);
        assert(NULL != node->data);

        printf("T --- memory p[%p] size[%d]\n", head->data, randSize);
        node->next = head;
        head = node;
    }

    return head;
}

Node *delete_and_add_node(tlsf_t inst, Node* head)
{
    // 添加一个node
    Node *node = (Node *)tlsf_malloc(inst, sizeof(Node));
    int randSize = get_random_number(1, 1024);
    node->data = tlsf_malloc(inst, randSize);
    assert(NULL != node->data);

    printf("T --- %s add p[%p] size[%d]\n", __FUNCTION__, head->data, randSize);
    node->next = head;
    head = node;

    // 随机删除一个
    randSize = get_random_number(0, 99);
    Node *tmp = head;
    Node *tmp1 = head->next;
    for (size_t i = 0; i < randSize; i++)
    {
        if (NULL != tmp->next)
        {
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }
    }

    if (tmp == head)
    {
        head = head->next;
        printf("T --- %s delete randSize[%d] p[%p]\n", __FUNCTION__, randSize, tmp->data);
        tlsf_free(inst, tmp->data);
        tlsf_free(inst, tmp);
    }
    else
    {
        tmp->next = tmp1->next;
        printf("T --- %s delete randSize[%d] p[%p]\n", __FUNCTION__, randSize, tmp1->data);
        tlsf_free(inst, tmp1->data);
        tlsf_free(inst, tmp1);
    }

    return head;
}


int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    // tlsf_t 其实是一个指向内存池起始地址的指针
    tlsf_t inst = tlsf_create_with_pool(my_memory_pool, POOL_SIZE);
    if (inst == NULL) {
        printf("TLSF 初始化失败！\n");
        assert(false);
        return -1;
    }

    Node* head = init_list(inst, 100);
    while (1)
    {
        head = delete_and_add_node(inst, head);
        sleep(1);
    }

    // 6. 销毁内存池（通常在嵌入式系统中，内存池是常驻的，较少调用）
    tlsf_destroy(inst);
    return 0;
}
