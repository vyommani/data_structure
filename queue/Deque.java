package com.ds.queue;


import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * A double-ended queue (abbreviated to deque) is an abstract data type that
 * generalizes a queue, for which elements can be added to or removed from either
 * the front (head) or back (tail).
 * @param <Item>
 * @author Vyom tewari
 */
public class Deque<Item> implements Iterable<Item> {

    private static final String NULL_ITEM = "Object is null,you can not add null to deque.";
    private static final String EMPTY_QUEUE = "Queue is empty,you can not remove any element.";
    private static final String REMOVE_NOT_ALLOWED = "Removing a item from iterator is not supported.";
    private Node first;
    private Node last;
    private int size;

    /**
     *
     */
    public Deque() {
        first = last = null;
    }

    /**
     * @return
     */
    public boolean isEmpty() {
        return (size == 0);
    }

    /**
     * @return
     */
    public int size() {
        return size;
    }

    /**
     * @param item
     */
    public void addFirst(Item item) {
        if (item == null) {
            throw new NullPointerException(NULL_ITEM);
        } else {
            if (isEmpty()) {
                Node newNode = new Node();
                newNode.item = item;
                newNode.prev = null;
                newNode.next = null;
                first = newNode;
                last = newNode;
            } else {
                Node oldFirst = first;
                first = new Node();
                first.item = item;
                first.prev = null;
                first.next = oldFirst;
                oldFirst.prev = first;
            }
            size++;
        }
    }

    /**
     * @param item
     */
    public void addLast(Item item) {
        if (item == null) {
            throw new NullPointerException(NULL_ITEM);
        } else {
            if (isEmpty()) {
                Node newNode = new Node();
                newNode.item = item;
                newNode.prev = null;
                newNode.next = null;
                last = newNode;
                first = newNode;
            } else {
                Node newNode = new Node();
                newNode.item = item;
                newNode.prev = last;
                newNode.next = null;
                last.next = newNode;
                last = newNode;
            }
            size++;
        }
    }

    /**
     * @return
     */
    public Item removeFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            Item item = first.item;
            first = first.next;
            if (first != null) {
                first.prev = null;
            }
            size--;
            return item;
        }
    }

    /**
     * @return
     */
    public Item removeLast() {
        if (isEmpty()) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            Item item = last.item;
            last = last.prev;
            if (last != null) {
                last.next = null;
            }
            size--;
            return item;
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    class Node {
        private Item item;
        private Node next;
        private Node prev;
    }

    private class DequeIterator implements Iterator<Item> {

        private Node current = first;

        @Override
        public boolean hasNext() {
            return (current != null);
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