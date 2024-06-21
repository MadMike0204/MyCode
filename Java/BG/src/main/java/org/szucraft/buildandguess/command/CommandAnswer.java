package org.szucraft.buildandguess.command;

import org.bukkit.Bukkit;
import org.bukkit.command.CommandSender;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.KeeperPlayer;

import java.util.Objects;
import java.util.UUID;

public class CommandAnswer {

    public CommandAnswer(CommandSender sender) {
        StringBuilder msg = new StringBuilder();
        if (BuildAndGuessGame.isRunning) {
            msg.append("Player Name - Correct Word:\n");
            for (UUID uuid : BuilderPlayer.BuilderMap.keySet()) {
                msg.append(Objects.requireNonNull(Bukkit.getPlayer(uuid)).getName()).append(" - ");
                msg.append(Objects.requireNonNull(BuilderPlayer.BuilderMap.get(uuid)).getWord()).append("\n");
            }
        } else {
            msg.append("The game haven't start yet!");
        }
        sender.sendMessage(String.valueOf(msg));
    }

}
