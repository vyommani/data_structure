package com.ds.queue;

import java.util.*;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private static final String NULL_ITEM = "Object is null,you can not add null to deque.";
    private static final String EMPTY_QUEUE = "Queue is empty,you can not remove any element.";
    private static final String REMOVE_NOT_ALLOWED = "Removing a item from iterator is not supported.";

    List<Item> items;
    Random random = new Random();

    public RandomizedQueue() {
        items = new ArrayList<>();
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public int size() {
        return items.size();
    }

    public void enqueue(Item item) {
        if (item == null) {
            throw new NullPointerException(NULL_ITEM);
        } else {
            items.add(item);
        }
    }

    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            int index = random.nextInt(size());
            Item item = items.get(index);
            items.remove(index);
            return item;
        }
    }

    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException(EMPTY_QUEUE);
        } else {
            int index = random.nextInt(size());
            Item item = items.get(index);
            return item;
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new RandomizeQueueIterator();
    }

    class RandomizeQueueIterator implements Iterator<Item> {
        List<Item> randomItems;
        Iterator<Item> iterator;

        public RandomizeQueueIterator() {
            randomItems = new ArrayList<>(items);
            Collections.shuffle(randomItems);
            iterator = randomItems.iterator();
        }

        @Override
        public boolean hasNext() {
            return iterator.hasNext();
        }

        @Override
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException(EMPTY_QUEUE);
            } else {
                return iterator.next();
            }
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException(REMOVE_NOT_ALLOWED);
        }
    }
}
