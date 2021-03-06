 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "杀人庄");
        set("long", @LONG
走到这里，天色忽然一暗，一种阴森森黑沉沉的杀气笼罩着此处的
上空。往前去是一个破落的大院，从残旧的门槛上可以看出这里的主人
曾经是那麽的受人欢迎。但那已是过去，那种种辉煌如今就只剩门上摇
摇欲坠的『聚义庄』牌匾，门前有块新竖立的木牌（ｓｉｇｎ）一块。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/qionghuajie",
  "west" : __DIR__"qyuan",

   ]));
        set("item_desc", ([
                "sign": @TEXT
一块警告牌，上面写着：
　　
　　生　　一
　　死　　入
　　自　　此
　　负　　门

TEXT
        ]) );  

        set("no_magic",1);
        set("NONPC",1);

        set("objects", ([
        
        __DIR__"npc/zanghua" : 1,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",5);
        setup();
} 
    
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int birdbox=0;

    if( dir == "east" && ob=present("ji zanghua", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if( (string)(inv[i]->query("id")) == "bird box")
            {
                tell_object(me,ob->name()+"傻笑着地将你身上染了血迹的"+
                            inv[i]->name()+"拿了回去．\n\n"); 
                destruct(inv[i]);
                return 1;
            }
            if( (string)(inv[i]->query("id")) == "corpse")
            {
                tell_object(me,ob->name()+"对你摇了摇头，「所有尸体都是杀人庄的贵宾，不能带走。」\n"+ob->name()+"轻轻地将你身上的"+
                            inv[i]->name()+"放了下来，埋入地中。\n\n"); 
                destruct(inv[i]);
                return 1;
            }
        }  
    }
    return 1;
}   