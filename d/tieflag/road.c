 // road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
���￿�������ɽǧ�𶴣���������ɽ��ɽ�µıؾ�֮·��
��·����һƬСС���֣�һ��ʯ��������ʯ�ʡ�һ��С���ڴ�
��������������Ϊ��¡��
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"road0",
  "west" : __DIR__"qianfo/tanghuai",
]));
        set("objects", ([
               __DIR__"npc/xiaofan" : 1, 
       ]) );
        set("outdoors", "tieflag");
        set("coor/x",40);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
