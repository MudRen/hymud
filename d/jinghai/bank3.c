// Room: /d/jinghai/bank3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ����ǰһ����ο��ɫ�Ĵ���׺������ʯ�ĵ�̺������
��ͷֱ�̵���Ľ��£����ڽ�ɫ��ɳ̲�ϣ����������µĴ�����
ζ�Ŀ������������һƬ������ֻ���������ķ���ȫ��һɨ���ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bank2",
  "east" : __DIR__"bank4",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}
