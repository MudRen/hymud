// Room: /d/fengtian/wy2.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·��һ��������Ĵ�֣�Ҳ��ʢ�����ɵ�����ֶ�����
ͨ���ֵ�Ҳ�൱���������������±Ƚ�̫ƽ�������β��õ�ʢ��
���������˰Ѿ�·�����ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mashi",
  "west" : __DIR__"wy1",
  "east" : __DIR__"wy3",
]));

	set("objects",([
	__DIR__"npc/wuzhe" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
