// Room: /d/tianshui/nroad2.c

inherit ROOM;

void create()
{
	set("short", "С�򱱽�");
	set("long", @LONG
������������ķ����ضΣ�һ������һ�ɵƺ���̣�Ц����
�������������һƬ����Ϊ���֡��������ǽ��д��һ������
�������֣���ϸ��������������ѹ�͵��ּۻ��۵�������������
��һƬ��������ʱ���������ˣ�������Ѻһ�١��Ľк�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dangpu",
  "south" : __DIR__"nroad1",
  "east" : __DIR__"duchang",
]));

	set("outdoors","tianshui");
	set("objects",([
	__DIR__"npc/beggar" : 2,
]));
	setup();
	replace_program(ROOM);
}
