//written by lnwm on 97/07/08
//qingcheng_shan3.c

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
        "east"   	:		__DIR__ "qingcheng_shan2",
		"west"		:		__DIR__ "shan1",
    ]));
    set("objects",([
         __DIR__"npc/caiyao" : 1
    ]));
	setup();
}

int welcome_visitor( object ob )
{
		tell_object(ob,HIM"\n��ҩ�˿�����һ�ۣ�ָ��ǰ��˵��\n"NOR);
	tell_object(ob,HIM"ǰ����ǿ�˳�û���͹�����һ�仰���Ͻ���ͷ����ǰ���ˣ�\n\n"NOR);
	return 1;
}

