package org.szucraft.buildandguess.util;

import org.bukkit.boss.BarColor;
import org.szucraft.buildandguess.BuildAndGuessGame;

public class BossbarCountDownHelper {

    public static void update() {
        if (BuildAndGuessGame.totalTime <= 0) {
            BuildAndGuessGame.bossBar.setProgress(1.0);
            BuildAndGuessGame.bossBar.setTitle("Build & Guess Game");
            BuildAndGuessGame.bossBar.setColor(BarColor.PINK);
            return;
        }

        double rate = (double) BuildAndGuessGame.timeLeft / BuildAndGuessGame.totalTime;
        BuildAndGuessGame.bossBar.setProgress(rate);
        if (rate > 0.5) {
            BuildAndGuessGame.bossBar.setColor(BarColor.GREEN);
        } else if (rate > 0.2) {
            BuildAndGuessGame.bossBar.setColor(BarColor.YELLOW);
        } else {
            BuildAndGuessGame.bossBar.setColor(BarColor.RED);
        }

        switch (BuildAndGuessGame.stage) {
            case 0 -> BuildAndGuessGame.bossBar.setTitle(String.format("Game loading, starting in: %ds", BuildAndGuessGame.timeLeft));
            case 1 -> BuildAndGuessGame.bossBar.setTitle(String.format("Build time left: %ds", BuildAndGuessGame.timeLeft));
            case 2 -> BuildAndGuessGame.bossBar.setTitle(String.format("Guess time left: %ds", BuildAndGuessGame.timeLeft));
        }

    }


}
