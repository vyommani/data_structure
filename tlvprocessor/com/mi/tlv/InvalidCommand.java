package com.mi.tlv;

import java.util.Objects;

/**
 *
 * @author vytewari
 */
class InvalidCommand implements Command {

    private final String data;
    private final CommandSupplier supplier;
    private final String CODE = "";

    public InvalidCommand(String data, CommandSupplier supplier) {
        this.data = data;
        this.supplier = supplier;
    }

    /**
     *
     * @return the com.mi.tlv.CommandResult
     */
    @Override
    public CommandResult execute() {
        return new CommandResult(CommandResult.SUCCESS, CODE + supplier.error());
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 89 * hash + Objects.hashCode(this.data);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final InvalidCommand other = (InvalidCommand) obj;
        return Objects.equals(this.data, other.data);
    }

}
