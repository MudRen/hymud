// Room: /open/dt/minju3.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����Ϊ��ԣ���˼ң������ŵ�ǽ�Ϲ��ż���ͨ��Ĵ�
��������Ժ�ӱ߽�Χ��һ��С԰�أ��������ż�ʮ���ɽ���档
Ժ����û���ˣ���ֻ��ȴ��Ϊ��ĵ�������������Ѳ�ң���ʱ��
���ؽ��ϼ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu2",
]));

	set("objects",([
	__DIR__"npc/laozhe" : 1,
]));

	setup();
	replace_program(ROOM);
}
