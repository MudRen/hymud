//written by lnwm on 97/07/08
//qingcheng_shan1.c

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short","���ɽ��´");
    set("long",@LONG
�����������ɽ�Ĳ�´������ɽ�����ܣ���ľ���죬��������ܻص����ĵ�
�Ĵ���أ����������������ص�����ɽ�ͺͷ��ܵ����֡���Щɽ�ͽ�һֱ������
������ظ�ԭ��
LONG);
    set("exits",([
        "east"   	:		"/d/xinan/qingcheng_shan",
		"west"		:		__DIR__ "qingcheng_shan2",
    ]));
    setup();
}

