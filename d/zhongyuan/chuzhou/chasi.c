// ���ݲ��� /d/city/chuzhou/chasi.c
// by lala, 1997-12-06

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"����"NOR);
    set("long", @LONG
һ���˵�����������ֵط���һ����������Ϣ��ͨ���ĵط�����������
���ָ�����С����Ϣ�������������£�����˭�ҵ�ĸ������˫�Ƶ���������Ϣ��
����һ��ʮ��ʮ���٣��ܿ�����Ǿ�֪�ˡ���ˣ������Ҫ����ʲô��Ϣ�Ļ���
�����ֳ��ϼ����״�����������ֲ��ױ�¶��ݡ�
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"nanshi",
        ]));
    set("objects", ([
        __DIR__"npc/cha_boshi"  :   1,
        __DIR__"npc/chake"      :   1,
    ]));        
    setup();
}
