// Room: /d/jinghai/bank2.c

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
  "southwest" : __DIR__"bank1",
  "north" : __DIR__"bank3",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}
