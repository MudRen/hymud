// Room: /d/fengtian/lukou.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
������һ��СС��·�ڣ����ڿ���ʢ�������ţ�����������
���ϣ����Ƿǳ������֣����Ͽ�ʢ����������ңң����������һ
ֱ�߾���ʢ�������ĵش��ˡ�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kd5",
  "south" : __DIR__"guanlu2",
  "east" : __DIR__"kd4",
  "north" : __DIR__"xm1",
]));

	setup();
	replace_program(ROOM);
}
