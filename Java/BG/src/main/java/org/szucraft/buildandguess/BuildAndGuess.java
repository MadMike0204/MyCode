package org.szucraft.buildandguess;

import com.mojang.datafixers.util.Pair;
import net.minecraft.server.v1_16_R3.Block;
import org.bukkit.Bukkit;
import org.bukkit.boss.BarColor;
import org.bukkit.boss.BarStyle;
import org.bukkit.boss.BossBar;
import org.bukkit.event.EventHandler;
import org.bukkit.event.EventPriority;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockBreakEvent;
import org.bukkit.plugin.PluginManager;
import org.bukkit.plugin.java.JavaPlugin;
import org.szucraft.buildandguess.command.CommandHandler;
import org.szucraft.buildandguess.compat.PlaceHolderHandler;
import org.szucraft.buildandguess.config.ConfigHandler;
import org.szucraft.buildandguess.event.EventHelper;
import org.szucraft.buildandguess.util.TimerHelper;

import java.util.logging.Logger;

public class BuildAndGuess extends JavaPlugin {
    public static BuildAndGuess instance;
    private static Logger logger = null;
    private static PlaceHolderHandler placeHolderHandler = null;
    public static ConfigHandler configHandler = null;
    private static CommandHandler commandHandler = null;
    private static TimerHelper timerHelper = null;
    private static EventHelper eventHelper = null;
    private static BuildAndGuessGame game = null;

    @Override
    public void onEnable() {
        logger = this.getLogger();
        if (!init()) {
            logger.warning("Could not find PlaceholderAPI! This plugin is required.");
            Bukkit.getPluginManager().disablePlugin(this);
            return;
        }
        logger.info("Build And Guess loaded! Enjoy it!");
    }

    private boolean init() {
        PluginManager manager = Bukkit.getPluginManager();
        if (manager.getPlugin("PlaceholderAPI") != null) {
            instance = this;
            game = new BuildAndGuessGame(this);
            placeHolderHandler = new PlaceHolderHandler(this);
            placeHolderHandler.register();
            configHandler = new ConfigHandler(this);
            commandHandler = new CommandHandler(this);
            timerHelper = new TimerHelper(this);
            eventHelper = new EventHelper(this);
            return true;
        }
        return false;
    }

}