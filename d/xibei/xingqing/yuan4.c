//yuan4.c.��֯Ժ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��֯Ժ"NOR);
    set("long",@LONG
����ר������������װ���;������ʵĹٸ��ֹ�ҵ������ֱ��Ϊ���ӷ���
����ƽ�����ҵ�Ҳ�ܻ�Ծ������֯Ժ��������������õ�ëձ, ��������ë
ձ�԰�ձ��Ϊ�������ھ�˵��Ҫ���̣����й�������æ�ھ�������������Ͼ��
��ëձ�ˡ�
LONG);
   
    set("exits",([
        "east"    : __DIR__"road2",
    ]));
    set("objects", ([
          __DIR__"npc/guan4" : 1,
    ]) );
    setup();
}

