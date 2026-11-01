#include <raylib.h>
#include <cmath>
#include <vector>

int lvl1[16][16] = {
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 0, 0, 2, 3, 0, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 3, 3, 0, 0, 0, 0, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 2, 0, 1, 1, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 1, 1, 2, 0, 0, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 0, 1, 0, 0, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};
int lvl2[16][16] = {
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 0, 2, 0, 2, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 3, 0, 1, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 3, 0, 0, 1, 1, 0, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 1, 3, 1, 1, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 0, 2, 0, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 0, 0, 1, 0, 0, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};
int lvl3[16][16] = {
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 1, 1, 1, 0, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 2, 0, 0, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 0, 0, 2, 1, 1, 0, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 1, 1, 3, 2, 3, 3, 0, 3, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 0, 2, 1, 0, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 0, 0, 1, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 0, 0, 1, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};
int lvl4[16][16] = {
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 0, 3, 0, 3, 0, 3, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 0, 2, 0, 2, 0, 2, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 0, 0, 0, 0, 2, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 0, 2, 0, 0, 0, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 2, 0, 2, 0, 2, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 0, 3, 0, 3, 0, 3, 0, 0, 1, 5, 5, 5},
    {5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};
int lvl5[16][16] = {
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 1, 0, 0, 0, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5},
    {5, 5, 1, 2, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 5, 5},
    {5, 5, 1, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 1, 5, 5},
    {5, 5, 1, 2, 1, 1, 1, 1, 3, 1, 1, 0, 0, 1, 5, 5},
    {5, 1, 1, 0, 1, 0, 3, 3, 3, 0, 1, 0, 1, 1, 1, 5},
    {5, 1, 0, 2, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 5},
    {5, 1, 0, 1, 1, 2, 1, 5, 1, 0, 1, 0, 0, 0, 1, 5},
    {5, 1, 0, 0, 0, 0, 1, 1, 1, 2, 1, 1, 0, 1, 1, 5},
    {5, 1, 1, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 5},
    {5, 5, 5, 1, 0, 2, 0, 1, 0, 1, 1, 1, 0, 0, 1, 5},
    {5, 5, 5, 1, 0, 1, 0, 0, 0, 1, 5, 1, 2, 0, 1, 5},
    {5, 5, 5, 1, 0, 0, 0, 1, 1, 1, 5, 1, 0, 0, 1, 5},
    {5, 5, 5, 1, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1, 5},
    {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};

struct Player {
    int posX;
    int posY;
    float drawX;
    float drawY;
};
struct Box {
    int posX;
    int posY;
    float drawX;
    float drawY;
};
struct Target {
    int posX;
    int posY;
};

void controlMechanics(Player &pl, int lvl[16][16], int &moveCount, std::vector<Box> &boxes, std::vector<Player> &plHistory, std::vector<Box> &boxHistory, Sound walkSound, Sound pushSound);
void changeLevel(Player &pl, int x, int y, int lvl[16][16], int nextLvl[16][16], int tileSize, std::vector<Box> &boxes, std::vector<Target> &targets, int &moveCount, std::vector<Box> &boxHistory, std::vector<Player> &plHistory);
void resetLevel(Player &pl, int x, int y, int lvl[16][16], int resetLvl[16][16], int tileSize, std::vector<Box> &boxes, int &moveCount, std::vector<Box> &boxHistory, std::vector<Player> &plHistory);
void saveMove(std::vector<Player> &plHistory, Player &pl, std::vector<Box> &boxes, std::vector<Box> &boxHistory);
void undoMove(std::vector<Player> &plHistory, Player &pl, std::vector<Box> &boxes, std::vector<Box> &boxHistory, int &moveCount);

int main() {

    InitWindow(768, 768, "Sokoban");
    InitAudioDevice();
    SetTargetFPS(60);

    Texture2D brickTex = LoadTexture("images/sprite_bricks.png");
    Texture2D grassTex = LoadTexture("images/sprite_grass.png");
    Texture2D playerTex = LoadTexture("images/sprite_player.png");
    Texture2D boxTex = LoadTexture("images/sprite_box.png");
    Texture2D winTex = LoadTexture("images/sprite_win.png");

    Sound resetSound = LoadSound("sounds/sfx-restart.wav");
    Sound undoSound = LoadSound("sounds/sfx-undo.wav");
    Sound walkSound = LoadSound("sounds/sfx-walk.wav");
    Sound pushSound = LoadSound("sounds/sfx-push.wav");

    int tileSize = brickTex.width;
    Player pl = {5, 9, 5.0f * tileSize, 9.0f * tileSize};
    int lvl[16][16] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 1, 0, 0, 0, 3, 0, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 3, 3, 0, 0, 0, 0, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 0, 0, 0, 0, 1, 1, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 1, 1, 1, 0, 0, 0, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 0, 0, 0, 1, 0, 0, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    };
    int currentLevel = 1;
    int moveCount = 0;
    std::vector<Box> boxes;
    std::vector<Target> targets;
    std::vector<Player> plHistory;
    std::vector<Box> boxHistory;

    changeLevel(pl, 5, 10, lvl, lvl1, tileSize, boxes, targets, moveCount, boxHistory, plHistory);

    while (WindowShouldClose() == false) {

        bool lvlWin = false;
        int onTarget = 0;

        for (Box b : boxes) {
            for (Target t : targets) {
                if (b.posX == t.posX && b.posY == t.posY) {
                    onTarget++;
                    if (onTarget == targets.size()) {
                        lvlWin = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }

        if (lvlWin) {
            if (IsKeyPressed(KEY_ENTER)) {
                PlaySound(resetSound);
                currentLevel++;
                switch (currentLevel) {
                    case 2:
                        changeLevel(pl, 5, 10, lvl, lvl2, tileSize, boxes, targets, moveCount, boxHistory, plHistory);
                        break;
                    case 3:
                        changeLevel(pl, 7, 10, lvl, lvl3, tileSize, boxes, targets, moveCount, boxHistory, plHistory);
                        break;
                    case 4:
                        changeLevel(pl, 4, 8, lvl, lvl4, tileSize, boxes, targets, moveCount, boxHistory, plHistory);
                        break;
                    case 5:
                        changeLevel(pl, 7, 12, lvl, lvl5, tileSize, boxes, targets, moveCount, boxHistory, plHistory);
                        break;
                    default:
                        break;
                }
            }
        } else {
            controlMechanics(pl, lvl, moveCount, boxes, plHistory, boxHistory, walkSound, pushSound);
        }

        if (IsKeyPressed(KEY_R)) {
            switch (currentLevel) {
                case 1:
                    resetLevel(pl, 5, 9, lvl, lvl1, tileSize, boxes, moveCount, boxHistory, plHistory);
                    break;
                case 2:
                    resetLevel(pl, 5, 10, lvl, lvl2, tileSize, boxes, moveCount, boxHistory, plHistory);
                    break;
                case 3:
                    resetLevel(pl, 7, 10, lvl, lvl3, tileSize, boxes, moveCount, boxHistory, plHistory);
                    break;
                case 4:
                    resetLevel(pl, 4, 8, lvl, lvl4, tileSize, boxes, moveCount, boxHistory, plHistory);
                    break;
                case 5:
                    resetLevel(pl, 5, 10, lvl, lvl5, tileSize, boxes, moveCount, boxHistory, plHistory);
                    break;
                default:
                    break;
            }
        } else if (IsKeyPressed(KEY_Z)) {
            PlaySound(undoSound);
            undoMove(plHistory, pl, boxes, boxHistory, moveCount);
        }

        pl.drawX += (pl.posX * tileSize - pl.drawX) / 2;
        pl.drawY += (pl.posY * tileSize - pl.drawY) / 2;

        if (abs(pl.drawX - pl.posX * tileSize) < 0.5f) {
            pl.drawX = pl.posX * tileSize;
        }
        if (abs(pl.drawY - pl.posY * tileSize) < 0.5f) {
            pl.drawY = pl.posY * tileSize;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (lvl[i][j] == 1) {
                    DrawTexture(brickTex, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 3) {
                    DrawTexture(winTex, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 0 || lvl[i][j] == 2) {
                    DrawTexture(grassTex, j * tileSize, i * tileSize, WHITE);
                } else {
                    //Prints black.
                }
            }
        }
        DrawTexture(playerTex, pl.drawX, pl.drawY, WHITE);
        for (Box &b : boxes) {
            b.drawX += (b.posX * tileSize - b.drawX) / 2;
            b.drawY += (b.posY * tileSize - b.drawY) / 2;
            if (abs(b.drawX - b.posX * tileSize) < 0.5f) {
                b.drawX = b.posX * tileSize;
            }
            if (abs(b.drawY - b.posY * tileSize) < 0.5f) {
                b.drawY = b.posY * tileSize;
            }
            DrawTexture(boxTex, b.drawX, b.drawY, WHITE);
        }
        DrawText(TextFormat("Moves: %d", moveCount), 0, 750, 20, WHITE);

        if (lvlWin) {
            DrawText("YOU WIN!", 310, 320, 40, GOLD);
            DrawText("Press ENTER to continue!", 260, 380, 20, LIGHTGRAY);
        }

        EndDrawing();
    }

    UnloadTexture(brickTex);
    UnloadTexture(grassTex);
    UnloadTexture(playerTex);
    UnloadTexture(boxTex);
    UnloadTexture(winTex);

    CloseWindow();

    return 0;
}

void controlMechanics(Player &pl, int lvl[16][16], int &moveCount, std::vector<Box> &boxes, std::vector<Player> &plHistory, std::vector<Box> &boxHistory, Sound walkSound, Sound pushSound) {
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            bool boxFound = false;
            for (Box &b : boxes) {
                if (pl.posX + 1 == b.posX && pl.posY == b.posY) {
                    boxFound = true;
                    bool boxBehind = false;
                    for (Box &b : boxes) {
                        if (pl.posX + 2 == b.posX && pl.posY == b.posY) {
                            boxBehind = true;
                            break;
                        }
                    }
                    if (boxBehind == false && (lvl[pl.posY][pl.posX + 2] == 0 || lvl[pl.posY][pl.posX + 2] == 3)) {
                        PlaySound(pushSound);
                        saveMove(plHistory, pl, boxes, boxHistory);
                        pl.posX++;
                        b.posX++;
                        moveCount++;
                        break;
                    }
                }
            }
            if (boxFound == false && (lvl[pl.posY][pl.posX + 1] == 0 || lvl[pl.posY][pl.posX + 1] == 3)) {
                PlaySound(walkSound);
                saveMove(plHistory, pl, boxes, boxHistory);
                pl.posX++;
                moveCount++;
            }
        } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            bool boxFound = false;
            for (Box &b : boxes) {
                if (pl.posX - 1 == b.posX && pl.posY == b.posY) {
                    boxFound = true;
                    bool boxBehind = false;
                    for (Box &b : boxes) {
                        if (pl.posX - 2 == b.posX && pl.posY == b.posY) {
                            boxBehind = true;
                            break;
                        }
                    }
                    if (boxBehind == false && (lvl[pl.posY][pl.posX - 2] == 0 || lvl[pl.posY][pl.posX - 2] == 3)) {
                        PlaySound(pushSound);
                        saveMove(plHistory, pl, boxes, boxHistory);
                        pl.posX--;
                        b.posX--;
                        moveCount++;
                        break;
                    }
                }
            }
            if (boxFound == false && (lvl[pl.posY][pl.posX - 1] == 0 || lvl[pl.posY][pl.posX - 1] == 3)) {
                PlaySound(walkSound);
                saveMove(plHistory, pl, boxes, boxHistory);
                pl.posX--;
                moveCount++;
            }
        } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            bool boxFound = false;
            for (Box &b : boxes) {
                if (pl.posX == b.posX && pl.posY + 1 == b.posY) {
                    boxFound = true;
                    bool boxBehind = false;
                    for (Box &b : boxes) {
                        if (pl.posX == b.posX && pl.posY + 2 == b.posY) {
                            boxBehind = true;
                            break;
                        }
                    }
                    if (boxBehind == false && (lvl[pl.posY + 2][pl.posX] == 0 || lvl[pl.posY + 2][pl.posX] == 3)) {
                        PlaySound(pushSound);
                        saveMove(plHistory, pl, boxes, boxHistory);
                        pl.posY++;
                        b.posY++;
                        moveCount++;
                        break;
                    }
                }
            }
            if (boxFound == false && (lvl[pl.posY + 1][pl.posX] == 0 || lvl[pl.posY + 1][pl.posX] == 3)) {
                PlaySound(walkSound);
                saveMove(plHistory, pl, boxes, boxHistory);
                pl.posY++;
                moveCount++;
            }
        } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            bool boxFound = false;
            for (Box &b : boxes) {
                if (pl.posX == b.posX && pl.posY - 1 == b.posY) {
                    boxFound = true;
                    bool boxBehind = false;
                    for (Box &b : boxes) {
                        if (pl.posX == b.posX && pl.posY - 2 == b.posY) {
                            boxBehind = true;
                            break;
                        }
                    }
                    if (boxBehind == false && (lvl[pl.posY - 2][pl.posX] == 0 || lvl[pl.posY - 2][pl.posX] == 3)) {
                        PlaySound(pushSound);
                        saveMove(plHistory, pl, boxes, boxHistory);
                        pl.posY--;
                        b.posY--;
                        moveCount++;
                        break;
                    }
                }
            }
            if (boxFound == false && (lvl[pl.posY - 1][pl.posX] == 0 || lvl[pl.posY - 1][pl.posX] == 3)) {
                PlaySound(walkSound);
                saveMove(plHistory, pl, boxes, boxHistory);
                pl.posY--;
                moveCount++;
            }
        }
}
void changeLevel(Player &pl, int x, int y, int lvl[16][16], int nextLvl[16][16], int tileSize, std::vector<Box> &boxes, std::vector<Target> &targets, int &moveCount, std::vector<Box> &boxHistory, std::vector<Player> &plHistory) {
    boxes.clear();
    boxHistory.clear();
    plHistory.clear();
    moveCount = 0;
    pl = {x, y, (x * tileSize), (y * tileSize)};
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (nextLvl[i][j] == 2) {
                boxes.push_back({j, i, (float)j * tileSize, (float)i * tileSize});
                lvl[i][j] = 0;
            } else if (nextLvl[i][j] == 3) {
                targets.push_back({j, i});
                lvl[i][j] = 3;
            } else {
                lvl[i][j] = nextLvl[i][j];
            }
        }
    }
}
void resetLevel(Player &pl, int x, int y, int lvl[16][16], int resetLvl[16][16], int tileSize, std::vector<Box> &boxes, int &moveCount, std::vector<Box> &boxHistory, std::vector<Player> &plHistory) {
    boxes.clear();
    boxHistory.clear();
    plHistory.clear();
    moveCount = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (resetLvl[i][j] == 2) {
                boxes.push_back({j, i, (float)j * tileSize, (float)i * tileSize});
                lvl[i][j] = 0;
            } else {
                lvl[i][j] = resetLvl[i][j];
            }
        }
    }
    pl = {x, y, x * tileSize, y * tileSize};
}
void saveMove(std::vector<Player> &plHistory, Player &pl, std::vector<Box> &boxes, std::vector<Box> &boxHistory) {
    plHistory.push_back({pl.posX, pl.posY});
    for (Box &b : boxes) {
        boxHistory.push_back({b.posX, b.posY});
    }
}
void undoMove(std::vector<Player> &plHistory, Player &pl, std::vector<Box> &boxes, std::vector<Box> &boxHistory, int &moveCount) {
    if (plHistory.size() > 0) {
        pl.posX = plHistory[moveCount - 1].posX;
        pl.posY = plHistory[moveCount - 1].posY;
        for (int i = (int)boxes.size() - 1; i >= 0; i--) {
            boxes[i].posX = boxHistory.back().posX;
            boxes[i].posY = boxHistory.back().posY;
            boxHistory.pop_back();
        }
        plHistory.pop_back();
        moveCount--;
    }
}