import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Vyom Tiwari
 */
public class TrieMapTest {

    TrieMap<Integer> instance;

    public TrieMapTest() {
        instance = new TrieMap<>();
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
        instance.put("by", 4);
        instance.put("sea", 6);
        instance.put("sells", 1);
        instance.put("she", 0);
        instance.put("shells", 3);
        instance.put("shore", 7);
        instance.put("the", 5);
    }

    @After
    public void tearDown() {
        instance = new TrieMap<>();
    }

    /**
     * Test of put method, of class TrieMap.
     */
    @Test
    public void testPut() {
        System.out.println("put");
        String key = "test";
        Integer value = 1;
        instance.put(key, value);
        assertEquals(1, instance.get(key).intValue());
        value = 7;
        instance.put(key, value);
        assertEquals(7, instance.get(key).intValue());
    }

    /**
     * Test of get method, of class TrieMap.
     */
    @Test
    public void testGet() {
        System.out.println("get");
        String key = "the";
        Integer expResult = 5;
        Integer result = instance.get(key);
        assertEquals(expResult, result);
    }

    /**
     * Test of contains method, of class TrieMap.
     */
    @Test
    public void testContains() {
        System.out.println("contains");
        String key = "shells";
        boolean expResult = true;
        boolean result = instance.contains(key);
        assertEquals(expResult, result);
        expResult=false;
        key = "not present";
        result = instance.contains(key);
        assertEquals(expResult, result);
        
    }
}
