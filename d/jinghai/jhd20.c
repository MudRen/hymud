// Room: /d/jinghai/jhd20.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
ǧ���׵ã�һ������Ϊ�˱�֤�����ɵĲ���׳������ÿ
�궼Ҫ�Ӹ���ǰ����ѵ�ı�����������ѡ��һ���ݽܳ�֮ʿ����
�����������ɿ��Զ���һ����˲š���������Ǿ��������µ���
ѧϰ�������书��ĵط������еĸ������Զ�붼��������ѧϰ
����������ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jhd22",
  "east" : __DIR__"jhd16",
  "west" : __DIR__"jhd23",
  "south" : __DIR__"jhd21",
]));
        set("objects",([
        __DIR__"npc/master2" : 1,
  __DIR__"npc/master5.c" : 1,
  __DIR__"npc/master3.c" : 1,
]));


	setup();
	replace_program(ROOM);
}
