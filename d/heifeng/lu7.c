// Room: /d/heifeng/lu7.c

inherit ROOM;

void create()
{
	set("short", "ƽ̹ɽ·");
	set("long", @LONG
���ǰ�ɽ����һ��ƽ̹��ɽ·�������ǳ�����ľ�ӲݵĶ���
��ɽ�£�·�����Ƕ��͵�ɽ�ڣ�˳��ɽ��������ȥ���������е�
ɽ����Լ�ɼ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lu8",
  "south" : __DIR__"lu6",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
