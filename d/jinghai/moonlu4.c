// Room: /d/jinghai/moonlu4.c

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
  "southup" : __DIR__"moonlu3",
  "north" : __DIR__"moonlu5",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}
