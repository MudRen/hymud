
// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("coor",({-100,4750,10}));
	set("short", "��Ժ");
	set("long",
"������һ�������Ժ����Ȼ���ӿ��������Ͼ��ˣ����Ǵ�ɨ�ú����࣬ǽ���Ϲ���һ��ɽ\n"
"ˮ�����⾳��Ϊ���ף���Ժ�Ĵ��ſ��ڱ��ߣ�������һ��ľ��ͨ�����ᡣ\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"mstreet4",
]));

	set("objects", ([
		__DIR__"npc/teacher": 1 ]) );
	setup();
}
void init()
{
    if(this_player())
        this_player()->set_explore("north#20");
}
