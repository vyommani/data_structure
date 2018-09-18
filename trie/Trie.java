import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Trie {
    private final Node root;

    public Trie() {
        root = new Node(' ');
    }

    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.addWord("bear");
        trie.addWord("bell");
        trie.addWord("bid");
        trie.addWord("bull");
        trie.addWord("buy");
        trie.addWord("book");
        trie.addWord("sell");
        trie.addWord("stock");
        trie.addWord("stop");
        trie.addWord("start");
        trie.addWord("status");
        trie.addWord("stack");

        System.out.println(trie.search("bear"));
        System.out.println(trie.findAllWords("st"));
    }

    public void addWord(String word) {
        if (word == null || word.isEmpty()) {
            throw new IllegalArgumentException("Word is n not a valid string");
        } else {
            char[] chars = word.toCharArray();
            Node currentNode = root;
            for (char ch : chars) {
                if (currentNode.childrens.isEmpty()) {
                    Node newNode = new Node(ch);
                    currentNode.childrens.put(ch, newNode);
                    currentNode = newNode;
                } else {
                    Node node = currentNode.childrens.get(ch);
                    if (node != null) {
                        currentNode = node;
                    } else {
                        Node newNode = new Node(ch);
                        currentNode.childrens.put(ch, newNode);
                        currentNode = newNode;
                    }
                }
            }
            currentNode.isCompleteWord = true; // once to reached the last character set the isCompleteWord to true.
        }
    }

    public boolean search(String key) {
        Node currentNode = root;
        for (char ch : key.toCharArray()) {
            Node node = currentNode.childrens.get(ch);
            if (node != null) {
                currentNode = node;
            } else {
                return false;
            }
        }
        return currentNode.isCompleteWord;

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

    static class Node {
        private final HashMap<Character, Node> childrens;
        boolean isCompleteWord;
        private final char ch;

        public Node(char ch) {
            this.ch = ch;
            childrens = new HashMap<>();
        }

        public void setCompleteWord(boolean isCompleteWord) {
            this.isCompleteWord = isCompleteWord;
        }
    }
}
