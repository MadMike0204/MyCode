package org.szucraft.buildandguess.event;

import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockBreakEvent;
import org.bukkit.event.block.BlockPlaceEvent;
import org.bukkit.event.player.PlayerInteractEvent;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.KeeperPlayer;
import org.szucraft.buildandguess.util.ChunkHelper;

public class BuildAreaProtectEvent implements Listener {

    @EventHandler
    public void OnPlayerBreakBlock(BlockBreakEvent event) {
        if (!event.isCancelled()) {
            Player player = event.getPlayer();
            Location location = event.getBlock().getLocation();
            if (KeeperPlayer.isKeeperPlayer(player))
                return;
            if (BuilderPlayer.isBuilderPlayer(player) && ChunkHelper.isTransborder(location, BuilderPlayer.BuilderMap.get(player.getUniqueId()).getBuildArea()))
                return;
            event.setCancelled(true);
        }
    }

    @EventHandler
    public void OnPlayerBuildBlock(BlockPlaceEvent event) {
        if (!event.isCancelled()) {
            Player player = event.getPlayer();
            Location location = event.getBlock().getLocation();
            if (KeeperPlayer.isKeeperPlayer(player))
                return;
            if (BuilderPlayer.isBuilderPlayer(player) && ChunkHelper.isTransborder(location, BuilderPlayer.BuilderMap.get(player.getUniqueId()).getBuildArea()))
                return;
            event.setCancelled(true);
        }
    }

    @EventHandler
    public void OnPlayerUseEgg(PlayerInteractEvent event) {
        if(event.hasItem()) {
            if (event.getMaterial().toString().endsWith("EGG")) {
                event.setCancelled(true);
                event.getPlayer().sendMessage("You have no permission to use this item!");
            }
        }
    }

}
