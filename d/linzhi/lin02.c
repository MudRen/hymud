// Room: /d/linzhi/lin02.c

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
  "eastup" : __DIR__"lin01",
  "westdown" : __DIR__"lin03",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3000);
	setup();
	replace_program(ROOM);
}
