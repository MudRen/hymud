// Room: /d/jinghai/moon6.c

inherit ROOM;

void create()
{
	set("short", "��ջ��");
	set("long", @LONG
����һ������ʯƴ�̳ɵĵ�·����·���������������Բľ
Χǽ����·���ϱ����������ֱ�����ӿ�ȥ��ʱ��ʱ��һ�ӶӺ�
��ˮ��������������ˮկկ�š��ϱ߲�Զ���Կ���һ����
�ء���������ֱ���ˮկ�Ļ﷿��ʿ��Ӫ�������ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon5",
  "east" : __DIR__"moon13",
  "west" : __DIR__"moon12",
  "south" : __DIR__"moon7",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
