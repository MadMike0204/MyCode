package org.szucraft.buildandguess.data;

import org.bukkit.entity.Player;
import org.szucraft.buildandguess.util.ChunkHelper;

import java.util.HashMap;
import java.util.UUID;

public class BuilderPlayer {

    public static HashMap<UUID, BuilderPlayer> BuilderMap = new HashMap<>();

    private BuildArea buildArea;
    private String word;

    public BuildArea getBuildArea() {
        return buildArea;
    }

    public String getWord() {
        return word;
    }

    public void setBuildArea(BuildArea buildArea) {
        this.buildArea = buildArea;
    }

    public void setWord(String word) {
        this.word = word;
    }

    public BuilderPlayer(Player player, BuildArea buildArea, String word) {
        this.buildArea = buildArea;
        this.word = word;
        BuilderMap.put(player.getUniqueId(), this);
    }

    public static void removeBuilderPlayer(Player player) {
        if (BuilderMap.get(player.getUniqueId()) == null)
            return;
        BuilderMap.get(player.getUniqueId()).buildArea = null;
        BuilderMap.remove(player.getUniqueId());
    }

    public static boolean isBuilderPlayer(Player player) {
        return BuilderMap.get(player.getUniqueId()) != null;
    }

    public static void checkTransborder(Player player) {
        if (!isBuilderPlayer(player))
            return;
        BuilderPlayer builderPlayer = BuilderMap.get(player.getUniqueId());
        BuildArea buildArea = builderPlayer.getBuildArea();
        if(ChunkHelper.isTransborder(player.getLocation(), buildArea) ) {
            player.teleport(ChunkHelper.getCenterLowY(player.getWorld(), buildArea));
        }
    }

    public static void teleportToArea(Player player) {
        if (!isBuilderPlayer(player))
            return;
        BuilderPlayer builderPlayer = BuilderMap.get(player.getUniqueId());
        BuildArea buildArea = builderPlayer.getBuildArea();
        if (buildArea != null)
            player.teleport(ChunkHelper.getCenterLowY(player.getWorld(), buildArea));
    }

}
