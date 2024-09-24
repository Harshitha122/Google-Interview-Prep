private final static int[] movesX = new int[]{1, -1, 0, 0};
private final static int[] movesY = new int[]{0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        max = Math.max(max, findGold(grid, movesX[i] + row, movesY[i] + col));
    }