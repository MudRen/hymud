// Room: /d/fengtian/guanlu2.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����·��ͨ��ʢ�����ŵĹٵ�������û����������ô������
���ӣ��ٵ����в��ٽ��Ǻͳ��ǵ��ˣ�������ԶԶ���Կ���ʢ��
�ǵ������ˡ�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guanlu3",
  "north" : __DIR__"lukou",
]));

	set("objects",([
		"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
