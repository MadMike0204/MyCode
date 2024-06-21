package org.szucraft.counterapi;

import java.util.Objects;
import javax.annotation.ParametersAreNonnullByDefault;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;

public class CommandUtil implements CommandExecutor {

    @ParametersAreNonnullByDefault
    public boolean onCommand(CommandSender commandSender, Command command, String label, String[] args) {
        if (args.length != 0) {
            String op = args[0];
            String counter;
            String counter1;
            int e;
            if (Objects.equals(op, "add")) {
                if (args.length != 4) {
                    return true;
                }
                counter = args[1];
                counter1 = args[2];

                try {
                    e = Integer.parseInt(args[3]);
                    if (CounterAPI.updateDataAdd(counter, counter1, e)) {
                        commandSender.sendMessage("Done.");
                    } else {
                        commandSender.sendMessage("Failed.");
                    }
                } catch (NumberFormatException var10) {
                    commandSender.sendMessage("Wrong Value.");
                }
            } else if (Objects.equals(op, "set")) {
                if (args.length != 4) {
                    return true;
                }

                counter = args[1];
                counter1 = args[2];

                try {
                    e = Integer.parseInt(args[3]);
                    if (CounterAPI.updateDataSet(counter, counter1, e)) {
                        commandSender.sendMessage("Done.");
                    } else {
                        commandSender.sendMessage("Failed.");
                    }
                } catch (NumberFormatException var9) {
                    commandSender.sendMessage("Wrong Value.");
                }
            } else if (Objects.equals(op, "create")) {
                if (args.length != 2) {
                    return true;
                }

                counter = args[1];
                if (CounterAPI.createCounter(counter)) {
                    commandSender.sendMessage("Done.");
                } else {
                    commandSender.sendMessage("Failed.");
                }
            } else if (Objects.equals(op, "reset")) {
                CounterAPI.reset();
            }

        }
        return true;
    }
}