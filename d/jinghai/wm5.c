// Room: /d/jinghai/wm5.c

inherit ROOM;

void create()
{
	set("short", "南城墙");
	set("long", @LONG
雄伟的城墙，有三丈多高，用大石条堆砌而成，城墙上面斑
斑驳驳，看起来已经有些年代了，城墙顶端旌旗飘扬。往南一丈
设有一个箭楼，上面有武士持械巡逻。沿着长长的城墙下铺有一
条结实的碎石路，可以供人行走。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"wm3",
  "south" : __DIR__"wm7",
]));
        set("objects",([
        __DIR__"npc/yong5" : 1,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
