//door2.c.��޹��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��޹��"NOR);
    set("long",@LONG
�������츮�����ţ��򱱵Ĵ�·ֱͨ���츮���Ĺ㳡���������Ǩ�������
Ǵ�ٳﻮ��Ӫ�������ǳأ��������ڹ������̳�����츮�Ѿ߹�ģ��������
�������Ͼ��������. ���ſ�������������ʱ�����˾����������ھ������츮��
�����ҵ��������ƽ��, �ڽ����ʹ��������Ĺٷ�������
LONG);
    set("exits",([
        "north"   : __DIR__"road20",
    ]));
    set("objects", ([
          __DIR__"npc/bing1" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

