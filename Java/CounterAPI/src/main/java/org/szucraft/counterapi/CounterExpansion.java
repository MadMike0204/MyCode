package org.szucraft.counterapi;

import me.clip.placeholderapi.expansion.PlaceholderExpansion;
import org.bukkit.OfflinePlayer;
import org.szucraft.counterapi.CounterAPI;

public class CounterExpansion extends PlaceholderExpansion {
    private final CounterAPI plugin;

    public CounterExpansion(CounterAPI plugin) {
        this.plugin = plugin;
    }

    @Override
    public String getAuthor() {
        return "szucraft";
    }

    @Override
    public String getIdentifier() {
        return "counterapi";
    }

    @Override
    public String getVersion() {
        return "1.0.0";
    }

    @Override
    public boolean persist() {
        return true; // This is required or else PlaceholderAPI will unregister the Expansion on reload
    }

    @Override
    public String onRequest(OfflinePlayer player, String params) {
        String name = player.getName();
        if (name != null && params != null && plugin.counterMap.get(params) != null) {
            return plugin.Config.getStringList(name).get(plugin.counterMap.get(params));
        }
        return null; // Placeholder is unknown by the Expansion
    }
}
