 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽׯ����");
        set("long", @LONG
���������Ŵ��ĵ�̺��ǽ�ϵ���һʮ��֧ͨ���ţ�;��򡣴����ľ�ͷ������
�źܴ�ġ�ϲ���֣���ɫ���֣��ʺ�ĳ񡣺��Ǽ���ģ�������ϲ����
LONG       );
        set("exits", ([ 
                "south" : __DIR__"yuanvillage",
                "west": __DIR__"yuanvillage3",
               "east": __DIR__"yuanvillage3",
                //"north": __DIR__"yuanvillage3",
        ]));
        set("objects", ([
                __DIR__"npc/yuanqiuyun": 1,
                __DIR__"npc/liudonglai": 1,
        ]) );
set("coor/x",-1090);
        set("coor/y",200);
        set("coor/z",0);

        setup();
        replace_program(ROOM);
}   
