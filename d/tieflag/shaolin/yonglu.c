 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�·");
        set("long", @LONG
���߱߿����ģ���֪�����Ѿ��ߵ��˱��־�ͷ��ǰ����������֮��һ
������--������·���˿�ʼ˳�׶��ϣ�����ʯ�ݱ㵽�����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yingbi",
  "north" : __DIR__"tianwang",
  "northeast" : __DIR__"yeeast",
  "northwest" : __DIR__"yewest",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}  
