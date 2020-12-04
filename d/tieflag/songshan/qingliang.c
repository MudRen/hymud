 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "清凉寺外院");
        set("long", @LONG
已接近山脚，独处一隅，数千株翠柏苍松密密的把寺庙围在当
中，即便在夏日之中，依旧阴凉无比，故此寺名清凉。每年秋天松
果盈树，清香扑鼻。此间有松茶最为吸引人，常有人不远千里来品
尝寺中长老调制的松茶。每年春天这里的松针落得满地，都需要人
略做打扫，否则便会积成淤泥。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lianhua",
  "east" : __DIR__"qingliang2",
]));
        set("coor/x",-220);
        set("coor/y",380);
        set("coor/z",50);
        set("objects", ([
                __DIR__"npc/lama2" : 1,
        ]) );
        setup();
        //replace_program(ROOM);
}      
int valid_leave(object me, string dir)
{
	if ( objectp(present("jin bo", environment(me))) && 
		dir == "east")
		return notify_fail("金伯胜夷拦住了你的去路 不准坏了我们桑结活佛的大事。\n");


	return ::valid_leave(me, dir);
}