#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ԭʼ����");
        set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest7",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest",
                "west" : __DIR__"forest6",
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1180);
        set("coor/y",-50);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        set("exits", ([
                "north" : __DIR__"forest7",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest",
                "west" : __DIR__"forest6",
        ]));
} 
