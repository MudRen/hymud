// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "边关关卡");
	set("long", @LONG
这里是就是太原附近的边关关卡了。这里历来是兵家必争之地。
这里有几个官兵，在检查着来往的行人。
LONG );
	set("exits", ([
//		"west"  : "/d/tuyuhun/silk",
 		"south"  : __DIR__"road9a",
		
	]));
	set("objects",([
	__DIR__"npc/bing":2,
	]));
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



