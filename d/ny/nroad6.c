
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({0,4600,10}));
	set("short", "ɽ·");
        set("long",
"����һ��˵����˵խ��Ҳ��խ��ɽ·��·���ü���������̦�Ĵ�ʯ�̳ɣ�������һ�λ�\n"
"��С�������������ͨ����Զ�ǣ�����ͨ���Ӫ������ɲ���һ���˿���ȥ�ĵط���������\n"
"�Ѿ�����ԼԼ������ʿ�����ڲ����Ľк����ˡ�\n"
);
        set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"nroad3",
      "south" : "/d/cloud/nroad",
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
