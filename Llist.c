//
// Created by lenovo on 2020/12/18.
//

#include "Llist.h"

Head* Init_List(Head *first)
{
    first=(Head*)malloc(sizeof(Head));
    first->length=0;
    first->header=NULL;
    return first;
}
int Insert_Person(Head *first)
{
    Person *p=first->header,*q,*s=(Person*)malloc(sizeof(Person));

    if(!s) return 1;

    s=SetPerson(s);
    if (first->length==0)
    {
        first->header=s;
        s->next=NULL;
    }
    else
    {
        for (;p!=NULL&&strcmp(s->name,p->name)>0;q=p,p=p->next);
        if(first->header==p){
            first->header=s;
            s->next=p;
        } else{
            q->next=s;
            s->next=p;
        }

    }
    first->length++;
    printf("Success!\n");
    return 0;

}
int Delete_Person(Head *first)
{
    Person *p=first->header,*q;
    if(!p){
        printf("The list is null.\n");
        return 1;
    }
    char name[30];
    int flag=1;

    printf("Type the name of the Person you want to delete:");
    scanf(" %s",name);

    for(;p!=NULL;q=p,p=p->next)
    {
        if(!strcmp(p->name,name))
        {
            flag=0;
            break;
        }
    }

    if(!flag)
    {
        if(p==first->header){
            first->header=p->next;
            free(p);
            first->length--;
        } else{
            q->next=p->next;
            free(p);
            first->length--;
        }

    } else
        printf("Sorry,the man you hate seems to have been deleted.");
    printf("Finish.\n");
    return 0;
}
int Print_List(Head *first)
{
    Person *p=first->header;
    if(!p)
    {
        printf("The list is null.\n");
        return 1;
    }
    printf("========================\n");
    for(;p!=NULL;p=p->next)
        printf("%s %s %s\n",p->name,p->relation,p->tel);
    printf("========================\n");
    return 0;
}
int Search_Person(Head *first)
{
    Person *p=first->header;
    if(!p){
        printf("The list is null.\n");
        return 1;
    }
    int flag=1;
    char name[30];

    printf("Type the name of the Person you want to search:");
    scanf(" %s",name);
    for(;p!=NULL;p=p->next)
    {
        if(!strcmp(p->name,name))
        {
            flag=0;
            break;
        }
    }

    if(!flag)
        printf("%s %s %s\n",p->name,p->relation,p->tel);
    else printf("NO SUCH PERSON!\n");
    return 0;
}
struct Person* SetPerson(Person*to)
{
    char name[30],relation[30],tel[30];

    printf("Please type the name,relation,and the tel number of the person you want to insert:");
    scanf("%s%s%s",name,relation,tel);
    to->name=(char*)malloc((strlen(name)+1)* sizeof(char ));
    to->relation=(char*)malloc((strlen(relation)+1)* sizeof(char ));
    to->tel=(char*)malloc((strlen(tel)+1)* sizeof(char ));

    strcpy(to->name,name);
    strcpy(to->relation,relation);
    strcpy(to->tel,tel);

    return to;
}