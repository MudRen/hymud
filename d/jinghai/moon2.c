// Room: /d/jinghai/moon2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ɽ�Զ��˵ı�Ե��������ȥ���Կ���������ӿ���Ļ�
���µ׵���ʯ����������һ�����°�ľ�����һ˿�����С�����
һ��������Ƕ�ڱ����ĺ���֮�С��򱱲�Զ����Լ���Կ���һ��
Сͤ��������һ��ʯ��ƴ�̳ɵĵ�·ͨ��ɽ�¡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon23",
  "westdown" : __DIR__"moon3",
  "southeast" : __DIR__"moon1",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
