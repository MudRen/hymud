 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���������໥���У�����ǡ������֮��岻�ߣ���ľҲ���࣬�ɹ�ʯ������
��룬�ߵ�������������ߣ����Ҳ���ʤ�����������˺�����
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"yuping",
]));
        set("objects", ([
        __DIR__"obj/guai" : 1,
        __DIR__"npc/rabbit" : 2,
                        ]) ); 
        set("outdoors", "huangshan");
        set("coor/x",-570);
        set("coor/y",-530);
        set("coor/z",40);
        setup();
}
