 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
û�뵽�ڶ�����������֮������������֮���Ȼ������㾰ɫ��
�������ɰ���ӳ�£���Ȼ�������һ�Ƿ��ܣ���ȥ��Ȼ��һ��¥��
¥�������������ݴ��������µ�һ���ִ������ֺ�Ϊ����ǧ������
��Ȼ�����Ը������ڶ��֣��Ӵ˲����������ѵ���¥����Ϊ��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zhulin",
]));
        set("objects", ([
                __DIR__"npc/master_xie" : 1,
       ]) );
        set("coor/x",-250);
        set("coor/y",380);
        set("coor/z",70);
        setup();
    //replace_program(ROOM);
}
int invalid_leave(object me)
{
        me->delete_temp("xieask");
        return 0;
}      
