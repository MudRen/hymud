// Room: /d/jinghai/zhuque1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��·");
	set("long", @LONG
����������ֽ��µ�ʯ��·�ƺ����̲��ã���ʯ�ļ���
����ŵ���ʹ��·��������һ���ŵ��������������������úõ�
ЪЪ������һ�뵽���ѻ�����ô������û���ֻ���ڶ���̾����
���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhuque5",
  "south" : __DIR__"zhuque4",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
