#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����һ��ƽ������������ͨ�������ש���ĺ�Ժ��ס������Ĵ����
�ǿ����ճԷ��ģ��п�С�ӻ��̵ģ����ģ������ģ���ľ�ģ�Ҳ�е��ǳ��걼��
���������ԭ�������ˡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"sroad4",
                "west" : __DIR__"sroad2",
                "south": __DIR__"house5",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
