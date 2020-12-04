//written by lnwm on 97/07/08
//shan2.c

#include <ansi.h>

inherit ROOM;

int do_jiefei( object ppl );

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
        "east"   	:		__DIR__ "shan1",
	"west"		:		__DIR__ "shan3",
    ]));
    setup();
}

void init()
{
    if (userp(this_player()))
    {
        do_jiefei(this_player());
    }
}

int valid_leave(object me, string arg)
{
	if ( objectp( present("jie fei",environment(me))))
	{
		return notify_fail(RED"�ٷ���ס�����ȥ·\n"NOR);
	}
	return 1;
}

int do_jiefei( object ppl )
{
	object jiefei;
	int i;	

	tell_object(ppl,CYN"\n\n���Ȼ�о���Χ�Ĳݴ���Щ����������ͣ���˽Ų���\n"NOR);
	tell_object(ppl,RED"\n\nͻȻ�Ӳݴ������������ٷˡ�\n"NOR);

    //�޲���������һ��ʬ�壬��ɵ�����bug.
    foreach( object ob in all_inventory(this_object()) )
    {
        if ( !ob->is_character() || ob->is_corpse() )
            destruct(ob);
    }
	
	if(  (int) ppl->query("combat_exp") <= 100000 )
	{
		tell_object(ppl,RED"\n�ٷ˼��½��㿳���ڵء�\n"NOR);
		tell_object(ppl,CYN"\n�ٷ�����ض���˵����ƾ����㴳�����ĵ���Ҳ�����ɽ��Ұ��\n"NOR);
		ppl->unconcious();
        ppl->move( __DIR__ "shan1" );

        foreach( object ob in all_inventory(this_object()))
        {
            if (!userp(ob))
            {
                ob->move(__DIR__"jiefei_wo");
            }
        }
	}	
	else
	{
		if ( present ("jie fei") ) 
            return 1;
		for( i = 0; i < 5; i++ )
		{
			jiefei = new(__DIR__ "npc/jiefei");
			jiefei->move(this_object());
		}	
	}
	return 1;
}
