#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"����"NOR);
        set("long", @LONG
��ǽ�����������������ź�������ĵ�̺��ǰ��������Ҳ���ݻ�
���ˣ���������һ�ȣ���ֱ������Ҥ�������ԣ������ţ����Ͻ����飬
�����ͷ׵Ĺ�Ӱ��������������߱����أ����������ϵ��ɾ���
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                "east" : __DIR__"silver2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
