// Room: /d/jinghai/wm3.c

inherit ROOM;

void create()
{
	set("short", "无名堡城门");
	set("long", @LONG
无名堡的城门。两边长长的城墙由石条砌就，正中是一座高
耸的城楼，设有两扇护铜甲硬木城门，铺有双行青石板大道，通
向堡内外。城楼两角筑有石墙箭楼，站有两列箭手严阵以待。右
边城门上贴有一张告示(gaoshi)，一大群人挤在四周，交头接耳
不知在议论着什么。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"wm5",
  "northup" : __DIR__"wm4",
  "eastdown" : __DIR__"wm2",
  "west" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong5" : 2,
        __DIR__"npc/duizhang1.c" : 1 ,
]));

        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
