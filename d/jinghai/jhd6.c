// Room: /d/jinghai/jhd6.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
���ص�ˮ�����ذ������㣬���µ�·�������ޣ��㲻�ҷſ�
�Ų�������һʧ��ͻ������������㽻�����ʯ��ˤ��������ǡ�
��һ��һ����Ų�ţ�ʱ���ƺ������ر���������صĺ��������
�����ĺ����İ�����Ҳ�������š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jhd5",
  "southwest" : __DIR__"jhd27",
  "south" : __DIR__"jhd28",
]));
	set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
