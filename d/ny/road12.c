
// Room: /d/ustc/bforest/road12.c

inherit ROOM;

void create()
{
    set("coor",({1050,4650,10}));
	set("short", "����С��");
	set("long",
"����һƬï�ܵ�����,һ��������ͷ,��ֻ�������г�������,�Ա��п�ʯͷ,�Ͽ����Ѫ���\n"
"�� ������˵� ,���ܶ�������,���ƺ�����·��!\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"eroad1",
  "west" : __DIR__"road11",
]));
        set("objects", ([ /* sizeof() == 2 */
   __DIR__"npc/crazy_dog" : 2,
]));

	setup();
	replace_program(ROOM);
}
