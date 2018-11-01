/*
 * Here comes the text of your license
 * Each line should be prefixed with  * 
 */
package com.ds.trie;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author vytewari
 */
public class TernarySearchTrieMapTest {

    TernarySearchTrieMap<String, Integer> instance;

    public TernarySearchTrieMapTest() {
        instance = new TernarySearchTrieMap<>();
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
        instance.put("now", 1);
        instance.put("for", 2);
        instance.put("tip", 3);
        instance.put("ilk", 4);
        instance.put("dim", 5);
        instance.put("tag", 6);
        instance.put("jot", 7);
        instance.put("sob", 8);
        instance.put("nob", 9);
        instance.put("sky", 10);
        instance.put("hut", 11);
        instance.put("ace", 12);
        instance.put("bet", 13);
        instance.put("men", 14);
        instance.put("egg", 15);
        instance.put("few", 16);
        instance.put("jay", 17);
        instance.put("owl", 18);
        instance.put("joy", 19);
        instance.put("rap", 20);
        instance.put("gig", 21);
        instance.put("wee", 22);
        instance.put("was", 23);
        instance.put("cab", 24);
        instance.put("wad", 25);
        instance.put("caw", 26);
        instance.put("cue", 27);
        instance.put("fee", 28);
        instance.put("tap", 29);
        instance.put("ago", 30);
        instance.put("tar", 31);
        instance.put("jam", 32);
        instance.put("dug", 33);
        instance.put("and", 34);

    }

    @After
    public void tearDown() {
        instance = new TernarySearchTrieMap<>();
    }

    /**
     * Test of get method, of class TernarySearchTrieMap.
     */
    @Test
    public void testGet() {
        System.out.println("get");
        int result = instance.get("now");
        assertEquals(1, result);
        assertEquals(null, instance.get("not present"));
    }

    /**
     * Test of put method, of class TernarySearchTrieMap.
     */
    @Test
    public void testPut() {
        System.out.println("put");
        Object result = instance.put("vyom", 123);
        assertEquals(123, result);
    }

    /**
     * Test of contains method, of class TernarySearchTrieMap.
     */
    @Test
    public void testContains() {
        System.out.println("contains");
        assertEquals(true, instance.contains("rap"));
        assertEquals(false, instance.contains("rap1"));
    }

    /**
     * Test of size method, of class TernarySearchTrieMap.
     */
    @Test
    public void testSize() {
        System.out.println("size");
        assertEquals(34, instance.size());
        instance.put("testkey", 35);
        assertEquals(35, instance.size());
    }

    /**
     * Test of isEmpty method, of class TernarySearchTrieMap.
     */
    @Test
    public void testIsEmpty() {
        System.out.println("isEmpty");
        assertEquals(false, instance.isEmpty());

    }

    /**
     * Test of containsKey method, of class TernarySearchTrieMap.
     */
    @Test
    public void testContainsKey() {
        System.out.println("containsKey");
        assertEquals(true, instance.containsKey("jam"));
    }

    /**
     * Test of remove method, of class TernarySearchTrieMap.
     */
    @Test
    public void testRemove() {
        System.out.println("remove");
        instance.remove("now");
        assertEquals(false, instance.contains("now"));
        assertEquals(null, instance.remove("now1"));
        int result = instance.remove("and");
        assertEquals(34, result);
        instance.put("and", 35);
        instance.put("and", 36);
        instance.put("and", 37);
        assertEquals(33, instance.size());
        result= instance.get("and");
        assertEquals(37, result);
    }
}
