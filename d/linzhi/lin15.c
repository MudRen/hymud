// Room: /d/linzhi/lin15.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·");
	set("long", @LONG
����һ����ԭ��·��·����ɽ�ư�͹��ʱ��ɽ�紵��������
���������������Щ���⡣�����µ���ʱ��ʱ�£����˲�һ��
�����͸е���Щ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin14",
  "southdown" : __DIR__"lin16",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
