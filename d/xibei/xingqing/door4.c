//xihua_men.c.������
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"������"NOR);
    set("long",@LONG
�������츮�����ţ��򶫵Ĵ�·ֱͨ���츮���Ĺ㳡���������Ǩ�������
Ǵ�ٳﻮ��Ӫ�������ǳأ��������ڹ������̳�����츮�Ѿ߹�ģ��������
�������Ͼ��������. ���ſ�������������ʱ�����˾����������ھ������츮��
������Ԫ껹��ͳ����¡�
   �����⿴��Զ���Ƿ����ص��ĺ���ɽ��
LONG);
    set("exits",([
        "east"      : __DIR__"road19",
        "southwest" : __DIR__"xing7",
///        "northwest" : "/d/zuzhi/yipin_tang/xuanwu_tang/x_x7",
    ]));
    set("objects", ([
          __DIR__"npc/bing1" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

