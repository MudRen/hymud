 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����С��");
        set("long", @LONG
���������֣����۵��������Ƴγε�С�����Ƶ�������ÿһ�����붼���Զ�
������˸�ź���͸���������ɫ�ʣ�����״����ɫ���ɱ����������ҫ�ñ�ĸ��Ѥ
�á���ɼͦ���ţ�֦Ȩ�������������һ���γ���һ�º���ǽ�ڣ�����һ֧��
��һ�µľ��ӡ�
LONG
        );
        set("exits", ([ 
                "eastup" : __DIR__"road1a",
                "westdown": __DIR__"road1c",
        ]));
        /*set("objects", ([ 
                
        ]) );*/
        set("outdoors", "eren");
set("coor/x",-1050);
        set("coor/y",160);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}   
