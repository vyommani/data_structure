package com.mi.tlv;

import java.io.InputStream;
import java.io.OutputStream;

/**
 *
 * @author vytewari
 */
public class TLVProcessor {

    public static void main(String args[]) {
        InputStream is = System.in;
        OutputStream os = System.out;
        TLVCommandController tLVCommandController = new TLVCommandController(is, os);
        tLVCommandController.start();
        try {
            tLVCommandController.join();
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}
