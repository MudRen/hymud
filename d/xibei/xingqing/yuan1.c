//yuan1.c.��˼Ժ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��˼Ժ"NOR);
    set("long",@LONG
����ר������������װ���;������ʵĹٸ��ֹ�ҵ������ֱ��Ϊ���ӷ���
����ƽ�����ҵ�Ҳ�ܻ�Ծ������˼Ժ��ר�����������Ϭ����ȸ߼�����
Ʒ, ���Ĺ����Ǿ��������ﶨ���������ߣ�����ÿ�껹�ɳ��������ֳ����ռ���
��ԭ�ϡ�
LONG);
   
    set("exits",([
        "west"    : __DIR__"road3",
    ])); 
    set("objects", ([
          __DIR__"npc/guan1" : 1,
    ]) );
    setup();
}

