package org.szucraft.buildandguess.command;

import com.mojang.datafixers.util.Pair;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.inventory.ItemStack;

import org.szucraft.buildandguess.BuildAndGuessGame;

import java.util.Arrays;

public class CommandSetGroupSign {
    private enum Carpets { RED_CARPET, ORANGE_CARPET, YELLOW_CARPET, GREEN_CARPET, LIME_CARPET, CYAN_CARPET, LIGHT_BLUE_CARPET, BLUE_CARPET, PURPLE_CARPET, MAGENTA_CARPET, PINK_CARPET, BROWN_CARPET, WHITE_CARPET, GRAY_CARPET, LIGHT_GRAY_CARPET, BLACK_CARPET }

    public CommandSetGroupSign(CommandSender sender, String arg) {
        if (sender instanceof Player player) {
            if (arg.equals("builder") || arg.equals("viewer")) {
                ItemStack itemStack = player.getInventory().getItemInMainHand();
                Carpets carpetType = Arrays.stream(Carpets.values())
                        .filter(carpet -> carpet.toString().equals(itemStack.getType().toString()))
                        .findFirst().orElse(null);

                if (carpetType != null) {
                    switch(arg) {
                        case "builder" -> BuildAndGuessGame.signBlocks = new Pair<>(itemStack.getType(), BuildAndGuessGame.signBlocks.getSecond());
                        case "viewer" -> BuildAndGuessGame.signBlocks = new Pair<>(BuildAndGuessGame.signBlocks.getFirst(), itemStack.getType());
                    }
                    sender.sendMessage(String.format("New sign floor for %s was set!", arg));
                } else {
                    sender.sendMessage("Wrong items, should be carpets!");
                }
            } else {
                sender.sendMessage("Invalid Parameters!");
            }
        } else {
            sender.sendMessage("This is a player-only command!");
        }
    }
}
