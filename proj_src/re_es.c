#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define ESC 0x1b
// getch함수 대체용 getkey함수
#include <termios.h>

int getkey(int is_echo) 
{
    int ch;
    struct termios old;
    struct termios current;

    /* 현재 설정된 terminal i/o 값을 backup함 */
    tcgetattr(0, &old);
    
    /* 현재의 설정된 terminal i/o에 일부 속성만 변경하기 위해 복사함 */
    current = old; 

    /* buffer i/o를 중단함 */
    current.c_lflag &= ~ICANON; 
    
    if (is_echo) {  // 입력값을 화면에 표시할 경우
        current.c_lflag |= ECHO; 
    } else {        // 입력값을 화면에 표시하지 않을 경우
        current.c_lflag &= ~ECHO;
    }
    
    /* 변경된 설정값으로 설정합니다.*/
    tcsetattr(0, TCSANOW, &current);
    ch = getchar();
    tcsetattr(0, TCSANOW, &old);

    return ch;
}
// 여기서부터 시작
typedef struct node{
    char address[20];
    char apt_name[20];
    float space;
    long int price;
    struct node *next;
}Node;

void main()
{
    FILE *fp = NULL;
    Node *new_node;
    Node *tmp_node;
    Node *list_head=NULL;
    char address[20];
    char apt_name[20];
    float space;
    long int price;
    char input ='0';

    // 파일 열기
    fp=fopen("202211_apt_list.dat","r+");
    if(fp==NULL){
        printf("Cannot open file\n");
        return;
    }
    // 학생정보읽기
    while(!feof(fp)){
        new_node=(Node*)malloc(sizeof(Node)); //동적 메모리 할당
        fscanf(fp,"%s %s %f %ld\n",&new_node->address,&new_node->apt_name,&new_node->space,&new_node->price);
        printf("노드 추가: %s %s %f %ld\n",&new_node->address,&new_node->apt_name,&new_node->space,&new_node->price);
        // 노드추가
        new_node->next=list_head;
        list_head=new_node;
    }
        // 포트폴리오 내역 조회
        while(input!=ESC){
            printf("------------------------------\n");
            printf("부동산 정보 조회(시군구_단지명):");
            scanf("%s %s",&address,&apt_name);
            tmp_node=search_node(address,apt_name,list_head);
            if(tmp_node)
            printf("%s %s %f %ld\n",tmp_node->address,tmp_node->apt_name,tmp_node->space,tmp_node->price);
            

        }
}

// void print_list(Node* list_head)
// {
//     // 리스트의 내용을 모두 출력
//     while(list_head !=NULL)
//     {
//         printf("%d=>",list_head->asset);
//         list_head=list_head->next;
//     }
//     printf("\n");
// }
// void main()
// {
//     int count=0;
//     int tmp_asset=0;
//     Node *new_node; //새로운 노드 위치 저장할 포인터
//     Node *list_head=NULL; //리스트의 시작노드

//     while(count<MAX_COUNT){
//         //사용자로부터 입력
//         printf("score %d: ",count);
//         scanf("%d",&tmp_asset);

//         if (tmp_asset==-1)
//             break;
//         else
//         {
//         // 1.노드 생성 with 동적 메모리 할당
//         new_node=(Node*)malloc(sizeof(Node));
//         new_node->asset=tmp_asset;
//         // 2.노드 연결
//         new_node->next=list_head; //뉴 노드의 다음 노드를 리스트 헤드로 저장.
//         list_head=new_node;
//         print_list(list_head);
//         }
//     }
// }
// 내림차순 정렬


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


 

