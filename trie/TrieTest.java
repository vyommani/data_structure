import java.util.List;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Vyom Tewari
 */
public class TrieTest {

    Trie instance;

    public TrieTest() {
        instance = new Trie();
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
        instance.addWord("bear");
        instance.addWord("bell");
        instance.addWord("bid");
        instance.addWord("bull");
        instance.addWord("buy");
        instance.addWord("book");
        instance.addWord("sell");
        instance.addWord("stock");
        instance.addWord("stop");
        instance.addWord("start");
        instance.addWord("status");
        instance.addWord("stack");
    }

    @After
    public void tearDown() {
        instance = new Trie();
    }

    /**
     * Test of addWord method, of class Trie.
     */
    @Test
    public void testAddWord() {
        System.out.println("addWord test");
        instance.addWord("bullward");
        assertEquals(true, instance.search("bullward"));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testAddNULLWord() {
        System.out.println("addWord test, adding null to trie");
        instance.addWord(null);
        instance.addWord("");
    }
    /**
     * Test of search method, of class Trie.
     */
    @Test
    public void testSearch() {
        System.out.println("search");

        assertEquals(true, instance.search("bear"));
        assertEquals(false, instance.search("bear1"));
        assertEquals(false, instance.search("bea"));
        assertEquals(false, instance.search("notpresent"));

    }

    /**
     * Test of findAllWords method, of class Trie.
     */
    @Test
    public void testFindAllWords() {
        System.out.println("findAllWords");
        String prefix = "st"; // find all word which starts with st
        
        List<String> expResult = List.of("stock", "stop", "start", "status", "stack");
        List<String> result = instance.findAllWords(prefix);
        for (String word : result) {
            assertEquals(true, expResult.contains(word));
        }
    }

    /**
     * Test of deleteWord method, of class Trie.
     */
    @Test
    public void testDeleteWord() {
        System.out.println("deleteWord");
        String word = "bear";
        
        boolean expResult = true;
        boolean result = instance.deleteWord(word);
        assertEquals(expResult, result);
        assertEquals(false, instance.search(word));

        word = "notpresent";
        expResult = false;
        result = instance.deleteWord(word);
        assertEquals(expResult, result);

        word = "stop";
        expResult = true;
        result = instance.deleteWord(word);
        assertEquals(expResult, result);
    }
}
