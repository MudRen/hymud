// ���������ھ��� /d/city/chuzhou/biaoju2.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"�����ھ�"NOR);
    set("long", @LONG
�����ھֵ���Ժԭ���ǶѷŻ���ͳ����ģ�������Ϊ����û��ʲô���������
���Ծ͸Ķѷ������ˡ�Ҳ��������֮�á�һλ׳����һλ������������ǽ�϶�һ
���㿴��������������ӡ�
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou" );
    set("detail", ([
        "����"  : "����������һ�Σ�����������\n",
        "paizi" : "����������һ�Σ�����������\n",
        "sign"  : "����������һ�Σ�����������\n",
    ]));        
    set("exits", ([
        "north"  : __DIR__"biaoju",
        ]));
    set("objects", ([
        __DIR__"npc/lin_tianhao"     :   1,
        __DIR__"npc/lin_tianxiong"   :   1,
    ]));        
    setup();
}
