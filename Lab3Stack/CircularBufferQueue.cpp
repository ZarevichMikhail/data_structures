#include "CircularBufferQueue.h"


//CircularBufferQueue::CircularBufferQueue() {
//
//    CircularBuffer queue = CircularBuffer(initial_capacity_);
//}
//
//
//CircularBufferQueue::CircularBufferQueue(int capacity) {
//
//    queue = CircularBuffer(capacity);
//}

CircularBufferQueue::CircularBufferQueue() : queue(initial_capacity_) {
}

CircularBufferQueue::CircularBufferQueue(int capacity) : queue(capacity) {
}

void CircularBufferQueue::Enqueue(int value) {
    queue.AddElement(value);
}


int CircularBufferQueue::Dequeue() {
    return queue.GetElement();
}


bool CircularBufferQueue::IsEmpty(){
    return queue.GetOccupiedSpace() == 0;
}


void CircularBufferQueue::PrintQueue() const {
    queue.PrintBuffer();
}


void CircularBufferQueue::ResizeQueue(int new_capacity) {
    
    queue.ResizeCircularBuffer(new_capacity);
}


void CircularBufferQueue::DeleteQueue() {

    queue.DeleteCircularBuffer();
}