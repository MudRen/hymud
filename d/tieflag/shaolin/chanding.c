 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ҵ����Ȼ��ͬ����һ˿����������ɮ������ϥ���У������
Ϊ�������徲��Ϊ����ѧһ����;ͬ�飬�����ڹ��������ɷ𷨶�����
����������������ڹ��������°빦����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jialan",
]));
        set("objects", ([
                __DIR__"npc/monk20a" : 1,
                __DIR__"npc/monk20" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",330);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}   
