
// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
        set("coor",({-100,4800,10}));
	set("short", "��������");
        set("long",
"������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬���ӵĽ���������˸�ʽ����\n"
"�����Ʒ��δ���Ʒ�����ǳ�ͷ�����������ӡ������ȣ����������������õ��������졣\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet4",
]));

        set("objects", ([
                __DIR__"npc/blacksmith": 1 ]) );
        setup();
        replace_program(ROOM);
}
