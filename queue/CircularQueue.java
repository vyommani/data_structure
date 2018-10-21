package com.ds.queue;

import java.util.NoSuchElementException;

/**
 * A circular queue, is a data structure that uses a single, fixed-size buffer
 * as if it were connected end-to-end.The useful property of a circular buffer
 * is that it does not need to have its elements shuffled around when one is consumed.
 * @param <Item>
 */
public class CircularQueue<Item> {
    private static final String NULL_ITEM = "Object is null,you can not add null to deque.";
    private static final String EMPTY_QUEUE = "Queue is empty,you can not remove any element.";
    private static final String REMOVE_NOT_ALLOWED = "Removing a item from iterator is not supported.";

    final int SIZE;
    Item items[];
    int front, rear, itemCount;

    public CircularQueue(int size) {
        items = (Item[]) new Object[size];
        SIZE = size;
        front = rear = -1;
        itemCount = 0;
    }

    public void enQueue(Item item) {
        if (item == null) {
            throw new NullPointerException(NULL_ITEM);
        } else {
            // do not put any check, overright the elements...
            if (itemCount != SIZE) {
                rear = (rear + 1) % SIZE;
                items[rear] = item;
                itemCount++;
            } else {
                System.out.println("queue is full");
            }
        }
    }

    public Item deQueue(Item item) {
        if (itemCount == 0) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            Item value = items[front];
            front = (front + 1) % SIZE;
            itemCount--;
            return value;
        }
    }
}
