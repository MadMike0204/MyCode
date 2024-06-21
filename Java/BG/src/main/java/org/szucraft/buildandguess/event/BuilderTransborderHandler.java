package org.szucraft.buildandguess.event;

import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.EventPriority;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerMoveEvent;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuilderPlayer;

public class BuilderTransborderHandler implements Listener {

    @EventHandler(priority = EventPriority.LOW)
    public void OnPlayerMove(PlayerMoveEvent event) {
        BuilderPlayer.checkTransborder(event.getPlayer());
    }

}
