// Room: /d/jinghai/jhd16.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
����һ����С�����ã����������һ�������ˣ�ÿ��һ�ε�
���������СͷĿ���̰������������С��м�һ�Ż�Ƥ���ε�
ǰ������������ĺ�ľС�ʣ��м�һ�����̺һֱ�̵���Ƥ��ǰ��
�����Ǽ�յ��ڴֵ��͵ƣ���������ʹ�˲���ʹ����Ȼ�𾴡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jhd17",
  "west" : __DIR__"jhd20",
  "south" : __DIR__"jhd15",
]));
        set("objects",([
        __DIR__"npc/jiading2" : 4,
]));
	setup();
	replace_program(ROOM);
}
