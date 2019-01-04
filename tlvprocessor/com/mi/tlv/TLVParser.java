package com.mi.tlv;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author vytewari
 */
public final class TLVParser {

    // Java 9 has better way of doing below.
    private static final Map<String, String> VALID_CMD_MAPPINGS = new HashMap<>();
    private static final short TYPE_LENGTH = 6;
    private static final short LENGTH_LENGTH = 4;
    private static final short HYPHEN_LENGTH = 1;

    static {
        VALID_CMD_MAPPINGS.put("UPPRCS", "com.mi.tlv.UpprCSCommand");
        VALID_CMD_MAPPINGS.put("REPLCE", "com.mi.tlv.ReplceCommand");
    }

    /**
     * This will parse the input and return the parse commands.
     *
     * @param inputString
     * @param commandSupplier
     * @return
     */
    public static List<Command> parse(String inputString, CommandSupplier commandSupplier) {
        List<Command> cmdList = new ArrayList<>();
        if (inputString == null) {
            throw new NullPointerException("Invalid string,TLV string can not be null.");
        } else {
            int inpLength = inputString.length(), index = 0;
            try {
                while (index < inpLength) {
                    String type = inputString.substring(index, (index + TYPE_LENGTH));
                    index += (TYPE_LENGTH + HYPHEN_LENGTH);
                    String length = inputString.substring(index, (index + LENGTH_LENGTH));
                    index += (LENGTH_LENGTH + HYPHEN_LENGTH);
                    int valLength = Integer.parseInt(length);
                    String value = inputString.substring(index, (index + valLength));
                    cmdList.add(constructCommand(type, value, commandSupplier));
                    index += valLength;
                }
            } catch (RuntimeException re) {
                //throw this exception only if no valid command so for.
                if (cmdList.isEmpty()) {
                    throw re;
                } else {
                    //ignore the malformed command.
                }
            }
        }
        return cmdList;
    }

    private static Command constructCommand(String type, String value, CommandSupplier supplier) {
        String cmdClass = VALID_CMD_MAPPINGS.get(type);
        Command cmd = null;
        if (cmdClass != null) {
            try {
                Class c = Class.forName(cmdClass);
                Constructor constructor = c.getConstructor(String.class, CommandSupplier.class);
                cmd = (Command) constructor.newInstance(value, supplier);
            } catch (ClassNotFoundException | InstantiationException
                    | IllegalAccessException | NoSuchMethodException
                    | SecurityException | IllegalArgumentException
                    | InvocationTargetException ex) {
                // In case of any parsing error construct the InvalidCommand
                cmd = new InvalidCommand(value, supplier);
            }
        } else {
            cmd = new InvalidCommand(value, supplier);
        }
        return cmd;
    }
}
