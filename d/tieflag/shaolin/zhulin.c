 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һƬ���֣���������ɽ�磬��Ҷ�����֮��ǡ��˿��֮����������
Ƣ���������ң�����ȴ�����쳣��һ����ȥ����Ȼ��������ͷ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"diyuan",
  "west" : __DIR__"yinshi",
]));
    set("outdoors", "shaolinfy");
        set("coor/x",-240);
        set("coor/y",380);
        set("coor/z",70);
        set("objects", ([
                __DIR__"npc/yan13" : 1,
       ]) );
        setup();
//    replace_program(ROOM);
} 
int invalid_leave(object me)
{
        me->delete_temp("yan13ask");
        return 0;
}         
