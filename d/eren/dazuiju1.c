 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����");
        set("long", @LONG
���Ǽ���ͨ��ũ��С�ݣ���ǽ�Ͽ��ż���ũ�ߣ��ſ����ŷ�����ɫ�Ķ�������
������ŤŤ��д�ţ���������㲻�����㣬��õغû��ǼҺá������������Ǹ���
�ӣ�������Ÿ�ͻͻð���Ĵ�������ﲻ֪����ʲô����Զ�����ŵ���ζ��
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"groad2",
        "east" : __DIR__"dazuiju2",
        ]));
        set("objects", ([
                __DIR__"obj/guo": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("guo", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
                item = new(__DIR__"obj/meat");
                item->move(con);
        }
} 
