package org.szucraft.buildandguess.command;

import net.minecraft.server.v1_16_R3.PlayerList;
import org.bukkit.Bukkit;
import org.bukkit.OfflinePlayer;
import org.bukkit.command.CommandSender;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.KeeperPlayer;

import java.util.Objects;
import java.util.UUID;

public class CommandList {

    public CommandList(CommandSender sender) {
        StringBuilder msg = new StringBuilder("Builders:\n");
        for (UUID uuid : BuilderPlayer.BuilderMap.keySet()) {
            msg.append(Objects.requireNonNull(Bukkit.getPlayer(uuid)).getName()).append(" ");
        }
        msg.append("\n").append("Keepers:\n");
        for (UUID uuid : KeeperPlayer.KeeperMap.keySet()) {
            msg.append(Objects.requireNonNull(Bukkit.getPlayer(uuid)).getName()).append(" ");
        }
        sender.sendMessage(String.valueOf(msg));
    }
}
