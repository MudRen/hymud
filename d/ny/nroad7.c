
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({-150,4800,10}));
	set("short", "ɽ·");
        set("long",
"����һ��˵����˵խ��Ҳ��խ��ɽ·��·���ü���������̦�Ĵ�ʯ�̳ɣ�������һ����\n"
"�أ��������������Ұ��ɽ���м��䷿�ݴ������ּ䣬������һ��Ժǽ�����洫�����ӵ���\n"
"����ɽ·������ͨ��ɽ�꣬ɽ·�����ν�һ����ʯ��·��\n"
);
        set("exits", ([ /* sizeof() == 2 */
      "southeast" : __DIR__"mstreet4",
      "southwest" : __DIR__"txgate",
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
