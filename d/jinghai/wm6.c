// Room: /d/jinghai/wm6.c

inherit ROOM;

void create()
{
	set("short", "北箭楼");
	set("long", @LONG
无名堡箭楼。几位穿戴盔甲的箭手来来回回地走动着，不时
的通过了望孔向下警惕的观察着来往行人。现在虽然很太平，但
无名堡平时还是守备森严。当你走到这里的第一个感觉，也许就
只有“杀气腾腾”这四个字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wm4",
]));
        set("objects",([
        __DIR__"npc/yong5" : 1,
]));



        set("outdoors","jinghai");
	setup();
	replace_program(ROOM);
}
