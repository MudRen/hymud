 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ڣ�ʯ�����ݣ�����������񹤣���ǰ����������ź�Ϊ��
�������ഫ����ɽɽ������������֮�죬����������֮��һ�죬����
�������ػ�һ���������ֹ���������������ã�������Ŀ��������ɫ��
���������Ϸ���������������ɫ�ֱ�����������������������ɫ�ֱ�����
����һ���Ҷ 
                        ���µ�һ��ͥ 
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yonglu",
  "north" : __DIR__"dianjiao",
]));
        set("objects", ([
                __DIR__"obj/jin" : 1,
                __DIR__"obj/tian" : 1,
                __DIR__"npc/master_23" : 1,
       ]) );
        set("valid_startroom", 1);
        set("coor/x",-210);
        set("coor/y",190);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}      
