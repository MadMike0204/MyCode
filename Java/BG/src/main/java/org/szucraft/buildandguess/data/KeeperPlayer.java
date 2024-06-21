package org.szucraft.buildandguess.data;

import org.bukkit.entity.Player;

import java.util.HashMap;
import java.util.UUID;

public class KeeperPlayer {

    public static HashMap<UUID, KeeperPlayer> KeeperMap = new HashMap<>();

    public KeeperPlayer(Player player) {
        KeeperMap.put(player.getUniqueId(), this);
    }

    public static void removeBuilderPlayer(Player player) {
        if (!KeeperPlayer.isKeeperPlayer(player))
            return;;
        KeeperMap.remove(player.getUniqueId());
    }

    public static boolean isKeeperPlayer(Player player) {
        return KeeperMap.get(player.getUniqueId()) != null;
    }
}
