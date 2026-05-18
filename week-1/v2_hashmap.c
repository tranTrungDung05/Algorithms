/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
typedef struct Node{
    int key;
    int value;
    struct Node *next;
}Node;

typedef struct hashMap{
    Node **bucket;
    int size;
}hashMap;

hashMap* create_hashMap(int size){
    hashMap *map = malloc(sizeof(hashMap));
    map->bucket = (Node**)malloc(size * sizeof(Node*));
    map->size = size; //quên gán
    for(int i = 0; i < size; i++){
        map->bucket[i] = NULL;
    }
    return map;
}
int hash(int key, int size){
    int bucket = key % size;
    if(bucket < 0) bucket += size;
    return bucket;
}

Node* insert_Node(hashMap *map, int key, int value){
    int idx = hash(key, map->size);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->bucket[idx];
    map->bucket[idx] = newNode; 
    return newNode;
}
Node* search_Node(hashMap *map, int key){  //quên khai báo lại void thành int
    int bucket = hash(key, map->size);
    for(Node *i = map->bucket[bucket]; i != NULL; i = i->next){ //quên gán map->bucket[idx] vào Node *i
        if(key == i->key){ //gõ thiếu phép == thành dấu =
            return i; //trả lại địa chỉ Node của key đó
        }
    }
    return NULL; //dùng NULL thay -1
}

void free_hashMap(hashMap *map){
    free(map);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashMap *map = create_hashMap(numsSize);
    int *return_arr = malloc(2 * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        int need = target - nums[i];
        Node *newNode = search_Node(map, need);

        if(newNode != NULL){
            if(need == newNode->key){
                return_arr[0] = i;
                return_arr[1] = newNode->value;
                *returnSize = 2;
                free_hashMap(map);
                return return_arr;
            }
        }else{
            insert_Node(map, nums[i], i);
        }
    }
    free_hashMap(map);
    *returnSize = 0;
    return NULL;
}
