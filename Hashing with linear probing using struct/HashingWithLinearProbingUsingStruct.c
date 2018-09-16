#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct Man{
    char name[20];
        int leg;
    double rating;
};

struct DataItem {
    int key;
    struct Man man;

};

struct DataItem* dataList[SIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key) {
    return key%SIZE;
}

struct DataItem *search(int key) {
    //get the hash
    int hashIndex = getHashCode(key);
    //move in array until an empty
    while(dataList[hashIndex]!=NULL) {
        if(dataList[hashIndex]->key==key)
            return dataList[hashIndex];
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void insert(int key,char nm[],int l, double r) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    strcpy(item->man.name,nm);
    item->man.leg=l;
    item->man.rating=r;
    item->key = key;

    //get the hash
    int hashIndex = getHashCode(key);

    //move in array until an empty or deleted cell
    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1) {
        //goto next call
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }
    dataList[hashIndex] = item;
}

struct DataItem* del(struct DataItem* item) {
    int key = item->key;

    //get the hash
    int hashIndex = getHashCode(key);

    //move in array until an empty
    while(dataList[hashIndex] != NULL) {
        if(dataList[hashIndex]->key ==key) {
            struct DataItem* temp = dataList[hashIndex];

            //assign a dummy item at deleted position
            dataList[hashIndex] = singleItem;
            return temp;
        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
};

void display() {
    int i=0;
    for(i=0;i<SIZE;++i) {
        if(dataList[i] != NULL)
            printf(" (key : %d,  data :%s,%d,%lf)",dataList[i]->key,dataList[i]->man.name,dataList[i]->man.leg,dataList[i]->man.rating);
        else printf("--");
    }
    printf("\n");
}

int main() {
    singleItem = (struct DataItem*) malloc(sizeof(struct DataItem*));

    singleItem->key = -1;

    insert(1,"anik",2,1.5);
    insert(24,"koushik",5,2.6);

    display();
    item = search(1);
    if(item!= NULL) {
        printf("Element found: key :%d data :%s,%d,%lf\n",item->key,item->man.name,item->man.leg,item->man.rating);
    } else {
        printf("Element not found\n");
    }

}
