// Room: /open/dt/mujiangpu.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ�Ҳ����ľ���̣����ĸ�ľ��������ͷ�󺺵�æ�ţ�
��������ͷ�������״�������������ڴ�һֻľ�����ﵽ����
�ٻ���һ�����µ�ľͷ�������������ݽ����ҵ�ɢ����һЩ
ľͷ�飬һ�������ڰ�һ��ľ����һ����ľ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu4",
]));

	setup();
	replace_program(ROOM);
}
