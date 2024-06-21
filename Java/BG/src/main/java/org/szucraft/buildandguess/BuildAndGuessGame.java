package org.szucraft.buildandguess;

import com.mojang.datafixers.util.Pair;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.boss.BarColor;
import org.bukkit.boss.BarStyle;
import org.bukkit.boss.BossBar;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.scheduler.BukkitRunnable;
import org.bukkit.scheduler.BukkitTask;
import org.szucraft.buildandguess.data.BuilderPlayer;
import org.szucraft.buildandguess.data.WordReader;
import org.szucraft.buildandguess.util.BossbarCountDownHelper;
import org.szucraft.buildandguess.util.ChunkCloneHelper;
import org.szucraft.buildandguess.util.TeleportHelper;
import org.szucraft.buildandguess.util.TitleHelper;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

public class BuildAndGuessGame {

    public static Pair<Material, Material> signBlocks = new Pair<>(Material.ORANGE_CARPET, Material.BLUE_CARPET);
    public static boolean isRunning = false;
    public static long serverTick = 0;
    public static BuildAndGuessGame game;
    public static Pair<Location, Location> areaOrigin = new Pair<>(null, null);
    public static String currentWord = null;
    public static String currentTips = null;
    public static HashMap<Player, Integer> leaderBoard = new HashMap<>();
    public static HashMap<Player, Integer> currentStatus = new HashMap<>();
    // -1:correct, 0+:time
    public static int currentCorrect;
    public static BossBar bossBar;
    public static int maxTime = 3;
    public static int stage = 0;
    public static int timeLeft = 0;
    public static int totalTime = 0;
    public static List<String> words = new ArrayList<>();
    public static List<Player> builderPlayers = new ArrayList<>();
    public static BukkitTask task = null;
    public static int playerCountDown;
    public static BuilderPlayer curerentBuilder;
    private final BuildAndGuess plugin;

    public BuildAndGuessGame(BuildAndGuess plugin) {
        this.plugin = plugin;
        game = this;
        bossBar = Bukkit.createBossBar("Build & Guess Game", BarColor.PINK, BarStyle.SEGMENTED_20);
        BuildAndGuess.instance.getLogger().info("BossBar Created");
        bossBar.setVisible(true);
    }

    public static void run(CommandSender sender) {
        if (areaOrigin.getFirst() == null || areaOrigin.getSecond() == null) {
            sender.sendMessage("No area defined!");
            return;
        }
        if (isRunning) {
            sender.sendMessage("Already running!");
            return;
        }
        if (!ChunkCloneHelper.isAreaValid()) {
            sender.sendMessage("Build area is too small!");
            return;
        }
        for (UUID uuid : BuilderPlayer.BuilderMap.keySet())
            builderPlayers.add(Bukkit.getPlayer(uuid));
        playerCountDown = builderPlayers.size();
        if (playerCountDown == 0) {
            sender.sendMessage("No builders!");
            return;
        }
        List<String> gameWords = WordReader.getRandomWords(playerCountDown);
        if (gameWords == null){
            sender.sendMessage("Not enough words for so much players!");
            return;
        }
        isRunning = true;
        totalTime = 10;
        timeLeft = totalTime;
        int i = 0;
        for (Player player : builderPlayers) {
            currentStatus.put(player, 0);
            leaderBoard.put(player, 0);
            BuilderPlayer.BuilderMap.get(player.getUniqueId()).setWord(gameWords.get(i));
            i ++;
        }
        TeleportHelper.separate();
        BossbarCountDownHelper.update();
        task = new BukkitRunnable() {
            @Override
            public void run() {
                if (timeLeft <= 0 && stage == 0) {
                    for (Player player : builderPlayers)
                        TitleHelper.sendTitle(player);
                    totalTime = 120;
                    stage = 1;
                    timeLeft = totalTime;
                } else if (timeLeft <= 0 && stage == 1) {
                    curerentBuilder = BuilderPlayer.BuilderMap.get(builderPlayers.get(playerCountDown-1).getUniqueId());
                    currentWord = curerentBuilder.getWord();
                    TeleportHelper.teleportALL(builderPlayers.get(playerCountDown-1));
                    TitleHelper.sendTitleAll(builderPlayers.get(playerCountDown-1));
                    playerCountDown--;
                    totalTime = 30;
                    stage = 2;
                    timeLeft = totalTime;
                } else if (timeLeft <= 0 && stage == 2 && playerCountDown > 0) {
                    curerentBuilder = BuilderPlayer.BuilderMap.get(builderPlayers.get(playerCountDown-1).getUniqueId());
                    currentWord = curerentBuilder.getWord();
                    TeleportHelper.teleportALL(builderPlayers.get(playerCountDown-1));
                    TitleHelper.sendTitleAll(builderPlayers.get(playerCountDown-1));
                    for (Player player : builderPlayers)
                        currentStatus.put(player, 0);
                    playerCountDown--;
                    totalTime = 30;
                    timeLeft = totalTime;
                } else if (timeLeft <= 0 && stage == 2) {
                    stop(null);
                } else {
                    timeLeft--;
                }
                BossbarCountDownHelper.update();
            }
        }.runTaskTimer(BuildAndGuess.instance, 0, 20L);
    }

    public static void stop(CommandSender sender) {
        if (!isRunning)
            return;
        task.cancel();
        task = null;
        stage = 0;
        BossbarCountDownHelper.update();
        isRunning = false;
        TitleHelper.broadcast();
        currentWord = null;
        currentTips = null;
        leaderBoard = new HashMap<>();
        currentStatus = new HashMap<>();
        currentCorrect = 0;
        timeLeft = 0;
        totalTime = 0;
        builderPlayers = new ArrayList<>();
        if (sender != null) {
            sender.sendMessage("Stop successfully!");
        }
    }

}
