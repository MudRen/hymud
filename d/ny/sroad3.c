
// Room: /d/snow/sroad3.c

inherit ROOM;

void create()
{
	set("coor",({-100,4600,10}));
	set("short", "��ʯ�ٵ�");
	set("long",
"����һ������ʵ����ʯ���̳ɵĴ����·�ϳ���ĺۼ��Ѿ���·��������һ�������Եİ�\n"
"�ۡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"sroad0",

]));
	set("outdoors", "ny");
//         set("objects", ([
//                 __DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
