// Room: /d/paiyun/up3.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ɽ����·��������·�ǳ�������·�߳�������ݣ�
·��ȴ���ǽ�ӡ����ӡ�������������˾������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up2",
  "northup" : __DIR__"up4",
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
