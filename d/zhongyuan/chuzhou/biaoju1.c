// ���������ھֱ� /d/city/chuzhou/biaoju1.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"�����ھ�"NOR);
    set("long", @LONG
���ǳ��������ھֵı�Ժ����Χ��һ����שƽ������������ͷһ�ҵ�ס����
Ժ������Ȼ�����أ�����ɨ�úܸɾ���Ժ����Ĵ����£�����С���Ͱ�ʡ�����
�ڷ��ſ����ӡ�һλ׳���������㡣
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
        "south"  : __DIR__"biaoju",
        ]));
    set("objects", ([
        __DIR__"npc/lin_tianbao" :   1,
    ]));        
    setup();
}
