// Room: /d/fengtian/wy3.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·��һ��������Ĵ�֣�Ҳ��ʢ�����ɵ�����ֶ�����
ͨ���ֵ�Ҳ�൱���������������±Ƚ�̫ƽ�������β��õ�ʢ��
���������˰Ѿ�·�����ˣ��������Ǹ�ʮ��·�ڡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"bank",
  "west" : __DIR__"wy2",
  "east" : __DIR__"cross",
  "north" : __DIR__"wuguan",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
