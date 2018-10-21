package com.ds.queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Queue<Item> implements Iterable<Item> {

    private static final String NULL_ITEM = "Object is null,you can not add null to deque.";
    private static final String EMPTY_QUEUE = "Queue is empty,you can not remove any element.";
    private static final String REMOVE_NOT_ALLOWED = "Removing a item from iterator is not supported.";

    private Node front;
    private Node rear;
    private int size;

    public Queue() {
        front = rear = null;
        size = 0;
    }

    @Override
    public Iterator<Item> iterator() {
        return new QueueIterator();
    }

    public boolean isEmpty() {
        return (size == 0);
    }

    public int size() {
        return size;
    }

    public void enqueue(Item item) {
        if (item == null) {
            throw new NullPointerException(NULL_ITEM);
        } else {
            Node newNode = new Node();
            newNode.item = item;
            newNode.next = null;
            if (isEmpty()) {
                newNode.prev = null;
                rear = newNode;
                front = newNode;
            } else {
                rear.next = newNode;
                newNode.prev = rear;
                rear = newNode;
            }
            size++;
        }
    }

    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            Item item = front.item;
            front = front.next;
            if (front != null) {
                front.prev = null;
            }
            size--;
            return item;
        }
    }

    class Node {
        private Item item;
        private Node next;
        private Node prev;
    }

    class QueueIterator implements Iterator<Item> {

        private Node current = front;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException(EMPTY_QUEUE);
            } else {
                Item item = current.item;
                current = current.next;
                return item;
            }
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException(REMOVE_NOT_ALLOWED);
        }
    }
}
