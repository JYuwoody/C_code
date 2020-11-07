#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
At most 3 * 104 calls will be made to get and put.
*/

typedef struct 
{
    int key;
    int value;
    int priority;
}Entry;


typedef struct {   
    struct Entry* entries;
    int capacity;
    int currentPriority; // If the value bigger, the priority is higher.
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    int i;
    LRUCache* obj = malloc(sizeof(LRUCache));
    obj->entries = calloc(capacity, sizeof(struct Entry));
    obj->capacity = capacity;
    obj->currentPriority = 0;
    
    for(i=0;i<capacity;i++)
    {
        obj->entries[i].key = -1;
    }

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int i;
    //have value
    for(i=0;i<obj->capacity;i++)
    {
        if(obj->entries[i].key == key)
        {
            obj->currentPriority++;
            obj->entries[i].priority = obj->currentPriority;
            return obj->entries[i].value;
        }
    }

    // null
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int i;
    int minI = 0;
    //had: recover
    for(i=0;i<obj->capacity;i++)
    {
        if(obj->entries[i].key == key)
        {
            obj->entries[i].value = value;
            obj->currentPriority++;
            obj->entries[i].priority = obj->currentPriority;
            return;
        }
    }

    // null: add new 
    // not full: add at null space 
    for(i=0;i<obj->capacity;i++)
    {
        if(obj->entries[i].key == -1)
        {
            obj->entries[i].key = key;
            obj->entries[i].value = value;
            obj->currentPriority++;
            obj->entries[i].priority = obj->currentPriority;
            return;
        }
    }

    //full: replace the min priority space 
    for(i=0;i<obj->capacity;i++)
    {
        if(obj->entries[i].priority < obj->entries[minI].priority)
        {
            minI = i;
        }
    }

    obj->entries[minI].key = key;
    obj->entries[minI].value = value;
    obj->currentPriority++;
    obj->entries[minI].priority = obj->currentPriority;
    return;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->entries);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

void main()
{



    return; 
}














