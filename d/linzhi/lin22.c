// Room: /d/linzhi/lin22.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ������");
	set("long", @LONG
�����Ǹ�ԭɽ�����£����涸�ͣ���������������棬��ʱ
��ͣ������Ϣ��Ϣ��ǰ���·���ܳ�������Щ�����ˣ���������
�ͻ�ȥ�ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin21",
  "northwest" : __DIR__"lin31",
  "south" : __DIR__"lin23",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
