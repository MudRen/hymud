
// Room: /d/snow/sroad0.c


inherit ROOM;

void create()
{
	set("coor",({-150,4550,10}));
	set("short", "��ʯ�ٵ�");
	set("long",
"����һ������ʵ����ʯ���̳ɵĴ����·�ϳ���ĺۼ��Ѿ���·��������һ�������Եİ�\n"
"�ۡ�\n"
"��\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "northeast": __DIR__"sroad3",
]));
	set("outdoors", "ny");
//         set("objects", ([
//                __DIR__"npc/crazy_dog": 1 ]) );

	setup();
//        replace_program(ROOM);
}
