#include "game.h"

//1.初始化游戏
void game_init(void** player,char* name)
{
    player_t *p=(player_t*)malloc(sizeof(player_t));
    if(p==NULL)
    {
        printf("login failed\n");
        return;
    }
    *player=p;
    strcpy(p->name,name);
    p->level=0;
    p->exp=0;
    printf("login success\n");
}
int isWin(int winRate,int diff)
{
    int random=rand()%100+1;//随机数1-100
    if (random<=winRate)
    {
        return diff*10;
    }
    else
    {
        return 0;
    }
}
//2.副本战斗 1代表胜利  0代表失败
int game_fight(void* player,int gamelevel)
{
    player_t*p=(player_t*)player;
    int addExp=0;
    switch (gamelevel)
    {
    case 1:
        addExp=isWin(90,1);
        break;
    case 2:
        addExp=isWin(50,1);
        break;
    case 3:
        addExp=isWin(30,1);
        break;
    default:
        break;
    }
    p->exp+=addExp;//经验加到玩家身上
    p->level=p->exp/10;// 升级
    if (addExp==0)
    {
        //printf("Defeat!\n");
        return 0;
    }
    else
    {
        //printf("Victory!\n");
        return 1;
    }
}

//3.查看玩家信息
void game_print(void* player)
{
    player_t* p=(player_t*)player;
    printf("name:%s level:%d exp:%d\n",p->name,p->level,p->exp);
}
//4.离开游戏
void game_leave(void* player)
{
    player_t* p=(player_t*)player;
    printf("当前玩家等级: %d\n",p->level);
    if (player==NULL)
    {
        printf("logout success\n");
        return;
    }
    else
    {
        free(player);
        player=NULL;
    }
    
}
