 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
��˵��������������֮����ʯ��������ϡ�ɼ���������״ǡ�ƾ���������ʯ
������ʯ���֣������پ������������Ʒ�һ���������������ֽ��ڴ˴�������ʯ��
�����б����Խ�ʯ��
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
                set("NONPC",1);

        set("coor/x",-550);
        set("coor/y",-520);
        set("coor/z",10);
        setup();
} 
