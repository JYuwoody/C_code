#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*208. Implement Trie (Prefix Tree)
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/


struct Node_
{
    bool isEnd;
    struct Node_* children['z'-'a'+1];
};

typedef struct Node_ Node;

typedef struct {
    Node* root;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie* trie = calloc(1, sizeof(Trie));
    trie->root = calloc(1,sizeof(Node));
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Node* curr = obj->root;
    int index, i;

    for (i = 0; word[i]!='\0'; i++)
    {
        index = word[i] - 'a';
        if(curr->children[index] == NULL)
        {
            curr->children[index] = calloc(1, sizeof(Node));
        }
        curr = curr->children[index];
    }
    curr->isEnd = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) { 
    Node* curr = obj->root;
    int index, i;

    for (i = 0; word[i]!='\0'; i++)
    {
        index = word[i] - 'a';
        if(curr->children[index] == NULL)
        {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEnd;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Node* curr = obj->root;
    int index, i;
    for (i = 0; prefix[i]!='\0'; i++)
    {
        index = prefix[i] - 'a';
        if(curr->children[index] == NULL)
        {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

void nodeFree(Node* root)
{
    int index;
    char c;
    if(root == NULL) return;
    for(c='a';c<='z';c++)
    {
        index = c - 'a';
        nodeFree(root->children[index]);
    }
    free(root);
}
void trieFree(Trie* obj) {
    nodeFree(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/


void main()
{
    printf("woody\n");

    return; 
}