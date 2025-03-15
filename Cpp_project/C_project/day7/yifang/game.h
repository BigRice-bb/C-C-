#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//约定好的接口
//1.初始化游戏
typedef void(*INIT_GAME)(void** player,char* name);
//2.副本战斗 1代表胜利  0代表失败
typedef int(*FIGHT_GAME)(void* player,int gamelevel);
//3.查看玩家信息
typedef void(*PRINT_GAME)(void* player);
//4.离开游戏
typedef void(*LEAVE_GAME)(void* player);

//开始设计
typedef struct 
{
    char name[64];//玩家姓名
    int level;//玩家等级
    int exp;//玩家经验
}player_t;

//1.初始化游戏
void game_init(void** player,char* name);
//2.副本战斗 1代表胜利  0代表失败
int game_fight(void* player,int gamelevel);
//3.查看玩家信息
void game_print(void* player);
//4.离开游戏
void game_leave(void* player);