#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COUNT 5
typedef struct node{
    int asset;//총알(1:장전, 0:없음)
    struct node *next;
}Node;
// typedef struct real_estate{
//     char address[20];
//     char apt_name[20];
//     int space;
//     int price;
// }Re_Es;
void print_list(Node* list_head)
{
    // 리스트의 내용을 모두 출력
    while(list_head !=NULL)
    {
        printf("%d=>",list_head->asset);
        list_head=list_head->next;
    }
    printf("\n");
}
void main()
{
    int count=0;
    int tmp_asset=0;
    Node *new_node; //새로운 노드 위치 저장할 포인터
    Node *list_head=NULL; //리스트의 시작노드

    while(count<MAX_COUNT){
        //사용자로부터 입력
        printf("score %d: ",count);
        scanf("%d",&tmp_asset);

        if (tmp_asset==-1)
            break;
        else
        {
        // 1.노드 생성
        new_node=(Node*)malloc(sizeof(Node));
        new_node->asset=tmp_asset;
        // 2.노드 연결
        new_node->next=list_head;
        list_head=new_node;
        print_list(list_head);
        }
    }
}
// int main()
// {
//     Re_Es A;
//     int a[8]={1,2,3,4,5,6,7,8};
//     QuickSort(a,0,7);
//     return 0;
// }

// void QuickSort(int a[], int left, int right) //Quick Sorting 내림차순 알고리즘 for 가격
// {
//     int i = left;
//     int j = right;
//     int temp = a[i];

//     if( left < right)
//     {
//         while(i < j)
//         {
//             while(a[j] <= temp && i < j)
//             {
//                 j--;
//                 }
//             a[i] = a[j];

//             while(a[i] >= temp && i < j)
//             {
//                 i++;
//             }
//             a[j] = a[i];
//         }
//         a[i] = temp;

//         QuickSort(a, left, i - 1);
//         QuickSort(a, j + 1, right);
//     }
// }
// void MakeNode(Node **head, int bullet)
// {
//     Node *now = (Node *)malloc(sizeof(Node));
//     now->bullet = bullet;
//     if ((*head) == NULL)//빈 상태
//     {
//     (*head) = now;//맨앞이 now
//         now->next = now;//현재 now 하나여서 now->next도 now
//     }
//     else //비어있지 않음
//     {
//         //(*head)와 (*head) 다음 노드 사이에 now를 연결
//         now->next = (*head)->next;
//         (*head)->next = now;
//     }
// }


 

