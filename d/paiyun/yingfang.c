// Room: /d/paiyun/yingfang.c

inherit ROOM;

void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
����Ӫ��������������ܶല�����ϵı�����������
�У�����һ����֪������ľ��ͺ��ϸ񣬲���һ��ǿ���ľ�Ӫ��
����һ��������ĸо���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu2",
]));
	setup();
	replace_program(ROOM);
}
