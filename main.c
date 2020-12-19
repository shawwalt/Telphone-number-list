#include "Llist.h"


int main() {
    char control_letter;
    Head *first;

    first = Init_List(first);

    for(;;)
    {
        printf("Please type your instruction:");
        if(scanf(" %c",&control_letter)==EOF)continue;
        switch (control_letter) {
            case 'q':break;
            case 'i':Insert_Person(first);break;
            case 'd':Delete_Person(first);break;
            case 'p':Print_List(first);break;
            case 's':Search_Person(first);break;
            default:printf("\aNo found such instruction!Please type again:\n");
        }
        if(control_letter=='q')break;
    }

    return 0;
}
