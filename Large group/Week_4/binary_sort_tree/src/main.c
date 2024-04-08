#define _CRT_SECURE_NO_WARNINGS 1

#include "binary_sort_tree.h" // ȷ������֮ǰ�����ͷ�ļ���ʵ��
#include <stdio.h>
#include <stdlib.h>

int main() {
    BinarySortTree BST;
    int choice, value;
    Status status;

    // ��ʼ��BST
    BST_init(&BST);

    while (1) {
        printf("\n��������������:\n");
        printf("1. ����Ԫ��\n");
        printf("2. ɾ��Ԫ��\n");
        printf("3. ����Ԫ��\n");
        printf("4. ǰ�����\n");
        printf("5. �������\n");
        printf("6. �������\n");
        printf("7. �������\n");
        printf("8. ������������,��-1����\n");
        printf("9. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("��������Ԫ��ֵ��");
            scanf("%d", &value);
            status = BST_insert(&BST, value);
            if (status) {
                printf("Ԫ�� %d ����ɹ���\n", value);
            }
            else {
                printf("Ԫ�� %d ����ʧ�ܡ�\n", value);
            }
            break;
        case 2:
            printf("����Ҫɾ����Ԫ��ֵ��");
            scanf("%d", &value);
            status = BST_delete(&BST, value);
            if (status) {
                printf("Ԫ�� %d ɾ���ɹ���\n", value);
            }
            else {
                printf("Ԫ�� %d ɾ��ʧ�ܡ�\n", value);
            }
            break;
        case 3:
            printf("����Ҫ���ҵ�Ԫ��ֵ��");
            scanf("%d", &value);
            status = BST_search(&BST, value);
            if (status) {
                printf("Ԫ�� %d ���������С�\n", value);
            }
            else {
                printf("Ԫ�� %d �����������С�\n", value);
            }
            break;
        case 4:
            printf("ǰ��������ݹ飩�����");
            BST_preorderR(&BST, visit);
            printf("\n");
            break;
        case 5:
            printf("����������ݹ飩�����");
            BST_inorderR(&BST, visit);
            printf("\n");
            break;
        case 6:
            printf("����������ݹ飩�����");
            BST_postorderR(&BST, visit);
            printf("\n");
            break;
        case 7:
            printf("������������");
            BST_levelOrder(&BST, visit);
            printf("\n");
            break;
        case 8:
            printf("����������ֵ����-1������\n");
            while (1) {
                scanf("%d", &value);
                if (value == -1) break;
                BST_insert(&BST, value);
            }
            printf("����������ɡ�\n");
            break;
        case 9:
            printf("�˳�����\n");
            return 0;
        default:
            printf("��Чѡ��\n");
        }
        system("pause");
        system("cls");
    }

    return 0;
}
