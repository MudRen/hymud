//door5.c.������ɽ��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"������ɽ��"NOR);
    set("long",@LONG
������������������Ժ��ʼ����������ʥԪ�꣬�������깤. һ�����ֱ
ͨ��Զ��, ��ǰ��ɽ�š�ɽ���ú���ɼľ�Ƴɣ������ͭ�������޴��ͭ����
ɽ�����Ϸ�����һ�������ң�����д��<<������>> �������֣���ʼ��Ԫ���
�⡣�����������Ļʼ���Ժ�����������ξ�ǰ��Ѳ�ߡ�
LONG);
   
    set("exits",([
        "north"   : __DIR__"road27",
        "south"   : __DIR__"qiandian1",
    ]));
    set("outdoors","xingqing");
    setup();
}

