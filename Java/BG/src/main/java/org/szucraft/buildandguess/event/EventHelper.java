package org.szucraft.buildandguess.event;

import org.bukkit.Bukkit;
import org.bukkit.plugin.PluginManager;
import org.szucraft.buildandguess.BuildAndGuess;

public class EventHelper {
    public EventHelper(BuildAndGuess plugin) {
        PluginManager manager = Bukkit.getPluginManager();
        manager.registerEvents(new TransferToBuilderEventCaller(), plugin);
        manager.registerEvents(new BuilderTransborderHandler(), plugin);
        manager.registerEvents(new KeeperCreateAreaEvent(), plugin);
        manager.registerEvents(new BuildAreaProtectEvent(), plugin);
        manager.registerEvents(new PlayerGuessEvent(), plugin);
    }

}
