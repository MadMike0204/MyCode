package org.szucraft.buildandguess.util;

import org.bukkit.Bukkit;
import org.bukkit.entity.Player;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.data.BuilderPlayer;

import java.util.*;

import static org.szucraft.buildandguess.BuildAndGuessGame.builderPlayers;
import static org.szucraft.buildandguess.BuildAndGuessGame.leaderBoard;

public class TitleHelper {

    public static void sendTitle(Player player) {
        if (!BuilderPlayer.isBuilderPlayer(player))
            return;
        player.sendTitle(String.format("Your word is %s", BuilderPlayer.BuilderMap.get(player.getUniqueId()).getWord()), "Time for Building!", 10, 70, 20);
    }

    public static void sendTitleAll(Player builder) {
        for (Player player : Bukkit.getOnlinePlayers())
            player.sendTitle(String.format("Building From %s", player.getName()), String.format("Tip, word length: %d", BuilderPlayer.BuilderMap.get(player.getUniqueId()).getWord().length()), 10, 70, 20);
    }

    public static void broadcast() {
        StringBuilder msg = new StringBuilder();
        msg.append("Match Result:\n");

        List<Map.Entry<Player, Integer>> entryList = new ArrayList<>(leaderBoard.entrySet());

        entryList.sort((o1, o2) -> o2.getValue().compareTo(o1.getValue()));

        for (Map.Entry<Player, Integer> entry : entryList) {
            msg.append(entry.getKey().getName()).append(" : ").append(entry.getValue()).append(" score").append("\n");
        }

        msg.append("----------------------------------");

        BuildAndGuess.instance.getServer().broadcastMessage(String.valueOf(msg));

        for (Player player : Bukkit.getOnlinePlayers()) {
            player.sendTitle("Congratulation to", entryList.get(0).getKey().getName(), 10, 70, 20);
        }
    }

}
