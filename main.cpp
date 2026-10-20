#include <raylib.h>
#include <stdbool.h>

struct Player {
    int posX;
    int posY;
};

int main() {

    Player player = {1, 1};

    InitWindow(768, 768, "Sokoban");
    SetTargetFPS(60);

    Texture2D brickTex = LoadTexture("images/sprite_bricks.png");
    Texture2D grassTex = LoadTexture("images/sprite_grass.png");
    Texture2D playerTex = LoadTexture("images/sprite_player.png");
    Texture2D boxTex = LoadTexture("images/sprite_box.png");
    Texture2D winTex = LoadTexture("images/sprite_win.png");

    int tileSize = brickTex.width;
    int level[16][16] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    while (WindowShouldClose() == false) {

        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (level[player.posY][player.posX + 1] == 0) {
                player.posX += 1;
            } else if (level[player.posY][player.posX + 1] == 2 && level[player.posY][player.posX + 2] == 0) {
                player.posX += 1;
                level[player.posY][player.posX] = 0;
                level[player.posY][player.posX + 1] = 2;
            }
        } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (level[player.posY][player.posX - 1] == 0) {
                player.posX -= 1;
            } else if (level[player.posY][player.posX - 1] == 2 && level[player.posY][player.posX - 2] == 0) {
                player.posX -= 1;
                level[player.posY][player.posX] = 0;
                level[player.posY][player.posX - 1] = 2;
            }
        } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            if (level[player.posY + 1][player.posX] == 0) {
                player.posY += 1;
            } else if (level[player.posY + 1][player.posX] == 2 && level[player.posY + 2][player.posX] == 0) {
                player.posY += 1;
                level[player.posY][player.posX] = 0;
                level[player.posY + 1][player.posX] = 2;
            }
        } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            if (level[player.posY - 1][player.posX] == 0) {
                player.posY -= 1;
            } else if (level[player.posY - 1][player.posX] == 2 && level[player.posY - 2][player.posX] == 0) {
                player.posY -= 1;
                level[player.posY][player.posX] = 0;
                level[player.posY - 1][player.posX] = 2;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (level[i][j] == 1) {
                    DrawTexture(brickTex, j * tileSize, i * tileSize, WHITE);
                } else if (level[i][j] == 2) {
                    DrawTexture(boxTex, j * tileSize, i * tileSize, WHITE);
                } else if (level[i][j] == 3) {
                    DrawTexture(winTex, j * tileSize, i * tileSize, WHITE);
                } else {
                    DrawTexture(grassTex, j * tileSize, i * tileSize, WHITE);
                }
            }
        }
        DrawTexture(playerTex, player.posX * tileSize, player.posY * tileSize, WHITE);

        EndDrawing();
    }

    UnloadTexture(brickTex);
    UnloadTexture(grassTex);
    UnloadTexture(playerTex);

    CloseWindow();

    return 0;
}