//written by lnwm on 97/07/08
//shan1.c

#include <ansi.h>

inherit ROOM;

void do_jiefei( object who );

void create()
{
    set("short","���ɽ��");
    set("long",@LONG
������Զ����Ǻ�ɽ��λ����ظ�ԭ�Զ����Ĵ������������ɽ����֮�У���
��ɽ�����������ʮ����Ҫ���ݴ��кܶ�����ĸ��˾���������Ƭ��嫵�Ⱥɽ֮��
���ڵ��Ƹ��ӣ���೯͢���շ�������Ҳϲ����������ƬȺɽ֮�С��������
ȥ������ȫ��ɽ���������ɱ����·��
LONG);
    set("exits",([
        "east"   	:		__DIR__ "qingcheng_shan3",
		"west"		:		__DIR__ "shan2",
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
        if ( userp(inv[i]) && arg == "west" )
             return notify_fail("ǰ��ɽ·���,��ֻ�������ϱ�����Խ��Խ��,������������.\n");
	}		

	return 1;
}


