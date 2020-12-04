#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_ANA;



int halt_breaking(object me);
int continue_breaking(object me);

void create()
{
	int i = random(sizeof(meridians));
	string meri = "m"+ (string)(i+1);
	mapping meridian = meridians[i];
	
	set_name(HIY"��Ѩͭ��"NOR, ({ "chongxue tongren", "tong ren" }));
	set_weight(50);

	set("unit", "��");
	set("long",HIG"����һ��ȫ��������������ľ���Ѩ����ͭ�ˣ�"
				"����������й�·���ƺ����Դ�ͨ"+meridian["mer"]+"(canwu)��\n"NOR);
	set("value", 500000);
	set("no_put",1);
	//set("no_give",1);
	//set("no_get",1);
	set("material", "iron");
	set("mer",meri);
}

void init()
{
	add_action("do_chongxue",({"canwu"}));
}

int do_chongxue(string arg)
{
	object me = this_player();	
	string meri;
	seteuid(getuid());	
	if(!id(arg)) return notify_fail("��Ҫ��ʲô����ͨ����Ѩ����\n");
	
	meri = query("mer");
  
	 //return notify_fail("��Ҫ��"+meri+"ʲô����ͨ����Ѩ����\n");
	return chongxue(me,meri);
}

int continue_breaking(object me)
{
	mapping meridian = get_meridian(me->query_temp("meri"));
	mapping *anamichis = get_anamichis(me->query_temp("meri"));
	mapping anamichi = anamichis[(int)me->query_temp("anami")];
	
	me->start_busy(60);
	tell_object(me, HIR "\n������չ������Դ�ͨ"+meridian["meri"]+HIR"��"+anamichi["ana"]+NOR"��\n"NOR);
	return 1;
}

private void stop_breaking(object me)
{
        if (! interactive(me))
        {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
        }
}

int halt_breaking(object me)
{
	tell_object(me, "����ֹ�˱չء�\n");
	message_vision(HIY "$N" HIY "����̾��һ�����������������ۡ�\n\n" NOR, me);
	me->set_temp("biguan", 0);
	return 1;
}

private void user_quit(object me)
{
        if (! me || interactive(me))
                return;
      
        me->force_me("quit");
}

int query_autoload() { return 1; }
