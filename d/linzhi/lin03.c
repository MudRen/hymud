// Room: /d/linzhi/lin03.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·�µ�");
	set("long", @LONG
���ߵ�һ����ԭ�µ��ϣ������������Ʈ�Ŷ����ƣ����
�����鱻�����ˡ��������ܿ�ȥ��ֻ�������Ӵ��׷��������
һ���Ǹ�ɽ��ѩ�ˡ�ǰ����һ��ɽ������ʱ������ˮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin02",
  "northdown" : __DIR__"lin04",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2800);
	setup();
	replace_program(ROOM);
}
