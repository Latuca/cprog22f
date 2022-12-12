#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define ESC 0x1b
//키보드 입력 감지 getch함수 구현
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
    char apt_name[30];
    int space;
    long int price;
    struct node *next;
}Node;
//1. 검색기능 구현
Node *search_node(char *apt_name, Node* list_head)
{
    Node *tmp=list_head;
    while(tmp){
        if(!strcmp(tmp->apt_name,apt_name)){ //검색할 단지명 찾음.
            return tmp; //해당 단지 정보 리턴
        }
        tmp=tmp->next;  //다음 노드로 이동하여 검색진행
    }
    return tmp;
}

void menu(void);//1.메뉴기능
void search();
void sort();
void add();
void remove();
void menu(void)
{
    printf("================");
    printf("0.검색");
    printf("1.정렬");
    printf("2.정보 추가");
    printf("3.삭제");
    printf("4.프로그램 종료");
    printf("================");
    
}
void main()
{
    FILE *fp = NULL;
    Node *new_node;
    Node *tmp_node;
    Node *list_head=NULL;
    char address[20];
    char apt_name[30];
    int space;
    long int price;
    // 함수포인터 배열 선언
    void (*pf[4])()={search,sort,add,remove};
    //메뉴 과련 변수 선언
    int choice;
    // 파일 열기
    fp=fopen("202211_apt_list.txt","r");
    if(fp==NULL){
        printf("Cannot open file\n");
        return;
    }
    // 부동산정보읽기
    while(!feof(fp)){
        new_node=(Node*)malloc(sizeof(Node)); //동적 메모리 할당
        fscanf(fp,"%s %s %d %ld ",new_node->address,new_node->apt_name,&new_node->space,&new_node->price);
        printf("\n[노드 추가]:\n %s %s %d %ld",new_node->address,new_node->apt_name,new_node->space,new_node->price);
        // 노드추가
        new_node->next=list_head;
        list_head=new_node;
    }
    while(1)
    {
        menu();
        printf("메뉴를 선택하시오:");
        scanf("%d",&choice);

        if(choice <0 || choice )
            break;
        switch(choice){
            case 0:
                search();
                break;
            case 1:
                sort();
                break;
            case 2:
                add();
                break;
            case 3:
                remove();
                break;
            default:
                break;
        }
    }

        // 메모리 해제 및 파일 닫기
        while(list_head){
            tmp_node=list_head;
            list_head=list_head->next;
            free(tmp_node);
        }
        fclose(fp);
}

void search(){
    Node *tmp_node;
    Node *list_head;
    char apt_name[30];
    char input ='0';
    while(input!=ESC){
        printf("\n------------------------------\n");
        printf("부동산 정보 검색(단지명):");
        scanf("%s",apt_name);
        tmp_node=search_node(apt_name,list_head);
        if(tmp_node)
            printf("%s %s %d %ld\n",tmp_node->address,tmp_node->apt_name,tmp_node->space,tmp_node->price);
        else
            printf("찾으시는 매물이 없습니다.\n");
        printf("종료는 ESC, 계속은 Enter 키를 누르세요\n");
        input=getch();
    }
}
//2.정렬 기능 구현
void insertNodeSort(){
    Node * list_head=NULL;
    Node *new_node=(Node *)malloc(sizeof(Node));
    scanf("%d",new_node->price);
    new_node->next=NULL;
    if(list_head==NULL)
    {
        list_head=new_node;
        return ;
    }
    if(list_head->price>new_node->price)
    {
        new_node->next=list_head;
        list_head=new_node;
        return ;
    }
}



 

