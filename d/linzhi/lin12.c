// Room: /d/linzhi/lin12.c

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
  "northwest" : __DIR__"lin11",
  "southup" : __DIR__"lin13",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
