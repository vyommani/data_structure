package com.mi.tlv;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vytewari
 */
class TLVCommandController extends Thread {

    private final InputStream inputStream;
    private final OutputStream outputStream;

    public TLVCommandController(InputStream is, OutputStream os) {
        inputStream = is;
        outputStream = os;
        setDaemon(true);
    }

    @Override
    public void run() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        while (true) {
            try {
                String inp = "";
                while ((inp = reader.readLine()) != null) {
                    Thread tlvHandler = new Thread(new TLVCommandHandler(inp, outputStream));
                    tlvHandler.setDaemon(true);
                    tlvHandler.start();
                }
            } catch (IOException ignore) {
                Logger.getLogger(TLVCommandController.class.getName()).log(Level.SEVERE, null, ignore);
            }
        }
    }

    static class TLVCommandHandler implements Runnable {

        private static final CommandSupplier SUPPLIER = CommandSupplier.getInstance();
        String cmd;
        OutputStream os;

        public TLVCommandHandler(String inpString, OutputStream os) {
            cmd = inpString;
            this.os = os;
        }

        @Override
        public void run() {
            List<Command> commandList = null;
            try {
                commandList = TLVParser.parse(cmd, SUPPLIER);
            } catch (RuntimeException re) {
                //ignore any parsing error for now.
                return;
            }
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
            for (Command command : commandList) {
                CommandResult result = new CommandProcessor(command).runCmd();
                if (result.getStatus() == CommandResult.SUCCESS) {
                    try {
                        writer.write(result.getResult());
                        writer.flush();
                    } catch (IOException ex) {
                        Logger.getLogger(TLVCommandController.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        }
    }
}
