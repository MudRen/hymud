// Room: /d/jinghai/moon25.c

inherit ROOM;

void create()
{
	set("short", "战船甲板上");
	set("long", @LONG
厚厚的箭垛上尽是箭矢炮石留下的斑驳痕迹，甲板一侧站着
一排红巾水勇，虽然船身晃动，可他们还是站得笔直，威震天下
的明月水寨就是靠这些人一刀一箭拼死建立起来的，在海上，无
论谁都不敢轻视他们的力量。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon16",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
