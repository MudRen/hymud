 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
����һ��ʯ���ŷ�������ʯ�ź󣬱��ǻ�ɽ����ʯ����ȥ��ֻ�������䣬�� 
��һƬ���̡�Ⱥ���������嶥�������ƣ����ɴ��ӭ������������·����һС 
������������Ъ�š� 
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan",  
  "north" : __DIR__"jiusi",  
		"southwest" : "/d/henshan/hsroad2",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
"quest/skills2/wakuang/kuang/kuangmai" : 2,
                        ]) );
        set("outdoors", "huangshan");
        set("coor/x",-510);
        set("coor/y",-510);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
