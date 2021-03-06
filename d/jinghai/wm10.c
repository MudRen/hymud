// Room: /d/jinghai/wm10.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
你走在一条用五彩缤纷的石子铺成的小路上，石子组成了各
种花纹。小路两旁种满了竹子，修篁森森，绿荫满地。不时有莺
歌鸟鸣声声传来，令人心旷神怡。西面就要快到堡中心了，可以
看到中心钟楼耸立，往东可以看到无名堡水寨大门了。
LONG
	);

        

	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wm19",
  "east" : __DIR__"wm9",
  "west" : __DIR__"wm11",
]));
        set("objects",([
        __DIR__"npc/kanshou2" : 1,
]));


        set("outdoors","jinghai");

	setup();
}
int valid_leave(object who,string dir)
{
        object npc;

        npc=present("kan shou",this_object());

        if(dir=="east" || dir == "e")
        {
       who->delete_temp("can_enter_wm19");
        return ::valid_leave(who,dir);
        }

        if(npc&& (dir == "north" || dir == "n")
        && !who->query_temp("can_enter_wm19") )
        return notify_fail("看守说道：没有令牌休想进入兵器库。\n");

        return ::valid_leave(who,dir);
}

