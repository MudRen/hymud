 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��԰");
        set("long", @LONG
��԰�����֦�Ϲ����˸��ֹ�ʵ�����ƻ��������һ���ķ��⡣��Щ��ľ����
����������õ�װ�����������������ɫ����ʵ����ɫ����͸����ϵ���ɫ����
�������ʵ���ɫ���������͵���ɫ�����е����������Ĺ�ʣ�
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"orchard1",
        ]));
        set("objects", ([ 
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
