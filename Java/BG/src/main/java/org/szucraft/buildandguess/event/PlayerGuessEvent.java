package org.szucraft.buildandguess.event;

import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.AsyncPlayerChatEvent;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.event.player.PlayerQuitEvent;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.util.WordCheckHelper;

public class PlayerGuessEvent implements Listener {

    @EventHandler
    public void onChat(AsyncPlayerChatEvent event) {
        if (BuildAndGuessGame.isRunning && BuildAndGuessGame.currentWord != null) {
            Player player = event.getPlayer();
            String msg = event.getMessage();
            event.setCancelled(true);
            WordCheckHelper.check(player, msg);
        }
    }

    @EventHandler
    public void onPlayerJoinIn(PlayerJoinEvent event) {
        BuildAndGuessGame.bossBar.addPlayer(event.getPlayer());
    }

    @EventHandler
    public void onPlayerJoinQuit(PlayerQuitEvent event) {
        BuildAndGuessGame.bossBar.removePlayer(event.getPlayer());
    }

}
