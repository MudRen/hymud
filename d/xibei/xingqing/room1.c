//room1.c.ƽ����
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","ƽ����");
    set("long",@LONG
������ƽ���������Ǽ��׵Ͱ������ݻ������ݣ�����Χ��ڻԻ͵Ĺ�����
�����ߵĹ���լ���γ������Աȡ����ڵ�ƽ���Դ����ֹ�ҵΪ�����ڼ�ͥ������
����ֹ���Ʒ�������ٸ��͹������̣��Ի�ȡ�������衣����๤�վ�Ʒ���ǳ�
����Щ�������С�
LONG);
   
    set("exits",([
        "north"   : __DIR__"road10",
    ]));  
    set("outdoors","xingqing");
    setup();
}

