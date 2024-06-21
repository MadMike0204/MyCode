package org.szucraft.buildandguess.util;

import org.bukkit.scheduler.BukkitRunnable;
import org.bukkit.scheduler.BukkitTask;
import org.szucraft.buildandguess.BuildAndGuess;
import org.szucraft.buildandguess.BuildAndGuessGame;

public class TimerHelper {

    public BukkitTask task = null;
    private final BuildAndGuess plugin;

    public TimerHelper(BuildAndGuess plugin) {
        this.plugin = plugin;
        run();
    }

    public void run() {
        this.task = new BukkitRunnable() {
            @Override
            public void run() {
                BuildAndGuessGame.serverTick += 1;
            }
        }.runTaskTimer(this.plugin, 20L, 1L);
    }

    public void stop() {
        if (!this.task.isCancelled())
            this.task.cancel();
        this.task = null;
    }

}
