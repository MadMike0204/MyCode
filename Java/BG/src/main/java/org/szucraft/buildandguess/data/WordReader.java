package org.szucraft.buildandguess.data;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import static org.szucraft.buildandguess.BuildAndGuessGame.words;

public class WordReader {

    public static List<String> getRandomWords(int n) {
        List<String> randomWords = new ArrayList<>();
        Random random = new Random();

        if (n >= words.size()) {
            return null;
        }

        List<String> copy = new ArrayList<>(words);
        for (int i = 0; i < n; i++) {
            int index = random.nextInt(copy.size());
            randomWords.add(copy.get(index));
            copy.remove(index);
        }
        return randomWords;
    }

}
