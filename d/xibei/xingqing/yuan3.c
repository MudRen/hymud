//yuan3.c.��Ժ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��Ժ"NOR);
    set("long",@LONG
����ר������������װ���;������ʵĹٸ��ֹ�ҵ������ֱ��Ϊ���ӷ���
����ƽ�����ҵ�Ҳ�ܻ�Ծ������Ժ��������Ʊ���������, ��˵��Ҫ����
�ˣ�������æ���Ȼ��졣Ժ�����һ������ǹ��һ�Ѷѿ��ף�һ����������ָ
��ʿ����㣬���ˡ�
LONG);
   
    set("exits",([
        "west"    : __DIR__"road2",
    ])); 
    set("objects", ([
          __DIR__"npc/guan3" : 1,
    ]) );
    setup();
}

