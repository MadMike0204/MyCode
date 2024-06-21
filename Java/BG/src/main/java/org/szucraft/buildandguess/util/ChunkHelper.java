package org.szucraft.buildandguess.util;

import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.World;
import org.szucraft.buildandguess.data.BuildArea;

import static java.lang.Math.*;

public class ChunkHelper {

    public static Location getCenter(World world, BuildArea buildArea) {
        if (buildArea == null)
            return null;
        return new Location(world, (buildArea.minChunkX() + buildArea.maxChunkX()) << 3, (buildArea.minY() + buildArea.maxY()) >> 1, (buildArea.minChunkZ() + buildArea.maxChunkZ()) << 3);
    }

    public static Location getCenterLowY(World world, BuildArea buildArea) {
        if (buildArea == null)
            return null;
        int x = (buildArea.minChunkX() + buildArea.maxChunkX()) << 3;
        int z = (buildArea.minChunkZ() + buildArea.maxChunkZ()) << 3;
        int i;
        for (i = 0; i < buildArea.maxY() - buildArea.minY(); i++) {
            if (new Location(world, x, buildArea.minY() + i, z).getBlock().getType() != Material.AIR)
                break;
        }
        return new Location(world, x, max(min((buildArea.minY() + i), buildArea.maxY() - 1), buildArea.minY() + 1), z);
    }

    public static boolean isTransborder(Location location, BuildArea buildArea) {
        if (buildArea == null)
            return false;
        int x = location.getBlockX() >> 4;
        int y = location.getBlockY();
        int z = location.getBlockZ() >> 4;
        if (y < buildArea.minY() || y >= buildArea.maxY())
            return true;
        if (x < buildArea.minChunkX() || x >= buildArea.maxChunkX())
            return true;
        if (z < buildArea.minChunkZ() || z >= buildArea.maxChunkZ())
            return true;
        return false;
    }
}
