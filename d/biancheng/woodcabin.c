 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ּ�С��");
        set("long", @LONG
������ܼ��ӣ��ܸɾ���ѩ�׵�ǽ�ϣ�����һ�����񡣻��ò����õ�����ȴ
�ܴ���һ������΢�롢Ŀ�⾼������������ˣ�΢΢��������վ��һƬ�����⣬
���ӱ�ͦ��������һ�˱�ǹһ�㡣��������һ���϶н��ۣ����ϵ�˿���ϣ�����һ
��������ڵĵ�������ǰ�������㰸����ľ�������ϣ�д�ŵ��ǣ������״���֮��
λ��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"woods2",
        ]));
        set("objects", ([
                __DIR__"npc/zhaodafang":        1,
                __DIR__"npc/yidajing":  1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
