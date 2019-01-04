package com.mi.tlv;

/**
 *
 * @author vytewari
 */
public class CommandSupplier {

    private static final CommandSupplier COMMAND_SUPPLIER = new CommandSupplier();
    private static final String REPLACE_STRING = "THIS STRING";
    private static final String ERROR_STRING = "Type not valid";
    private static final String NEW_LINE = "\n";

    private CommandSupplier() {

    }

    static CommandSupplier getInstance() {
        return COMMAND_SUPPLIER;
    }

    String convertUpperCase(String data) {
        return data.toUpperCase() + NEW_LINE;
    }

    String replace(String data) {
        return REPLACE_STRING + NEW_LINE;
    }

    String error() {
        return ERROR_STRING + NEW_LINE;
    }
}
