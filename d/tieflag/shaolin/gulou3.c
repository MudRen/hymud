 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�������ϱ��Ǵ��¥���޹ı������档ǽ�ϵıڻ�
�ƺ����汥��������ķ���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"gulou4",
  "down" : __DIR__"gulou2",
]));
        set("objects", ([
                __DIR__"obj/bihua" : 1,
       ]) );
        set("coor/x",-220);
        set("coor/y",200);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
} 
