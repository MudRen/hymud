inherit ROOM;

void create()
{
	set("short", "�ݾ�");
	set("long", @LONG
����һ�ڿݾ������������Ѿ������ˡ����ܶ������ż�ֻ
��ȸ���������߹����������ų�����������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
  "south" : __DIR__"lu11",
]));
	set("outdoors", "zuojiacun");
	setup();


	replace_program(ROOM);
}
