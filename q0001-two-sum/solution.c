typedef struct Node {
  int val;
  int index;
  struct Node *next;
} Node;

typedef struct Bucket {
  Node *firstNode;
  int size;
} Bucket;

typedef struct HashTable {
  Bucket **buckets;
  int size;
} HashTable;

int getHash(int val, int tableSize){
  return (val % tableSize + tableSize) % tableSize;
}

Node* createNode(int val, int index){
  Node *node = malloc(sizeof(Node));
  node->val = val;
  node->index = index;
  node->next = NULL;
  return node;
}

void insertNode(Bucket *bucket, int val, int index){
  Node* newNode = createNode(val, index);
  Node *node = bucket->firstNode;

  if (node == NULL) {
    bucket->firstNode = newNode;
    bucket->size += 1;
    return;
  }

  while(node->next != NULL){
    node = node->next;
  }

  node->next = newNode;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  HashTable *table = malloc(sizeof(HashTable));
  table->buckets = calloc(numsSize, sizeof(Bucket*));
  table->size = numsSize;

  for(int i = 0; i < numsSize; i++){
    int complement = target - nums[i];
    int key = getHash(complement, numsSize);

    Bucket *bucket = table->buckets[key];
    if (bucket == NULL){
      table->buckets[key] = malloc(sizeof(Bucket));
      bucket = table->buckets[key];
      bucket->firstNode = NULL;
      bucket->size = 0;
    }

    Node* node = bucket->firstNode;
    while(node != NULL){
      if(node->val == complement){
        int *res = malloc(2*sizeof(int));
        res[0] = node->index;
        res[1] = i;
        *returnSize = 2;
        return res;
      }
      node = node->next;
    }

    int insertKey = getHash(nums[i], numsSize);
    if (table->buckets[insertKey] == NULL) {
      table->buckets[insertKey] = malloc(sizeof(Bucket));
      table->buckets[insertKey]->firstNode = NULL;
      table->buckets[insertKey]->size = 0;
    }
    insertNode(table->buckets[insertKey], nums[i], i);
  }

  *returnSize = 0;
  return NULL;
}
