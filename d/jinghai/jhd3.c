// Room: /d/jinghai/jhd3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��СС�������֪����ʲô���½��ɵģ���Ȼ��
�����ƾ��ˣ��������ϵ���¯����Ȼ�������ơ�������﹩����
һ�����񣬾�˵����������Ϊ�ܹ����ĵس������㣬ÿ�γ���ǰ
��Ҫ�����������׵������ܹ��ô󺣷�ƽ�˾�����������Ҳ��
������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhd1",
  "northeast" : __DIR__"jhd4",
  "west" : __DIR__"jhd7",
  "south" : __DIR__"jhd5",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
