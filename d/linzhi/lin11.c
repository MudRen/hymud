// Room: /d/linzhi/lin11.c

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
  "northdown" : __DIR__"lin07",
  "southeast" : __DIR__"lin12",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
