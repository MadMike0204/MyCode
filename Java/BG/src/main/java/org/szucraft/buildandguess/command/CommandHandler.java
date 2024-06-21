package org.szucraft.buildandguess.command;

import java.util.Objects;
import javax.annotation.ParametersAreNonnullByDefault;

import org.bukkit.Bukkit;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;

public class CommandHandler implements CommandExecutor {

    private final BuildAndGuess plugin;

    public CommandHandler(BuildAndGuess plugin) {
        this.plugin = plugin;
        this.init();
    }

    public void init() {
        if (Bukkit.getPluginCommand("buildandguess") != null) {
            Objects.requireNonNull(Bukkit.getPluginCommand("buildandguess")).setExecutor(this);
        }
    }

    @ParametersAreNonnullByDefault
    public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
        if (args.length != 0) {
            String op = args[0];
            switch (op) {
                case "set" -> {
                    if (args.length == 2)
                        new CommandSetGroupSign(sender, args[1]);
                }
                case "list" -> {
                    if (args.length == 1)
                        new CommandList(sender);
                }
                case "start" -> {
                    if (args.length == 1)
                        BuildAndGuessGame.run(sender);
                }
                case "stop" -> {
                    if (args.length == 1)
                        BuildAndGuessGame.stop(sender);
                }
                case "answer" -> {
                    if (args.length == 1)
                        new CommandAnswer(sender);
                }
                case "keeper" -> {
                    if (args.length == 1)
                        new CommandKeeper(sender);
                }
                case "reload" -> {
                    if (args.length == 1)
                        plugin.configHandler.init();
                }
            }
        }
        return true;
    }
}