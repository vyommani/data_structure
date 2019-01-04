package com.mi.tlv;

/**
 *
 * @author vytewari
 */
public class CommandResult {

    public static short FAILED = 0;
    public static short SUCCESS = 1;
    private final short status;
    private final String data;

    public CommandResult(short status, String data) {
        this.status = status;
        this.data = data;
    }

    public String getResult() {
        return data;
    }

    public short getStatus() {
        return status == 1 ? SUCCESS : FAILED;
    }
}
