/**
 *
 * @author Vyom Tewari
 * @param <Value>
 */
public class TrieMap<Value> {

    private static final short CHAR_SET = 256; //ASCII character set
    private Node<Value> root = new Node<>();

    public void put(String key, Value value) {
        root = put0(root, key, value, 0);
    }

    private Node<Value> put0(Node<Value> root, String key, Value value, int index) {
        if (root == null) {
            root = new Node<>();
        }
        if (index == key.length()) {
            root.value = value;
            return root;
        }
        char c = key.charAt(index);
        root.childs[c] = put0(root.childs[c], key, value, index + 1);
        return root;
    }

    public Value get(String key) {
        Node<Value> valueNode = get0(root, key, 0);
        return valueNode == null ? null : valueNode.value;
    }

    public boolean contains(String key) {
        return get0(root, key, 0) != null;
    }

    private Node<Value> get0(Node<Value> root, String key, int index) {
        if (root == null) {
            return null;
        }
        if (key.length() == index) {
            return root;
        }
        char c = key.charAt(index);
        return get0(root.childs[c], key, index + 1);
    }

    private static class Node<Value> {
        private Value value;
        private Node<Value>[] childs = new Node[CHAR_SET];
    }
}
