 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ľ��");
        set("long", @LONG
���Ӹǵúܵͣ�����һ���־Ϳ�������������ǽ�ϵķ����Ѱ��䣬��������һ
�Źط��ӹ۴����ľ��ͼ��һ������ӵ��μҸ��ԣ���һ����д��Ȱ���ģ���д��
��Ȼ�ܹ���������ֻ��һ�ȴ��ӣ�һ���ţ����Ϲ����Ѿ���ϴ�÷��׵�����������
LONG
        );
        set("exits", ([ 
        "east": __DIR__"smallroad2",
        ]));
        set("objects", ([
                __DIR__"npc/singer": 1,
        ]) );
        set("coor/x",-1160);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
