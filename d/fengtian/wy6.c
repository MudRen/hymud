// Room: /d/fengtian/wy6.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·�Ķ��ڣ�ԶԶ���Ѿ����Կ��������ʵ۸��ˣ�����
����Ҳ�Ƚ��ྲ��·����һ�Һ������Ĵ����̣�������Դ�����
�����������Ͼ͹յ����ֽ����ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ll1",
  "west" : __DIR__"wy5",
  "east" : __DIR__"jjf1",
  "north" : __DIR__"smith",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
