// Room: /d/jinghai/jhd23.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ��Ժ");
	set("long", @LONG
�����Ǿ������ĺ�Ժ������ǰԺ�����ﰲ���˺ܶ࣬��Ϊ��
�治Զ�����Ǿ����ɵ��������ˡ�Ժ���м���һ��ССˮ�أ���
��һ����ɽ������峺��Ȫˮ����Χǽ����ֲ�˼�����������
ȥ�����������ǵľ���ɽׯ�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jhd25",
  "east" : __DIR__"jhd20",
  "south" : __DIR__"jhd26",
  "west" : __DIR__"jhd24",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
