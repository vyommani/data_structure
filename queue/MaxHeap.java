package com.ds.queue;

public class MaxHeap<Key extends Comparable<Key>> {
    private final Key keys[];
    private int elementCount;
    private static final int DEFAULT_SIZE=37;

    public MaxHeap(){
        keys= (Key[]) new Comparable[DEFAULT_SIZE];
    }

    public MaxHeap(final int capacity){
        //we store elements from index 1 to make calculation simple.
        keys= (Key[]) new Comparable[capacity+1];
    }

    public void insert(Key k){
        keys[++elementCount]=k;
        swim(elementCount);
    }

    public Key deleteMax(){
        Key key=keys[1];
        keys[1]=keys[elementCount];
        sink(1);
        keys[elementCount--]=null;
        return key;
    }

    private void swim(int lastIndex){
        while (lastIndex >1 && less(lastIndex/2,lastIndex)){
            swap(lastIndex/2,lastIndex);
            lastIndex=lastIndex/2;
        }
    }

    private void sink(int index){
        while(2*index <=elementCount){
            int j=2*index;
            if(!less(j,index)){
                break;
            }else
            {
                swap(index,j);
                index=j;
            }
        }
    }
    private boolean less(int firstIndex,int secondIndex){

        return keys[firstIndex].compareTo(keys[secondIndex]) < 0;
    }

    private  void swap(int firstIndex,int secondIndex){
        Key k=keys[firstIndex];
        keys[firstIndex]=keys[secondIndex];
        keys[secondIndex]=k;
    }
}
