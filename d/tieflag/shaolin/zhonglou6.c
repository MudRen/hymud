 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
��������һ��ͤ�����ܿյ����ģ�������һ�ڣ���һ��һǧ����ڽ�
����̫����䣬���ذ˴����������ԣ�һ�����죬ֱ�Ӿ������쳹���ۡ�
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"zhonglou5",
]));
        set("objects", ([
                __DIR__"obj/bigzhong" : 1,
                __DIR__"npc/monk5_sentry" : 2,
       ]) );
        set("coor/x",-190);
        set("coor/y",200);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}      
