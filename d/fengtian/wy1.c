// Room: /d/fengtian/wy1.c

inherit ROOM;

void create()
{
	set("short", "��Զ·");
	set("long", @LONG
��Զ·��һ��������Ĵ�֣�Ҳ��ʢ�����ɵ�����ֶ�����
ͨ���ֵ�Ҳ�൱���������������±Ƚ�̫ƽ�������β��õ�ʢ��
���������˰Ѿ�·�����ˣ����������Ϲٵ��ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhengbing",
  "west" : __DIR__"guanlu1",
  "east" : __DIR__"wy2",
  "north" : __DIR__"xiang1",
]));

	set("objects",([
		"/d/city/npc/xunbu" : 1,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
