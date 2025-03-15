#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "game.h"
#include <time.h>
// 面向接口编程
// 下面这些函数指针就是接口
// 1.初始化游戏
typedef void (*INIT_GAME)(void **player, char *name);
// 2.副本战斗 1代表胜利  0代表失败
typedef int (*FIGHT_GAME)(void *player, int gamelevel);
// 3.查看玩家信息
typedef void (*PRINT_GAME)(void *player);
// 4.离开游戏
typedef void (*LEAVE_GAME)(void *player);

void play_game(INIT_GAME init, FIGHT_GAME fight,
               PRINT_GAME print, LEAVE_GAME leave)
{
    // 初始化游戏
    void *player = NULL;
    printf("请输入姓名: \n");
    char name[64];
    scanf("%s", name);
    init(&player, name);
    while (1)
    {
        // 游戏战斗
        int gamelevel = -1;
        printf("请选择游戏难度: 1.简单 2.中等 3.困难\n");
        scanf("%d", &gamelevel);
        if (fight(player, gamelevel))
            printf("Victory!\n");
        else
        {
            printf("Defeat!\n");
            break;
        }
        // 查看玩家信息
        print(player);
    }
    // 离开游戏
    leave(player);
}
int main()
{
    srand((unsigned int)time(NULL));
    play_game(game_init, game_fight,
              game_print, game_leave);
    // play_game();
    system("pause");
    return 0;
}
