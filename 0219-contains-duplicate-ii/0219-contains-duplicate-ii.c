#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    long long *table;
    int capacity;
    int size;
} HashSet;

HashSet* createSet(int capacity) {
    HashSet *set = (HashSet*)malloc(sizeof(HashSet));
    set->capacity = capacity;
    set->size = 0;
    set->table = (long long*)malloc(sizeof(long long) * capacity);
    for (int i = 0; i < capacity; i++) set->table[i] = LLONG_MIN; 
    return set;
}

int hashFunc(HashSet *set, long long key) {
    long long h = key % set->capacity;
    if (h < 0) h += set->capacity;
    return (int)h;
}

bool contains(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        if (set->table[idx] == key) return true;
        idx = (idx + 1) % set->capacity;
    }
    return false;
}

void insert(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        idx = (idx + 1) % set->capacity;
    }
    set->table[idx] = key;
    set->size++;
}

void removeKey(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        if (set->table[idx] == key) {
            set->table[idx] = LLONG_MIN;
            return;
        }
        idx = (idx + 1) % set->capacity;
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k == 0) return false;

    int capacity = numsSize * 2 + 1;
    HashSet *set = createSet(capacity);

    for (int i = 0; i < numsSize; i++) {
        if (contains(set, nums[i])) {
            free(set->table);
            free(set);
            return true;
        }
        insert(set, nums[i]);

        
        if (set->size > k) {
            removeKey(set, nums[i - k]);
        }
    }

    free(set->table);
    free(set);
    return false;
}