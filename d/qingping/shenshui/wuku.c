 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��ˮ���ڽ���Ů�ӣ��书���أ���������Ҳ�صض�����רΪŮ�Ӵ��죬ʹ
�������������ޱȣ���̬������ڳ����ż��ű����ܣ����浶��ǹ������ָ
����Ӧ�о��У�������ھ�Ȼ����һ���廨�룬��֪���к��ô�����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yaofang",
]));
        set("coor/x",190);
        set("coor/y",12345);
        set("coor/z",-10);
        set("objects", ([
        __DIR__"npc/needlegirl" : 1,
                        ]) );
        setup();
        replace_program(ROOM);
}     
