 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�����������ͻȻ����������ֻ�����ĵ��������˸�ţ�
�ݽ�һ��ͭ�������С�����ͭ���ձ��ǡ���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"gulou2",
  "east" : __DIR__"dianjiao",
  "south" : __DIR__"yewest",
]));
        set("objects", ([
                __DIR__"obj/tong" : 1,
       ]) );
        set("coor/x",-220);
        set("coor/y",200);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}       
