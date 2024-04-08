#define _CRT_SECURE_NO_WARNINGS 1

#include "binary_sort_tree.h" // 确保包含之前定义的头文件和实现
#include <stdio.h>
#include <stdlib.h>

int main() {
    BinarySortTree BST;
    int choice, value;
    Status status;

    // 初始化BST
    BST_init(&BST);

    while (1) {
        printf("\n二叉排序树操作:\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 查找元素\n");
        printf("4. 前序遍历\n");
        printf("5. 中序遍历\n");
        printf("6. 后序遍历\n");
        printf("7. 层序遍历\n");
        printf("8. 批量插入数据,以-1结束\n");
        printf("9. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("输入插入的元素值：");
            scanf("%d", &value);
            status = BST_insert(&BST, value);
            if (status) {
                printf("元素 %d 插入成功。\n", value);
            }
            else {
                printf("元素 %d 插入失败。\n", value);
            }
            break;
        case 2:
            printf("输入要删除的元素值：");
            scanf("%d", &value);
            status = BST_delete(&BST, value);
            if (status) {
                printf("元素 %d 删除成功。\n", value);
            }
            else {
                printf("元素 %d 删除失败。\n", value);
            }
            break;
        case 3:
            printf("输入要查找的元素值：");
            scanf("%d", &value);
            status = BST_search(&BST, value);
            if (status) {
                printf("元素 %d 存在于树中。\n", value);
            }
            else {
                printf("元素 %d 不存在于树中。\n", value);
            }
            break;
        case 4:
            printf("前序遍历（递归）结果：");
            BST_preorderR(&BST, visit);
            printf("\n");
            break;
        case 5:
            printf("中序遍历（递归）结果：");
            BST_inorderR(&BST, visit);
            printf("\n");
            break;
        case 6:
            printf("后序遍历（递归）结果：");
            BST_postorderR(&BST, visit);
            printf("\n");
            break;
        case 7:
            printf("层序遍历结果：");
            BST_levelOrder(&BST, visit);
            printf("\n");
            break;
        case 8:
            printf("批量插入数值，以-1结束：\n");
            while (1) {
                scanf("%d", &value);
                if (value == -1) break;
                BST_insert(&BST, value);
            }
            printf("批量插入完成。\n");
            break;
        case 9:
            printf("退出程序。\n");
            return 0;
        default:
            printf("无效选择。\n");
        }
        system("pause");
        system("cls");
    }

    return 0;
}
