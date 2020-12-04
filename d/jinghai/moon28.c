// Room: /d/jinghai/moon28.c

inherit ROOM;

void create()
{
	set("short", "密道中");
	set("long", @LONG
这里是一条狭窄的过道，它是通向牢房的唯一通道。四壁用
大块的青石砌成。密道内只有墙壁上的小油灯，格外昏暗潮湿。
偶尔会听见还有滴答滴答的流水声音。静静得没有一点声响。很
是吓人。墙壁上悬挂这一条很粗大得[绳子]。密道向北继续延伸
着。
LONG
	);
       set("item_desc", ([ 
	"绳子" : "可以(climb)试试。/n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon29",
]));

	setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();

	if( !arg && arg != "绳子" && arg != "shengzi")
		return 0;
        message_vision("$N双手用力抓住绳子，脚下一蹬向上攀登而去。\n",me);
        me->move(__DIR__"moon23");

        return 1;
}
