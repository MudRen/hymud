 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ݳ�");
        set("long", @LONG
ĺ�����£��򻶲ݳ��������������÷����Ĳݳ���ǡ��һ����ɫ�������Ƕ��
�ޱ��޼ʵĻ�ԭ֮�С����ԭ�ϣ���������һƬ���裬����Բԣ�Ұãã���紵��
�ͼ�ţ�򡣡�û��ţ��ֻ������Ⱥ�������±��ۣ���ؼ�����������Ļ�����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"grassland4",
                "north":  __DIR__"grassland6",
                "east" : __DIR__"grassland7",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1090);
        set("coor/y",270);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
