// Room: /d/fengtian/wy4.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·��һ�������ᴮ�Ĵ�֣�Ҳ��ʢ������Ľֵ�����
�������Ǹ����ʮ��·�ڣ�������Զ·���жΣ�·����һ��ͦ
��ĳ��ׯ��
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chou",
  "west" : __DIR__"cross",
  "east" : __DIR__"wy5",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
