package com.mi.tlv;

/**
 *
 * @author vytewari
 */
public class CommandProcessor {

    private final Command myCommand;

    public CommandProcessor(Command command) {
        myCommand = command;
    }

    public CommandResult runCmd() {
        return myCommand.execute();
    }
}
