// Room: /d/jinghai/wm5.c

inherit ROOM;

void create()
{
	set("short", "�ϳ�ǽ");
	set("long", @LONG
��ΰ�ĳ�ǽ�������ɶ�ߣ��ô�ʯ���������ɣ���ǽ�����
�߲������������Ѿ���Щ����ˣ���ǽ�������Ʈ�����һ��
����һ����¥����������ʿ��еѲ�ߡ����ų����ĳ�ǽ������һ
����ʵ����ʯ·�����Թ������ߡ�
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
