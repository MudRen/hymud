// Room: /d/tianshui/wroad2.c

inherit ROOM;

void create()
{
	set("short", "С������");
	set("long", @LONG
��ʯ�ֵ�������ͷ���죬����·�Ƚ�Ƨ����ƽʱҲ������
�������ϱ��������һ����ͨ����լ�����������һ��������Ǭ
ʥ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minju",
  "west" : __DIR__"simiao",
  "south" : __DIR__"gongjiang",
  "east" : __DIR__"wroad1",
]));
	set("outdoors", "tianshui");
	set("objects",([
"/clone/npc/man" : 3,
]));
	setup();
	replace_program(ROOM);
}
