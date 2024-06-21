package org.szucraft.buildandguess.event;

import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.entity.Player;
import org.bukkit.event.*;
import org.bukkit.event.player.PlayerMoveEvent;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.KeeperPlayer;

public class TransferToBuilderEventCaller implements Listener {

    @EventHandler(ignoreCancelled = true)
    public void onPlayerMove(PlayerMoveEvent event) {
        Player player = event.getPlayer();
        Material material = player.getLocation().getBlock().getType();
        Bukkit.getPluginManager().callEvent(new TransferToBuilderEvent(player, material));
        if (BuildAndGuessGame.isRunning && BuildAndGuessGame.stage == 0) {
            event.setCancelled(true);
        }
    }

    @EventHandler
    public void OnPlayerTransferBuilder(TransferToBuilderEvent event) {
        Player player = event.getPlayer();
        Material material = event.getMaterial();
        if (!BuildAndGuessGame.isRunning && !KeeperPlayer.isKeeperPlayer(player)) {
            if (material.equals(BuildAndGuessGame.signBlocks.getFirst())) {
                if (!BuilderPlayer.isBuilderPlayer(player)) {
                    new BuilderPlayer(player, null, null);
                }
            } else {
                BuilderPlayer.removeBuilderPlayer(player);
            }
        } else if (KeeperPlayer.isKeeperPlayer(player)) {
            BuilderPlayer.removeBuilderPlayer(player);
        }
    }

}
