package org.szucraft.buildandguess.command;

import com.mojang.datafixers.util.Pair;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.inventory.ItemStack;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.KeeperPlayer;

import java.util.Arrays;

public class CommandKeeper {

    public CommandKeeper(CommandSender sender) {
        if (!BuildAndGuessGame.isRunning) {
            if (sender instanceof Player player) {
                if ( KeeperPlayer.KeeperMap.get(player.getUniqueId()) == null) {
                    new KeeperPlayer(player);
                    if (BuilderPlayer.isBuilderPlayer(player))
                        BuilderPlayer.removeBuilderPlayer(player);
                    sender.sendMessage("You are now a keeper for the game!");
                } else {
                    KeeperPlayer.removeBuilderPlayer(player);
                    sender.sendMessage("You are no longer a keeper for the game!");
                }
            } else {
                sender.sendMessage("This is a player-only command!");
            }
        }
    }

}
