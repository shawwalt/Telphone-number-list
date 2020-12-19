//
// Created by lenovo on 2020/12/18.
//

#ifndef DESKTOP_LLIST_H
#define DESKTOP_LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char* name;
    char* relation;
    char* tel;
    struct Person*next;
}Person;

typedef struct L_Head
{
    int length;
    Person *header;
}Head;


int Insert_Person(Head *first);

int Delete_Person(Head *first);

int Print_List(Head *first);

int Search_Person(Head *first);

Head* Init_List(Head *first);

struct Person* SetPerson(Person*to);

#endif //DESKTOP_LLIST_H
