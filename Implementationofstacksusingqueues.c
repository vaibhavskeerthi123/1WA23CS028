#include <stdio.h>

#define MAX 100


int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

// Check if queue is empty
int isEmpty(int front) {
    return front == -1;
}


void enqueue(int queue[], int *front, int *rear, int value) {
    if (*rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (*front == -1)
        *front = 0;
    queue[++(*rear)] = value;
}


int dequeue(int queue[], int *front, int *rear) {
    if (isEmpty(*front)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = queue[*front];
    if (*front == *rear) {
        *front = *rear = -1;  // Queue becomes empty
    } else {
        (*front)++;
    }
    return value;
}

// Front of queue
int front(int queue[], int front) {
    if (isEmpty(front))
        return -1;
    return queue[front];
}

// Push operation for stack
void push(int x) {
    // Push x into q2
    enqueue(q2, &front2, &rear2, x);

    // Move all elements from q1 to q2
    while (!isEmpty(front1)) {
        enqueue(q2, &front2, &rear2, dequeue(q1, &front1, &rear1));
    }

    // Swap q1 and q2
    int temp[MAX];
    int tempFront = front1, tempRear = rear1;
    
    for (int i = 0; i < MAX; i++) {
        temp[i] = q1[i];
        q1[i] = q2[i];
        q2[i] = temp[i];
    }
    front1 = front2; rear1 = rear2;
    front2 = tempFront; rear2 = tempRear;
}


void pop() {
    if (isEmpty(front1)) {
        printf("Stack underflow\n");
        return;
    }
    dequeue(q1, &front1, &rear1);
}

// Top operation for stack
int top() {
    if (isEmpty(front1))
        return -1;
    return front(q1, front1);
}


int size() {
    return isEmpty(front1) ? 0 : rear1 - front1 + 1;
}

int main() {
    push(1);
    push(2);
    push(3);

    printf("Current size: %d\n", size());
    printf("Top element: %d\n", top());
    pop();
    printf("Top element after pop: %d\n", top());
    pop();
    printf("Top element after another pop: %d\n", top());

    printf("Current size: %d\n", size());

    return 0;
}
