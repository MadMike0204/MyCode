package org.szucraft.buildandguess.event;

import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.entity.Player;
import org.bukkit.event.Cancellable;
import org.bukkit.event.Event;
import org.bukkit.event.HandlerList;

public class TransferToBuilderEvent extends Event implements Cancellable {
    private static final HandlerList HANDLERS = new HandlerList();
    private boolean isCancelled;

    private Player player;
    private Material material;

    public Player getPlayer() {
        return player;
    }

    public Material getMaterial() {
        return material;
    }

    public static HandlerList getHandlerList() {
        return HANDLERS;
    }

    public TransferToBuilderEvent(Player player, Material material) {
        this.player = player;
        this.material = material;
    }

    @Override
    public HandlerList getHandlers() {
        return HANDLERS;
    }

    @Override
    public boolean isCancelled() {
        return this.isCancelled;
    }

    @Override
    public void setCancelled(boolean isCancelled) {
        this.isCancelled = isCancelled;
    }
}
