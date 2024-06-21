package org.szucraft.buildandguess.event;

import com.mojang.datafixers.util.Pair;
import org.bukkit.Material;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerInteractEvent;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.KeeperPlayer;

import java.util.Objects;

public class KeeperCreateAreaEvent implements Listener {

    @EventHandler
    public void onKeeperSetPos(PlayerInteractEvent event) {
        Player player = event.getPlayer();
        if (KeeperPlayer.isKeeperPlayer(player)) {
            if (event.getMaterial().equals(Material.WOODEN_HOE)) {
                switch (event.getAction()) {
                    case LEFT_CLICK_BLOCK -> {
                        BuildAndGuessGame.areaOrigin = new Pair<>(Objects.requireNonNull(event.getClickedBlock()).getLocation(), BuildAndGuessGame.areaOrigin.getSecond());
                        player.sendMessage("Pos 1 of Clone Area set");
                        event.setCancelled(true);
                    }
                    case RIGHT_CLICK_BLOCK -> {
                        BuildAndGuessGame.areaOrigin = new Pair<>(BuildAndGuessGame.areaOrigin.getFirst(), Objects.requireNonNull(event.getClickedBlock()).getLocation());
                        player.sendMessage("Pos 2 of Clone Area set");
                        event.setCancelled(true);
                    }
                }

            }
        }
    }

}
