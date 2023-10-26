#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** history;
    int size;
    int capacity;
    int current_position;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory* browserHistory = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    browserHistory->capacity = 100;
    browserHistory->history = (char**)malloc(browserHistory->capacity * sizeof(char*));
    browserHistory->size = 1;
    browserHistory->current_position = 0;
    browserHistory->history[0] = strdup(homepage);
    return browserHistory;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
    obj->current_position++;
    if(obj->current_position == obj->capacity) {
        obj->capacity *= 2;
        obj->history = realloc(obj->history, obj->capacity * sizeof(char*));
    }
    obj->history[obj->current_position] = strdup(url);
    obj->size = obj->current_position + 1;
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
  obj->current_position = obj->current_position - steps >= 0 ? obj->current_position - steps : 0;
    return obj->history[obj->current_position];
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
  obj->current_position = obj->current_position + steps < obj->size ? obj->current_position + steps : obj->size - 1;
    return obj->history[obj->current_position];
}

void browserHistoryFree(BrowserHistory* obj) {
   for(int i = 0; i < obj->size; i++) {
        free(obj->history[i]);
    }
    free(obj->history);
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char * param_2 = browserHistoryBack(obj, steps);
 
 * char * param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/
