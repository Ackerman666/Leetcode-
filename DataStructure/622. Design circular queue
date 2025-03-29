


typedef struct {

    int *buffer;
    int buffer_size;
    int head, tail;
   

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *ring_buffer = malloc(sizeof(MyCircularQueue));
    ring_buffer->buffer_size = k;
    ring_buffer->buffer = malloc(sizeof(int) * k);
    ring_buffer->head  = ring_buffer->tail = -1;
    
    return ring_buffer;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(obj->tail == -1){
        obj->tail = obj->head = 0;
        obj->buffer[obj->tail] = value;
        return true;
    }

    if((obj->tail + 1) % obj->buffer_size != obj->head){
        obj->tail = ++obj->tail % obj->buffer_size;
        obj->buffer[obj->tail] = value;
        return true;
    }
    return false;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->head > -1){
        if(obj->head == obj->tail)
            obj->head = obj->tail = -1;
        else
            obj->head = ++obj->head % obj->buffer_size;
        return true;
    }
    return false;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->tail == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % obj->buffer_size == obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj) {

    free(obj->buffer);
    free(obj);
}

int myCircularQueueFront(MyCircularQueue* obj) {

    return (myCircularQueueIsEmpty(obj)) ? -1 : obj->buffer[obj->head];
    
}

int myCircularQueueRear(MyCircularQueue* obj) {
    
     return (myCircularQueueIsEmpty(obj)) ? -1 : obj->buffer[obj->tail];

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
