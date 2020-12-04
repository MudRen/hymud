// Room: /d/huanggong/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "后宫");
	set("long", @LONG
这是皇后的寝宫. 这里与前面皇上的乾清宫, 象征天地乾坤, 紫徵
正中. 坤宁意为大地安宁. 后宫的东西六院则象征十二星宿.
LONG
	);
	set("magicroom",1);set("exits", ([ /* sizeof() == 4 */
		 "west"  : __DIR__"hougong",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/xiannu" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}