#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define ESC 0x1b
//1.키보드 입력 감지 getch함수 구현
#include <termio.h>

int getch(void)
{
    int ch;

    struct termios old;
    struct termios new;

    tcgetattr(0, &old);

    new = old;
    new.c_lflag &= ~(ICANON|ECHO);
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);

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
//2. 검색기능 구현
Node *search_node(char *apt_name, Node* list_head)
{
    Node *tmp=list_head;
    while(tmp){
        if(!strcmp(tmp->apt_name,apt_name)){ //검색할 단지명 찾음.
            return tmp;
        }
        tmp=tmp->next;  //다음 노드로 이동하여 검색진행
    }
    return tmp;
}

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
            scanf("%s",&apt_name);
            tmp_node=search_node(apt_name,list_head);
            if(tmp_node)
                printf("%s %s %f %ld\n",tmp_node->address,tmp_node->apt_name,tmp_node->space,tmp_node->price);
            else
                printf("찾으시는 매물이 없습니다.\n");
            printf("종료는 ESC, 계속은 Enter 키를 누르세요\n");
            input=getch();
        }
        // 메모리 해제 및 파일 닫기
        while(list_head){
            tmp_node=list_head;
            list_head=list_head->next;
            free(tmp_node);
        }
        fclose(fp);
}




 

