// Room: /d/fengtian/guanlu3.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����·��ͨ��ʢ�����ŵĹٵ�������û����������ô������
���ӣ��ٵ����в��ٽ��Ǻͳ��ǵ��ˣ�������ԶԶ���Կ���ʢ��
�ǵ������ˣ�·�Ķ�����Ѳ��Ӫ��
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"s_gate",
  "east" : __DIR__"xunbu",
  "north" : __DIR__"guanlu2",
]));

	setup();
	replace_program(ROOM);
}
