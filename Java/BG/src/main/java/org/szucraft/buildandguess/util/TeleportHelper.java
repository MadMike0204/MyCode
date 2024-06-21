package org.szucraft.buildandguess.util;

import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.scheduler.BukkitRunnable;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;
import org.szucraft.buildandguess.data.BuildArea;
import org.szucraft.buildandguess.data.BuilderPlayer;

import java.util.Random;
import java.util.UUID;

public class TeleportHelper {

    public static void separate() {
        int x = 1;
        Random random = new Random();
        int z = random.nextInt(10000);
        for (Player player : BuildAndGuessGame.builderPlayers) {
            BuilderPlayer.BuilderMap.get(player.getUniqueId()).setBuildArea(new BuildArea(x, x + ChunkCloneHelper.sizeX, z, z + ChunkCloneHelper.sizeZ, ChunkCloneHelper.minY, ChunkCloneHelper.maxY));
            BuilderPlayer.teleportToArea(player);
            int finalX = x;
            new BukkitRunnable() {
                @Override
                public void run() {
                    ChunkCloneHelper.areaClone(finalX, z);
                }
            }.runTaskLater(BuildAndGuess.instance, 100L);
            x = x + ChunkCloneHelper.sizeX + 5;
        }
    }

    public static void teleportALL(Player builder) {
        Location location = ChunkHelper.getCenterLowY(builder.getWorld(), BuilderPlayer.BuilderMap.get(builder.getUniqueId()).getBuildArea());
        for (Player player : Bukkit.getOnlinePlayers()) {
            player.teleport(location);
        }
    }

}
