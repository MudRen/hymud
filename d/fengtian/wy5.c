// Room: /d/fengtian/wy5.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��������Զ·���жΣ�Ҳ����Զ·�����ֵĵط�����Ϊ����
�к�������жĳ�����·������һ�Ҿ�������Ժ����·�Ͼ���
�����÷��ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wy4",
  "east" : __DIR__"wy6",
  "north" : __DIR__"ji1",
]));

	set("objects",([
		"/d/city/npc/xunbu" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
