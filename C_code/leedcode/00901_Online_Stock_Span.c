#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*901. Online Stock Span
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.
*/
/*
Runtime: 267 ms, faster than 81.82% of C online submissions for Online Stock Span.
Memory Usage: 64 MB, less than 18.18% of C online submissions for Online Stock Span.
*/
typedef struct {
    int lastMax[10001];
    int index[10001];
    int lastMaxSize;
    int end;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    return calloc(1, sizeof(StockSpanner));
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int result = 0;

    while(obj->lastMaxSize > 0 && obj->lastMax[obj->lastMaxSize-1] <= price)
    {
        obj->lastMaxSize--;
    }
    obj->lastMax[obj->lastMaxSize] = price;
    obj->index[obj->lastMaxSize] = obj->end;

    if(obj->lastMaxSize == 0)
        result = obj->end + 1;
    else
        result = obj->end - obj->index[obj->lastMaxSize-1];

    obj->lastMaxSize++;
    obj->end++;
    return result;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/

/*
Runtime: 288 ms, faster than 81.82% of C online submissions for Online Stock Span.
Memory Usage: 58.5 MB, less than 81.82% of C online submissions for Online Stock Span.
*/


typedef struct {
    unsigned data[10001];
    unsigned d[10001];
    int index;
} StockSpanner2;


StockSpanner2* stockSpannerCreate2() {
    StockSpanner2 *r = malloc(sizeof(StockSpanner2));
    r->index = 0;
    return r;
}

int stockSpannerNext2(StockSpanner2* r, int p) {
    int j = r->index;
    int s = 1;
    for (int i = j - 1; i >= 0 && r->data[i] <= p; i -= r->d[i])
        s += r->d[i];
    r->d[j] = s;
    r->data[j] = p;
    ++r->index;
    return s;
}

void stockSpannerFree2(StockSpanner2* r) {
    free(random);
}

/*
Runtime: 828 ms, faster than 54.55% of C online submissions for Online Stock Span.
Memory Usage: 59.3 MB, less than 81.82% of C online submissions for Online Stock Span.
*/
typedef struct {
    int price[10001];
    int end;
} StockSpanner1;


StockSpanner1* stockSpannerCreate1() {
    return calloc(1, sizeof(StockSpanner1));
}

int stockSpannerNext1(StockSpanner1* obj, int price) {
    int curr = 0;

    obj->price[obj->end] = price;
    obj->end++;

    curr = obj->end-1;
    while(curr >= 0 && obj->price[curr] <= price)
    {
        curr--;
    }
    if(curr < 0)
    {
        return obj->end;
    }

    return obj->end-1-curr;
}

void stockSpannerFree1(StockSpanner1* obj) {
    free(obj);
}


