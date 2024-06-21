package org.szucraft.buildandguess.util;

import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class ChunkCloneHelper {

    public static int minX, maxX, minY, maxY, minZ, maxZ, sizeX, sizeZ;

    public static void updateToChunkSize() {
        minX = BuildAndGuessGame.areaOrigin.getFirst().getBlockX();
        maxX = BuildAndGuessGame.areaOrigin.getSecond().getBlockX();
        minY = BuildAndGuessGame.areaOrigin.getFirst().getBlockY();
        maxY = BuildAndGuessGame.areaOrigin.getSecond().getBlockY();
        minZ = BuildAndGuessGame.areaOrigin.getFirst().getBlockZ();
        maxZ = BuildAndGuessGame.areaOrigin.getSecond().getBlockZ();
        if (minX > maxX) {
            int tmp = minX;
            minX = maxX;
            maxX = tmp;
        }
        if (minY > maxY) {
            int tmp = minY;
            minY = maxY;
            maxY = tmp;
        }
        if (minZ > maxZ) {
            int tmp = minZ;
            minZ = maxZ;
            maxZ = tmp;
        }
        if ((maxX - minX + 1) % 16 != 0) {
            int a = ((maxX - minX + 1) % 16) / 2;
            int b = ((maxX - minX + 1) % 16) - a;
            minX += a;
            maxX -= b;
        }
        if ((maxZ - minZ + 1) % 16 != 0) {
            int a = ((maxZ - minZ + 1) % 16) / 2;
            int b = ((maxZ - minZ+ 1) % 16) - a;
            minZ += a;
            maxZ -= b;
        }
        sizeX = (maxX - minX) / 16;
        sizeZ = (maxZ - minZ) / 16;
    }

    public static void areaClone(int chunkX, int chunkZ) {
        int x = (chunkX * 16 - 2);
        int z = (chunkZ * 16 - 2);
        BuildAndGuess.instance.getServer().dispatchCommand(BuildAndGuess.instance.getServer().getConsoleSender(), String.format("clone %d %d %d %d %d %d %d %d %d", minX - 4, max(minY - 4 , - 64), minZ - 4, maxX + 4, min(maxY, 255), maxZ + 4, x - 4, max(minY - 4 , - 64) ,z - 4));
    }

    public static boolean isAreaValid() {
        if (BuildAndGuessGame.areaOrigin.getFirst() == null || BuildAndGuessGame.areaOrigin.getSecond() == null)
            return false;
        updateToChunkSize();
        return maxX - minX >= 15 && maxZ - minZ >= 15 && maxY - minY >= 15;
    }

}
