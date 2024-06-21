package org.szucraft.szuapi;

import org.bukkit.Bukkit;
import org.bukkit.Server;
import org.bukkit.command.CommandSender;
import org.bukkit.command.ConsoleCommandSender;
import org.bukkit.configuration.InvalidConfigurationException;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.bukkit.event.EventHandler;
import org.bukkit.event.EventPriority;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Objects;

public class CounterAPI extends JavaPlugin implements Listener {

    public FileConfiguration Config = new YamlConfiguration();
    private List<String> players = new ArrayList<>();
    private List<String> counters = new ArrayList<>();
    private List<String> timers = new ArrayList<>();
    private List<String> clocks = new ArrayList<>();
    private int totalCounters = 0;
    private int totalTimers = 0;
    private int totalClocks = 0;
    private static CounterAPI instance;
    private final HashMap<String, List<Integer>> playerMap = new HashMap<>();
    public HashMap<String, Integer> counterMap = new HashMap<>();
    public HashMap<String, Integer> timerMap = new HashMap<>();
    public HashMap<String, Integer> clockMap = new HashMap<>();
    private File file = null;
    private final ConsoleCommandSender sender = null;
    private final List<Integer> zeros = new ArrayList<>();

    @Override
    public void onEnable() {
        if (Bukkit.getPluginManager().getPlugin("PlaceholderAPI") != null) {
            Bukkit.getPluginManager().registerEvents(this, this);
            new CounterExpansion(this).register();
            instance = this;
            this.saveDefaultConfig();
            file = new File(getDataFolder(), "config.yml");
            try {
                Config.load(file);
            } catch (IOException | InvalidConfigurationException e) {
                e.printStackTrace();
            }
            Bukkit.getPluginManager().registerEvents(this, this);
            if (Bukkit.getPluginCommand("counter") != null) {
                Objects.requireNonNull(Bukkit.getPluginCommand("counter")).setExecutor(new CommandUtil());
            }
            readData();
            totalCounters = counters.size();
            totalTimers = timers.size();
            totalClocks = clocks.size();
            for (int i = 0; i < totalCounters; i++) {
                zeros.add(0);
            }
            ConsoleCommandSender sender = this.getServer().getConsoleSender();
            getLogger().info("SZUAPI loaded.");
        } else {
            getLogger().warning("Could not find PlaceholderAPI! This plugin is required.");
            Bukkit.getPluginManager().disablePlugin(this);
        }
    }

    @EventHandler(priority = EventPriority.HIGHEST)
    public void onJoin(PlayerJoinEvent event) {
        String player = event.getPlayer().getName();
        if (!players.contains(player)) {
            players.add(player);
            saveNewPlayerData(player);
        }
    }

    public void readData() {
        players = Config.getStringList("players");
        for (String name : players) {
            List<Integer> data = Config.getIntegerList(name);
            playerMap.put(name, data);
        }
        counters = Config.getStringList("counters");
        int i = 0;
        for (String name : counters) {
            counterMap.put(name, i);
            i ++;
        }
        timers = Config.getStringList("timers");
        i = 0;
        for (String name : timers) {
            timerMap.put(name, i);
            i ++;
        }
        clocks = Config.getStringList("clocks");
        i = 0;
        for (String name : clocks) {
            clockMap.put(name, i);
            i ++;
        }
    }

    public void saveNewPlayerData(String name) {
        Config.set("players", players);
        Config.createSection(name);
        List<Integer> zeros = new ArrayList<>();
        for (int i = 0; i < totalCounters; i++) {
            zeros.add(0);
        }
        Config.set(name, zeros);
        try {
            Config.save(file);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveNewCounterData(String name) {
        Config.set("counters", counters);
        players = Config.getStringList("players");
        for (String player : players) {
            List<Integer> values = Config.getIntegerList(player);
            values.add(0);
            Config.set(player, values);
        }
        try {
            Config.save(file);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveNewTimerData(String name) {
        Config.set("timers", timers);
        try {
            Config.save(file);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveNewClockData(String name) {
        Config.set("clocks", clocks);
        try {
            Config.save(file);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public boolean updateData(String player, String counter, int value, boolean add) {
        if (players.contains(player) && counters.contains(counter)) {
            List<Integer> values = Config.getIntegerList(player);
            if (add) {
                value += values.get(counterMap.get(counter));
            }
            values.set(counterMap.get(counter), value);
            Config.set(player, values);
            try {
                Config.save(file);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return true;
        }
        return false;
    }

    public static boolean updateDataAdd(String player, String counter, int value) {
        boolean add = true;
        return instance.updateData(player, counter, value, add);
    }

    public static boolean updateDataSet(String player, String counter, int value) {
        boolean add = false;
        return instance.updateData(player, counter, value, add);
    }

    public void resetData() {
        for (String player : players) {
            Config.set(player, zeros);
        }
        try {
            Config.save(file);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void resetData(String player) {
        if (players.contains(player)) {
            Config.set(player, zeros);
            try {
                Config.save(file);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void resetCounterData(String counter) {
        if (counters.contains(counter)) {
            int num = counterMap.get(counter);
            for (String player : players) {
                List<Integer> temp = Config.getIntegerList(player);
                temp.set(num, 0);
                Config.set(player, temp);
            }
            try {
                Config.save(file);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void reset() {
        instance.resetData();
    }

    public static void reset(String player) {
        instance.resetData(player);
    }

    public static void resetCounter(String counter) {
        instance.resetCounterData(counter);
    }

    public boolean _createCounter(String name) {
        if (counters.contains(name)) {
            return false;
        } else {
            counters.add(name);
            counterMap.put(name, totalCounters);
            totalCounters ++;
            zeros.add(0);
            saveNewCounterData(name);
            return true;
        }
    }

    public boolean _createTimer(String name, int cooldown) {
        if (timers.contains(name)) {
            return false;
        } else {
            timers.add(name);
            timerMap.put(name, totalTimers);
            totalTimers ++;
            saveNewTimerData(name);
            return true;
        }
    }

    public boolean _createClock(String name, int time) {
        if (clocks.contains(name)) {
            return false;
        } else {
            clocks.add(name);
            counterMap.put(name, totalClocks);
            totalClocks ++;
            saveNewClockData(name);
            return true;
        }
    }

    public static boolean createCounter(String name) {
        return instance._createCounter(name);
    }

    public static boolean createTimer(String name, int cooldown) {
        return instance._createTimer(name, cooldown);
    }

    public static boolean createClock(String name, int time) {
        return instance._createClock(name, time);
    }


}