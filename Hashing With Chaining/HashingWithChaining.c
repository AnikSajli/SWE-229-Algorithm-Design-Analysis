#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem* dataList[SIZE][SIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key) {
    return key%SIZE;
}

struct DataItem *search(int key) {
    //get the hash
    int hashIndex = getHashCode(key);
    int d = 0;
    //move in array until an empty
    while(dataList[hashIndex][d]!=NULL) {
        if(dataList[hashIndex][d]->key==key)
            return dataList[hashIndex][d];
        //go to next cell
        ++d;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void insert(int key,int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data=data;
    item->key = key;

    //get the hash
    int hashIndex = getHashCode(key);
    int d = 0;

    //move in array until an empty or deleted cell
    while(dataList[hashIndex][d] != NULL && dataList[hashIndex][d]->key != -1) {
        //goto next call
        ++d;

        //wrap around the table
        hashIndex %= SIZE;
    }
    dataList[hashIndex][d] = item;
}

struct DataItem* del(struct DataItem* item) {
    int key = item->key;

    //get the hash
    int hashIndex = getHashCode(key);
    int d = 0;
    //move in array until an empty
    while(dataList[hashIndex][d] != NULL) {
        if(dataList[hashIndex][d]->key ==key) {
            struct DataItem* temp = dataList[hashIndex][d];

            //assign a dummy item at deleted position
            dataList[hashIndex][d] = singleItem;
            return temp;
        }
        //go to next cell
        ++d;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void display() {
    int i=0;
    int j = 0;
    for(i=0;i<SIZE;++i) {
            for(j = 0; j<SIZE; j++){
        if(dataList[i][j] != NULL)
            printf(" (%d,%d)",dataList[i][j]->key,dataList[i][j]->data);
        else printf("--");
            }
            printf("\n");
    }

}

int main() {
    singleItem = (struct DataItem*) malloc(sizeof(struct DataItem*));
    singleItem->data = -1;
    singleItem->key = -1;

    insert(1,20);
    insert(2,70);
    insert(42,80);
    insert(4,25);
    insert(10,44);
    insert(14,32);
    insert(17,11);
    insert(20,78);
    insert(37,97);
    insert(37,53);

    display();
    item = search(20);
    if(item!= NULL) {
        printf("Element found: %d %d\n",item->key,item->data);
    } else {
        printf("Element not found\n");
    }

}
