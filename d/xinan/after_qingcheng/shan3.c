//written by lnwm on 97/07/08
//shan3.c

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short","���ɽ��");
    set("long",@LONG
������Զ����Ǻ�ɽ��λ����ظ�ԭ�Զ����Ĵ������������ɽ����֮�У���
��ɽ�����������ʮ����Ҫ���ݴ��кܶ�����ĸ��˾���������Ƭ��嫵�Ⱥɽ֮��
���ڵ��Ƹ��ӣ����೯͢���շ�������Ҳϲ����������ƬȺɽ֮�С��������
ȥ������ȫ��ɽ���������ɱ����·��
LONG);
    set("exits",([
        "east"   	:		__DIR__ "shan2",
		"west"		:		__DIR__ "entershangu",
    ]));
    setup();
}

int valid_leave(object me, string arg)
{
    object *inv;
    int i;

    inv = all_inventory(me);

    for ( i = 0; i < sizeof(inv); i++ )
   	{
        if ( userp(inv[i]) && arg == "east" )
             return notify_fail("ǰ��ɽ·���,��ֻ�������ϱ�����Խ��Խ��,������������.\n");
	}		

	return 1;
}