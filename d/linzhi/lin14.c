// Room: /d/linzhi/lin14.c

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
  "north" : __DIR__"lin13",
  "south" : __DIR__"lin15",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
