 // mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����");
    set("long", @LONG
����һ�����ŵĳ����ã�����һ���������������������ǰ����
�����ƣ����˵������ڷ���������ʦ�⣬��Ϊ���ﹱ�����ࡣ��ϧ���Ӣ�ţ�
�����ҳ���ȥ����һ�ں�����а�ʹ������������ǰϲ���Ļ�ɽ�ɹ����ڣ�Ϊ
������һ�������ã�������һ����λ�����������ڵ������೤��Ϊ��һ
���˽��̾���ϣ��������֮��úð�Ϣ��
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"yard",  
//                "north" : __DIR__"songgu",
        ]));

set("item_desc", ([
                "sign": @TEXT
                ֿ
                ��

                ��             
                ��
��              
��              ��
��              ��
��              λ
��
TEXT
        ]) );
//        set("no_fight",1);
        set("no_magic",1);
        set("NONPC", 1);
    set("indoors", "huangshan");
        set("coor/x",-648);
    set("coor/y",-545);
        set("coor/z",30);
        setup();
     

} 
