// ������ͷ /d/city/chuzhou/matou.c
// by lala, 1997-12-13

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"��ͷ"NOR );
    set("long", @LONG
�����ǳ��ݵ��˺���ͷ������������æ�����ֵĵط�����ʱ�д��СС
�Ŀͻ���ֻ�����������Ļ�������ˡ��ÿ����������´�ֻ������̷��ڳû���
���Լ��Ļ������ʿ��������Ѳ�ߣ�������Ŀ����ⷱæ�ľ����򶫾ͽ���
���ˡ���ͷ��ǽ��Ҳ�����Ű��ģ�����˭Ҳû��վ����������
LONG
    );
    set("exits", ([
        "east"      : __DIR__"xishi",
        ]));
    set("objects", ([
        __DIR__"npc/xiaowei"    :   2,
        __DIR__"npc/shibing1"   :   1,
        __DIR__"npc/shibing2"   :   1,
        __DIR__"npc/kuli"       :   3,
    ]) );

    set( "outdoors", "yangzhou" );       
    set( "no_kill",  "yangzhou" );
    setup();
}
