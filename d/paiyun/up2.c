// Room: /d/paiyun/up2.c

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
  "southdown" : __DIR__"up1",
  "northup" : __DIR__"up3",
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
