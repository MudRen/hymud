// Room: /d/jinghai/wm4.c

inherit ROOM;

void create()
{
	set("short", "����ǽ");
	set("long", @LONG
��ΰ�ĳ�ǽ�������ɶ�ߣ��ô�ʯ���������ɣ���ǽ�����
�߲������������Ѿ���Щ����ˣ���ǽ�������Ʈ�����һ��
����һ����¥����������ʿ��еѲ�ߡ����ų����ĳ�ǽ������һ
����ʵ����ʯ·�����Թ������ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wm6",
  "southdown" : __DIR__"wm3",
]));
        set("objects",([
        __DIR__"npc/yong5" : 1,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
