// Room: /d/linzhi/lin01.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·");
	set("long", @LONG
���ߵ�һ����ԭ��·�ϣ������������Ʈ�Ŷ����ƣ����
�����鱻�����ˡ��������ܿ�ȥ��ֻ�������Ӵ��׷��������
һ���Ǹ�ɽ��ѩ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"linzhie",
  "westdown" : __DIR__"lin02",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
