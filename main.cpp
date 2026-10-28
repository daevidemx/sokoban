#include <raylib.h>
#include <cmath>

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

struct Player {
    int posX;
    int posY;
    float drawX;
    float drawY;
};

void controlMechanics(Player &pl, int lvl[16][16]);
void changeLevel(Player &pl, int x, int y, int lvl[16][16], int nextLvl[16][16], int tileSize);

int main() {

    InitWindow(768, 768, "Sokoban");
    SetTargetFPS(60);

    Texture2D brickTex = LoadTexture("images/sprite_bricks.png");
    Texture2D grassTex = LoadTexture("images/sprite_grass.png");
    Texture2D playerTex = LoadTexture("images/sprite_player.png");
    Texture2D boxTex = LoadTexture("images/sprite_box.png");
    Texture2D winTex = LoadTexture("images/sprite_win.png");

    //TEMP
    Texture2D winBox = LoadTexture("images/sprite_winbox.png");

    int tileSize = brickTex.width;
    Player pl = {5, 9, 5.0f * tileSize, 9.0f * tileSize};
    int lvl[16][16] = {
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
    int currentLevel = 1;

    while (WindowShouldClose() == false) {

        bool lvlWin = true;

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (lvl[i][j] == 3) {
                    lvlWin = false;
                }
            }
        }

        if (lvlWin) {
            if (IsKeyPressed(KEY_ENTER)) {
                currentLevel++;
                switch (currentLevel) {
                    case 2:
                        changeLevel(pl, 5, 10, lvl, lvl2, tileSize);
                        break;
                    case 3:
                        changeLevel(pl, 7, 10, lvl, lvl3, tileSize);
                        break;
                    case 4:
                        changeLevel(pl, 4, 8, lvl, lvl4, tileSize);
                        break;
                    case 5:
                        changeLevel(pl, 5, 10, lvl, lvl5, tileSize);
                        break;
                    default:
                        break;
                }
            }
        } else {
            controlMechanics(pl, lvl);
        }

        float slideSpeed = 20.0f;
        pl.drawX += (pl.posX * tileSize - pl.drawX) * slideSpeed * GetFrameTime();
        pl.drawY += (pl.posY * tileSize - pl.drawY) * slideSpeed * GetFrameTime();

        if (abs((pl.posX * tileSize) - pl.drawX) < 0.5f) {
            pl.drawX = pl.posX * tileSize;
        }
        if (abs((pl.posY * tileSize) - pl.drawY) < 0.5f) {
            pl.drawY = pl.posY * tileSize;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (lvl[i][j] == 1) {
                    DrawTexture(brickTex, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 2) {
                    DrawTexture(boxTex, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 3) {
                    DrawTexture(winTex, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 4) {
                    DrawTexture(winBox, j * tileSize, i * tileSize, WHITE);
                } else if (lvl[i][j] == 0) {
                    DrawTexture(grassTex, j * tileSize, i * tileSize, WHITE);
                } else {
                    //Prints black.
                }
            }
        }
        DrawTexture(playerTex, (int)pl.drawX, (int)pl.drawY, WHITE);

        if (lvlWin) {
            DrawText("YOU WIN!", 310, 320, 40, GOLD);
            DrawText("Press ENTER to continue!", 260, 380, 20, LIGHTGRAY);
        }

        EndDrawing();
    }

    UnloadTexture(brickTex);
    UnloadTexture(grassTex);
    UnloadTexture(playerTex);

    CloseWindow();

    return 0;
}

void controlMechanics(Player &pl, int lvl[16][16]) {
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (lvl[pl.posY][pl.posX + 1] == 0 || lvl[pl.posY][pl.posX + 1] == 3) {
                pl.posX += 1;
            } else if ((lvl[pl.posY][pl.posX + 1] == 2 || lvl[pl.posY][pl.posX + 1] == 4) && (lvl[pl.posY][pl.posX + 2] == 0 || lvl[pl.posY][pl.posX + 2] == 3)) {
                if (lvl[pl.posY][pl.posX + 1] == 4) {
                    pl.posX += 1;
                    lvl[pl.posY][pl.posX] = 3;
                    if (lvl[pl.posY][pl.posX + 1] == 3) {
                        lvl[pl.posY][pl.posX + 1] = 4;
                    } else {
                        lvl[pl.posY][pl.posX + 1] = 2;
                    }
                } else {
                    pl.posX += 1;
                    lvl[pl.posY][pl.posX] = 0;
                    if (lvl[pl.posY][pl.posX + 1] == 3) {
                        lvl[pl.posY][pl.posX + 1] = 4;
                    } else {
                        lvl[pl.posY][pl.posX + 1] = 2;
                    }
                }
            }
        } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (lvl[pl.posY][pl.posX - 1] == 0 || lvl[pl.posY][pl.posX - 1] == 3) {
                pl.posX -= 1;
            } else if ((lvl[pl.posY][pl.posX - 1] == 2 || lvl[pl.posY][pl.posX - 1] == 4) && (lvl[pl.posY][pl.posX - 2] == 0 || lvl[pl.posY][pl.posX - 2] == 3)) {
                if (lvl[pl.posY][pl.posX - 1] == 4) {
                    pl.posX -= 1;
                    lvl[pl.posY][pl.posX] = 3;
                    if (lvl[pl.posY][pl.posX - 1] == 3) {
                        lvl[pl.posY][pl.posX - 1] = 4;
                    } else {
                        lvl[pl.posY][pl.posX - 1] = 2;
                    }
                } else {
                    pl.posX -= 1;
                    lvl[pl.posY][pl.posX] = 0;
                    if (lvl[pl.posY][pl.posX - 1] == 3) {
                        lvl[pl.posY][pl.posX - 1] = 4;
                    } else {
                        lvl[pl.posY][pl.posX - 1] = 2;
                    }
                }
            }
        } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            if (lvl[pl.posY + 1][pl.posX] == 0 || lvl[pl.posY + 1][pl.posX] == 3) {
                pl.posY += 1;
            } else if ((lvl[pl.posY + 1][pl.posX] == 2 || lvl[pl.posY + 1][pl.posX] == 4) && (lvl[pl.posY + 2][pl.posX] == 0 || lvl[pl.posY + 2][pl.posX] == 3)) {
                if (lvl[pl.posY + 1][pl.posX] == 4) {
                    pl.posY += 1;
                    lvl[pl.posY][pl.posX] = 3;
                    if (lvl[pl.posY + 1][pl.posX] == 3) {
                        lvl[pl.posY + 1][pl.posX] = 4;
                    } else {
                        lvl[pl.posY + 1][pl.posX] = 2;
                    }
                } else {
                    pl.posY += 1;
                    lvl[pl.posY][pl.posX] = 0;
                    if (lvl[pl.posY + 1][pl.posX] == 3) {
                        lvl[pl.posY + 1][pl.posX] = 4;
                    } else {
                        lvl[pl.posY + 1][pl.posX] = 2;
                    }
                }
            }
        } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            if (lvl[pl.posY - 1][pl.posX] == 0 || lvl[pl.posY - 1][pl.posX] == 3) {
                pl.posY -= 1;
            } else if ((lvl[pl.posY - 1][pl.posX] == 2 || lvl[pl.posY - 1][pl.posX] == 4) && (lvl[pl.posY - 2][pl.posX] == 0 || lvl[pl.posY - 2][pl.posX] == 3)) {
                if (lvl[pl.posY - 1][pl.posX] == 4) {
                    pl.posY -= 1;
                    lvl[pl.posY][pl.posX] = 3;
                    if (lvl[pl.posY - 1][pl.posX] == 3) {
                        lvl[pl.posY - 1][pl.posX] = 4;
                    } else {
                        lvl[pl.posY - 1][pl.posX] = 2;
                    }
                } else {
                    pl.posY -= 1;
                    lvl[pl.posY][pl.posX] = 0;
                    if (lvl[pl.posY - 1][pl.posX] == 3) {
                        lvl[pl.posY - 1][pl.posX] = 4;
                    } else {
                        lvl[pl.posY - 1][pl.posX] = 2;
                    }
                }
            }
        }
}
void changeLevel(Player &pl, int x, int y, int lvl[16][16], int nextLvl[16][16], int tileSize) {
    pl = {x, y, (x * tileSize), (y * tileSize)};
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            lvl[i][j] = nextLvl[i][j];
        }
    }
}