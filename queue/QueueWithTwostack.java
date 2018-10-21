package com.ds.queue;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Stack;

public class QueueWithTwostack<Item> implements Iterable<Item> {

    private static final String NULL_ITEM = "Object is null,you can not add null to deque.";
    private static final String EMPTY_QUEUE = "Queue is empty,you can not remove any element.";
    private static final String REMOVE_NOT_ALLOWED = "Removing a item from iterator is not supported.";

    private final Stack<Item> firstStack;
    private final Stack<Item> secondStack;

    public QueueWithTwostack() {
        firstStack = new Stack<>();
        secondStack = new Stack<>();
    }

    public void enqueue(Item item) {
        firstStack.push(item);
    }

    public Item dequeue() {
        if (!secondStack.empty()) {
            return secondStack.pop();
        } else {
            while (!firstStack.empty()) {
                secondStack.push(firstStack.pop());
            }
            return secondStack.pop();
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new QueueIterator();
    }

    class QueueIterator implements Iterator<Item> {

        Stack<Item> first = firstStack, second = secondStack;

        @Override
        public boolean hasNext() {
            return !first.empty() || !second.empty();
        }

        @Override
        public Item next() {
            Item item = null;
            if (!hasNext()) {
                throw new NoSuchElementException(EMPTY_QUEUE);
            } else {
                if (!second.empty()) {
                    item = second.pop();
                } else {
                    while (!first.empty()) {
                        second.push(first.pop());
                    }
                    item = second.pop();
                }
            }
            return item;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException(REMOVE_NOT_ALLOWED);
        }
    }
}
