package org.szucraft.buildandguess.util;

import org.bukkit.entity.Player;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.data.BuilderPlayer;

import static org.szucraft.buildandguess.BuildAndGuessGame.*;

public class WordCheckHelper {

    public static boolean canGuess(Player player) {
        if (currentStatus.get(player) != null && leaderBoard.get(player) != null) {
            return currentStatus.get(player) >= 0 && currentStatus.get(player) < maxTime;
        }
        return false;
    }

    public static void check(Player player, String msg) {
        if (BuilderPlayer.isBuilderPlayer(player) && BuilderPlayer.BuilderMap.get(player.getUniqueId()).equals(curerentBuilder)) {
            player.sendMessage("You are the current builder, just wait for others!");
            return;
        }
        if (!canGuess(player)) {
            player.sendMessage("No more chance!");
            return;
        }
        if (msg.length() != currentWord.length()) {
            player.sendMessage("Wrong length of word!");
            return;
        }
        if (msg.equals(currentWord)) {
            player.sendMessage("Correct!");
            BuildAndGuess.instance.getServer().broadcastMessage(String.format("Player %s found the correct answer!", player.getName()));
            currentStatus.put(player, -1);
            switch (currentCorrect) {
                case 0 -> leaderBoard.put(player, leaderBoard.get(player) + 3);
                case 1 -> leaderBoard.put(player, leaderBoard.get(player) + 2);
                default -> leaderBoard.put(player, leaderBoard.get(player) + 1);
            }
            currentCorrect += 1;
        } else {
            currentStatus.put(player, currentStatus.get(player) + 1);
            player.sendMessage(String.format("Wrong answer, %d times left", maxTime - currentStatus.get(player)));
        }
    }

}
