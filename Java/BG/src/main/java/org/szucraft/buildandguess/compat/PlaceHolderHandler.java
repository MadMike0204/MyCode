package org.szucraft.buildandguess.compat;

import org.bukkit.OfflinePlayer;
import org.bukkit.entity.Player;
import org.szucraft.buildandguess.BuildAndGuess;

import me.clip.placeholderapi.expansion.PlaceholderExpansion;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuilderPlayer;

public class PlaceHolderHandler extends PlaceholderExpansion {

    private final BuildAndGuess plugin;

    public PlaceHolderHandler(BuildAndGuess plugin) {
        this.plugin = plugin;
    }

    @Override
    public String getAuthor() {
        return "szucraft";
    }

    @Override
    public String getIdentifier() {
        return "bng";
    }

    @Override
    public String getVersion() {
        return "1.0.0";
    }

    @Override
    public boolean persist() {
        return true;
    }

    @Override
    public String onRequest(OfflinePlayer player, String params) {
        if (player.isOnline()) {
            Player player1 = (Player) player;
            switch (params) {
                case "stage" -> {
                    if (BuildAndGuessGame.isRunning) {
                        switch (BuildAndGuessGame.stage) {
                            case 0 -> {
                                return "Loading Game...";
                            }
                            case 1 -> {
                                return "Building Time";
                            }
                            case 2 -> {
                                return "Guessing Time";
                            }
                        }
                    }
                    return "No Match Active";
                } case "word" -> {
                    if (BuildAndGuessGame.isRunning && BuilderPlayer.isBuilderPlayer(player1))
                        return BuilderPlayer.BuilderMap.get(player1.getUniqueId()).getWord();
                    return "None";
                } case "score" -> {
                    if (BuildAndGuessGame.isRunning && BuildAndGuessGame.leaderBoard.get(player1) != null) {
                        return String.valueOf(BuildAndGuessGame.leaderBoard.get(player1));
                    }
                    return "0";
                }
            }
        }
        return null;
    }
}
