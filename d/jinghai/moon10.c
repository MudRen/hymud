// Room: /d/jinghai/moon10.c

inherit ROOM;

void create()
{
	set("short", "��ջ��");
	set("long", @LONG
����һ������ʯƴ�̳ɵĵ�·����·���������������Բľ
Χǽ����·�������������ֱ�����ӿ�ȥ��ʱ��ʱ��һ�ӶӺ�
��ˮ�����������򱱲�Զ�����Կ���ɽ��������һ��կ�š���
����ȫկ����ߵ㣬����կ���̨�����߲�Զ���Կ���һ����
�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon16",
  "south" : __DIR__"moon17",
  "west" : __DIR__"moon7",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
