

inherit ROOM;

void create()
{
	set("short", "��ˮ�򶫿�");
	set("long", @LONG
��������ˮ��Ķ��ڡ���ˮ����˵ֻ��һ�����ż�ʮ���˼�
��С���ӣ������ڵش�Ҫ�壬��������������������һ�����ѵ�
С·��Զ����չ��
LONG
	);
	set("exits", ([

  "west" : __DIR__"eroad3",
  "east" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();


	replace_program(ROOM);
}
