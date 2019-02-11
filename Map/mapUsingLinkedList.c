/*****************************************************************
Name    :mapUsingLinkedList
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190211 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================*/
typedef struct mapItem
{
    char* key;
    int val;
    struct mapItem *next;
}mapItem;

typedef struct map
{
    mapItem *head;
    mapItem *end;
}map;

map* mapNew()
{
    map *newMap = malloc(sizeof(map));
    newMap->head = NULL;
    newMap->end = NULL;
    return newMap;
}

map* mapInsert(const char *key, int val, map* mapPtr)
{
    //copy the new key
    char *newkey = malloc(sizeof(key) + 1);
    strcpy(newkey, key);

    //new map item
    mapItem *newItem = malloc(sizeof(mapItem));
    newItem->key = newkey;
    newItem->val = val;
    newItem->next= NULL;

    //add into map
    if (mapPtr->head == NULL){
        mapPtr->head = newItem;
        mapPtr->end = newItem;
    }else{
        mapPtr->end->next = newItem;
        mapPtr->end = newItem;
    }

    return mapPtr;
}

mapItem* mapFind(char *key, map* mapPtr)
{
    mapItem *parsing = malloc(sizeof(mapItem));
    parsing = mapPtr->head;
    while(parsing != NULL){
        //printf("%s %d\n", parsing->key, parsing->val);
        if(strcmp(key, parsing->key) == 0){
            break;
        }
        parsing = parsing->next;
    }

    return parsing;
}

/*==============================================================*/

/*==============================================================*/
int main(){
    map *cMap = mapNew();

    mapInsert("word", 2, cMap);
    mapInsert("fork", 2, cMap);
    mapInsert("book", 5, cMap);

    mapItem *find = mapFind("fork", cMap);
    if(find != NULL)
        printf("%s %d\n", find->key, find->val);
    else
        printf("Not Found\n");

    return 0;
}
/*==============================================================*/