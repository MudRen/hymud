// Room: /d/paiyun/up4.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ɽ����·��������·�ǳ�������·�߳�������ݣ�
·��ȴ���ǽ�ӡ����ӡ�������������˾�����������濴��һ
���ߴ��կ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up3",
  "northup" : __DIR__"door",
]));
        set("NONPC",1);


	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
