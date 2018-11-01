package com.ds.trie;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

/**
 * Ternary search trie is a data structure based on character comparisons.
 * Ternary tree is like a binary tree except: Each internal node has three
 * children: smaller, equal and larger.The branching is based on a single
 * character at a given position. The position is zero at the root and increases
 * along the middle branches.
 *
 * @author Vyom tewari
 * @param <K> this should be String
 * @param <V>
 */
public class TernarySearchTrieMap<K, V> implements Map<K, V> {

    private Node<V> root;

    private int size;

    @Override
    public V get(Object key) {
        if (!(key instanceof String)) {
            throw new IllegalArgumentException("key should be string.");
        }
        Node<V> node = get0(root, (String) key, 0);
        return node == null ? null : node.value;
    }

    @Override
    public V put(K key, V value) {
        if (!(key instanceof String)) {
            throw new IllegalArgumentException("key should be string.");
        } else {
            // this is costly, i need to optimize it. In put0 there is no way 
            // to identify if it is update or new key.
            boolean newItem = false;
            if (get(key) == null) {
                newItem = true;
            }
            root = put0(root, root, (String) key, value, 0);
            if (newItem) {
                size++;
            }
            return value;
        }
    }

    private Node<V> put0(Node parent, Node root, String key, V value, int index) {
        char ch = key.charAt(index);
        if (root == null) {
            Node<V> newNode = new Node<>(ch);
            newNode.parent = parent; // we will use parent while removing K,V pair from map.
            root = newNode;
        }
        if (ch < root.ch) {
            root.left = put0(root, root.left, key, value, index);
        } else if (ch > root.ch) {
            root.right = put0(root, root.right, key, value, index);
        } else if (index < key.length() - 1) {
            root.middle = put0(root, root.middle, key, value, index + 1);
        } else {
            root.value = value;
        }
        return root;
    }

    private Node<V> get0(Node root, String key, int index) {
        char ch = key.charAt(index);
        if (root == null) {
            return null;
        } else {
            if (ch < root.ch) {
                return get0(root.left, key, index);
            } else if (ch > root.ch) {
                return get0(root.right, key, index);
            } else if (index < key.length() - 1) {
                return get0(root.middle, key, index + 1);
            } else {
                return root;
            }
        }
    }

    public boolean contains(String key) {
        Node<V> node = get0(root, key, 0);
        return (node != null && node.value != null);
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean containsKey(Object key) {
        Node<V> node = get0(root, (String) key, 0);
        return (node != null && node.value != null);
    }

    @Override
    public boolean containsValue(Object value) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public V remove(Object key) {
        if (!(key instanceof String)) {
            throw new IllegalArgumentException("key should be string.");
        }
        Node<V> nodeToDelete = get0(root, (String) key, 0);
        if (nodeToDelete == null || nodeToDelete.value == null) {
            return null;
        } else {
            V value = nodeToDelete.value;
            //nodeToDelete.value = null;
            removeNode(nodeToDelete);
            size--;
            return value;
        }
    }

    private void removeNode(Node<V> nodeToDelete) {
        if (hasNoChilds(nodeToDelete)) {
            if (nodeToDelete.parent != null) {
                Node<V> parent = nodeToDelete.parent;
                removeChildNode(parent, nodeToDelete);
                removeNode(parent); // recursivelly delete parent as well.
            } else {
                nodeToDelete.value = null;
            }
        } else {
            nodeToDelete.value = null;
        }
    }

    private void removeChildNode(Node<V> parent, Node<V> nodeToBeDeleted) {
        if (parent.left == nodeToBeDeleted) {
            parent.left = null;
        }
        if (parent.middle == nodeToBeDeleted) {
            parent.middle = null;
        }
        if (parent.right == nodeToBeDeleted) {
            parent.right = null;
        }
    }

    private boolean hasNoChilds(Node<V> node) {
        return (node.left == null && node.middle == null && node.right == null);
    }

    @Override
    public void putAll(Map<? extends K, ? extends V> m) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void clear() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<K> keySet() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Collection<V> values() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<Entry<K, V>> entrySet() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    private static class Node<V> {

        char ch;
        V value;
        Node left, middle, right, parent;

        public Node(char ch) {
            this.ch = ch;
            left = null;
            middle = null;
            right = null;
            parent = null;
        }
    }
}
