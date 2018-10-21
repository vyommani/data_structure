package com.ds.queue;


/**
 * @param <Item>
 * @author vyom tewari
 */
public class BlockingQueue<Item> {

    private final int QUEUE_SIZE;
    private final Item arr[];
    private volatile int itemCount = 0;
    private volatile int front, rear;

    public BlockingQueue(int size) {
        front = rear = 0;
        arr = (Item[]) new Object[size]; //this ugly cast is because Java does not provide a way to create a gneric list
        QUEUE_SIZE = size;
    }


    public synchronized void put(Item item) {
        while (true) {
            if (itemCount == QUEUE_SIZE) {
                try {
                    this.wait();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            } else {
                rear = (rear + 1) % QUEUE_SIZE;
                arr[rear] = item;
                itemCount++;
                this.notifyAll();
                return;
            }
        }
    }

    public synchronized Item get() {
        Item item = null;
        while (true) {
            if (itemCount == 0) {
                try {
                    this.wait();
                } catch (InterruptedException ex) {
                    Thread.currentThread().interrupt();
                }
            } else {
                front = (front + 1) % QUEUE_SIZE;
                itemCount--;
                item = arr[front];
                this.notifyAll();
                return item;
            }
        }
    }
}