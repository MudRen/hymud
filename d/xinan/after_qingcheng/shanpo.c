//writen by lnwm on 97/07/14
//shanpo.c
//д����ط����������ˣ����ء���������������������

#include <ansi.h>
#include <skill.h>

inherit ROOM;


void create()
{
    set("short", "Сɽ��");
    set("long", @LONG
�����ɽ�꣬��ǰ������һ��СС��ɽ�£�ɽ�±���Ⱥɽ��������������ɽ��
����һ��СС��é�ݡ���ϸϸ������һ��һ��Χ���ıڣ���é���̶�����ª��ʮ��
�ɾ����ࡣé��������СС�Ĳ��飬�������࿪������СС�Ĵ�����
LONG
        );
    set("exits", ([ 
        "south"     :       __DIR__ "gudi",
        "enter"     :       __DIR__ "maowu",
    ]));
    set("outdoors","lnwm");
    setup();
}

