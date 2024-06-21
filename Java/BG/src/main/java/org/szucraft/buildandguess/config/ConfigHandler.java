package org.szucraft.buildandguess.config;

import org.bukkit.configuration.InvalidConfigurationException;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;

import java.io.File;
import java.io.IOException;

public class ConfigHandler {

    private final FileConfiguration Config = new YamlConfiguration();
    private final BuildAndGuess plugin;
    public ConfigHandler(BuildAndGuess plugin) {
        this.plugin = plugin;
        init();
    }

    public void init() {
        this.plugin.saveDefaultConfig();
        File file = new File(this.plugin.getDataFolder(), "config.yml");
        try {
            Config.load(file);
        } catch (IOException | InvalidConfigurationException e) {
            e.printStackTrace();
        }
        BuildAndGuessGame.words = Config.getStringList("words");
    }

}
