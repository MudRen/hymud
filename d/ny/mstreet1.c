
// Room: /d/snow/mstreet1.c

inherit ROOM;

void create()
{
        set("coor",({-20,4770,10}));
	set("short", "��Զ�Ƕ���");
        set("long",
"��������������Զ�ǵĽֵ��ϣ���������һ����ֱ����Զ��֡����������Ľֵ������Ǹ�ʽ\n"
"�����ĵ��̣�������ֻ�����������У����Ǹ���ʮ�߼����Ĺ㳡�����������൱���֡�����\n"
"������һ���Ʒ��������Զ��������ּ����ѿ�������ʲ���֡�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mstreet2",
  "southeast" : __DIR__"square",
]));
        set("objects", ([
                __DIR__"npc/drunk" : 1, ]) );
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
