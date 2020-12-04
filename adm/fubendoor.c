#include <ansi.h>
inherit ITEM; 

void create() 
{ 
                
           set_name(RED"副本传送门"NOR, ({ "fuben door", "door" }) ); 
            set_weight(5); 
               if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                     set("long", HIB"目前的功能有：\n"+ 
                                  "enter <迷宫代码>：创建一个属于自己或队伍的迷宫副本。\n"+ 
                                  "迷宫代码：forest-原始森林，desert-无尽大漠，dragon-巨龙封印，necropolis-诡异墓园，temple-失落神庙，mausoleum-秦皇陵墓。\n"+ 
                                  "\n"NOR);  
                      set("unit", "个"); 
                      set("no_get",1); 
                      set("value", 20); 
              } 
              setup(); 
      } 
       
      void init() 
      { 
              add_action("do_enter","enter"); 
      } 
       
      int do_enter(string arg)  
     { 
              int valid; 
                       
             if( !arg || arg == "" ) 
                      return 0; 
               
              valid = FUBEN_D->valid_enter(this_player(), arg);  
              if( valid >=1 ) 
                      FUBEN_D->enter_fuben(this_player(), arg); 
              else { 
                      if( valid == 0 ) 
                              write("您实战经验不足，进副本恐有不测，还是先历练一下再来吧。\n"); 
                      else if( valid == -1 ) 
                              write("您经验太高了，就不要进去欺负那些可怜的小怪物了吧。\n"); 
                      else if( valid == -2 ) 
                              write("游戏中目前并没有开放该副本，请您核对后再试。\n"); 
                      else if( valid == -3 ) 
                              write("该副本限制IP多重进入，您已经超过最高上限。\n"); 
                      else if( valid == -4 ) 
                              write("该副本被巫师关闭，您暂时无法进入。\n"); 
                      else if( valid == -5 ) 
                              write("你离上次进入副本时间太短，请休息会再来。\n"); 
                      else if( valid == -6 ) 
                              write("该副本必须组队才能进入。\n"); 
                      else if( valid == -7 ) 
                              write("你的队伍人数超过该副本规定的上限。\n"); 
              }         
              return 1; 
      } 