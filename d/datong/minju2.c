// Room: /open/dt/minju2.c

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
  "south" : __DIR__"luzhuxiang3",
]));

	setup();
	replace_program(ROOM);
}
