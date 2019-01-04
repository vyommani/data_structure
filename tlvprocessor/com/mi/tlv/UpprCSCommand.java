package com.mi.tlv;

import java.util.Objects;

/**
 *
 * @author vytewari
 */
class UpprCSCommand implements Command {

    private final String data;
    private final CommandSupplier supplier;
    private final String CODE = "UPPRCS-";

    public UpprCSCommand(String data, CommandSupplier supplier) {
        this.data = data;
        this.supplier = supplier;
    }

    /**
     *
     * @return the com.mi.tlv.CommandResult
     */
    @Override
    public CommandResult execute() {
        return new CommandResult(CommandResult.SUCCESS, CODE + supplier.convertUpperCase(data));
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 37 * hash + Objects.hashCode(this.data);
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
        final UpprCSCommand other = (UpprCSCommand) obj;
        return Objects.equals(this.data, other.data);
    }

}
