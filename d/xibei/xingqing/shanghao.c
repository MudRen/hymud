//shanghao.c.�̺�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",MAG"�̺�"NOR);
    set("long",@LONG
�������йٷ����ֹ�������ҲһЩƽ����ĵ��̣���Ӫ������Ʒ�ȣ�����
Ϊ���䡣����̺ſ����������ֺ��ˣ���ӪһЩ�������ز�������������һЩ��
������Ķ��������û�С������������ﾭ����һЩϡ����Ʒ��
LONG);
   
    set("exits",([
        "east"    : __DIR__"road6",
    ])); 
    set("objects", ([
          __DIR__"npc/dianzhu" : 1,
    ]) );
    setup();
}

