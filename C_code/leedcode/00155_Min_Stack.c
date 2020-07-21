#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

typedef struct {
    int *data;
    int *min;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s = malloc(sizeof(MinStack));
    s->data = NULL;
    s->min = NULL;
    s->size = 0;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    obj->data = realloc(obj->data, sizeof(int)*( obj->size + 1 ));
    obj->min = realloc(obj->min, sizeof(int)*( obj->size + 1 ));
    obj->data[obj->size] = x;
    if(obj->size == 0 || obj->min[obj->size - 1] > x)
    {
        obj->min[obj->size] = x;
    }
    else
    {
        obj->min[obj->size] = obj->min[obj->size - 1];
    }
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->size-1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->min);
    free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

void main()
{   
    
    return; 
}
