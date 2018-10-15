import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Trie {
    private final Node root;

    public Trie() {
        root = new Node(' ');
    }

    public void addWord(String word) {
        if (word == null || word.isEmpty()) {
            throw new IllegalArgumentException("Word is not a valid string");
        } else {
            char[] chars = word.toCharArray();
            Node currentNode = root;
            for (char ch : chars) {
                if (currentNode.childrens.isEmpty()) {
                    Node newNode = new Node(ch);
                    newNode.parent = currentNode;
                    currentNode.childrens.put(ch, newNode);
                    currentNode = newNode;
                } else {
                    Node node = currentNode.childrens.get(ch);
                    if (node != null) {
                        currentNode = node;
                    } else {
                        Node newNode = new Node(ch);
                        newNode.parent = currentNode;
                        currentNode.childrens.put(ch, newNode);
                        currentNode = newNode;
                    }
                }
            }
            currentNode.isCompleteWord = true; // once to reached the last character set the isCompleteWord to true.
        }
    }

    public boolean search(String key) {
        Node currentNode = null;
        try {
            currentNode = search0(key);
        } catch (RuntimeException e) {
            return false;
        }
        return currentNode.isCompleteWord;
    }

    public Node search0(String key) {
        Node currentNode = root;
        for (char ch : key.toCharArray()) {
            Node node = currentNode.childrens.get(ch);
            if (node != null) {
                currentNode = node;
            } else {
                throw new RuntimeException("key not present.");
            }
        }
        return currentNode;

    }

    public List<String> findAllWords(String prefix) {
        Node currentNode = root;
        for (char ch : prefix.toCharArray()) {
            Node node = currentNode.childrens.get(ch);
            if (node != null) {
                currentNode = node;
            } else {
                return List.of(); // this will return the empty list
            }
        }
        // now we reached to the prefix node;
        return fetchAllWords(prefix, currentNode);
    }

    private List<String> fetchAllWords(String prefix, Node startNode) {
        if (startNode.childrens.isEmpty()) {
            List<String> list = new ArrayList<>();
            list.add(prefix); // no childrens , so just add the matched prefix.
            return list;
        } else {
            List<String> list = new ArrayList<>();
            for (Node node : startNode.childrens.values()) {
                list.addAll(fetchAllWords(prefix + node.ch, node));
            }
            return list;
        }
    }

    public boolean deleteWord(String word) {

        Node nodeToDelete = null;
        try {
            nodeToDelete = search0(word);
        } catch (RuntimeException re) {
            return false;
        }
        // we reached to the last character of word to be deleted
        if (!nodeToDelete.isCompleteWord) // if it is not a word you can not delete it.
            return false;
        else {
            if (!nodeToDelete.childrens.isEmpty()) // If node has childrens you can not delete , just make the isCompleteWord to false.
                nodeToDelete.isCompleteWord = false;
            else {
                Node parent = nodeToDelete.parent;
                parent.childrens.values().remove(nodeToDelete);
                // if parent does not have any child delete parent as well.
                nodeToDelete = parent;
                parent = parent.parent;
                while (parent.childrens.size() == 1) {
                    parent.childrens.values().remove(nodeToDelete);
                    nodeToDelete = parent;
                    parent = parent.parent;
                }
            }
            return true;
        }
    }

    static class Node {
        private final Map<Character, Node> childrens;
        private final char ch;
        boolean isCompleteWord;
        private Node parent; // we need parent while deleting a word.

        public Node(char ch) {
            this.ch = ch;
            childrens = new HashMap<>();
        }

        public void setCompleteWord(boolean isCompleteWord) {
            this.isCompleteWord = isCompleteWord;
        }
    }
}
