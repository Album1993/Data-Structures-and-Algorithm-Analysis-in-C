//
// Created by 张一鸣 on 2017/1/10.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_QUEUE_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_QUEUE_H

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty_queue( Queue Q );
int IsFull_queue( Queue Q );
Queue CreateQueue_queue( int MaxElements );
void DisposeQueue_queue( Queue Q );
void MakeEmpty_queue( Queue Q );
void Enqueue_queue( ElementType X, Queue Q );
ElementType Front_queue( Queue Q );
void Dequeue_queue( Queue Q );
ElementType FrontAndDequeue_queue( Queue Q );

#endif //DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_C_QUEUE_H
