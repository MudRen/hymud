// cooker.c
// by Find.

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С����", ({ "cooker" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "�����Ǹ�����¥�ĳ��ӡ�\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);

	set("inquiry",([
	"�ɻ�" : CYN + "С����˵�������⵹��Щϴ(xi)��ϴ���ӵĻ��\n" + NOR,
	"����" : CYN + "С����˵�������⵹��Щϴ(xi)��ϴ���ӵĻ��\n" + NOR,
	"work" : CYN + "С����˵�������⵹��Щϴ(xi)��ϴ���ӵĻ��\n" + NOR,
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_work",({"wash","xi"}));
}

int do_work(string arg)
{
	object me = this_player();
	int time;

	if( arg != "plate"
	&& arg != "bowl"
	&& arg != "����"
	&& arg != "��")
		return notify_fail(sprintf(CYN "%s�ɻ�Ŀ�����һ�ۣ�����Ҫ��ʲô����\n" NOR,name()));

	if(me->query_temp("changan_work"))
		return notify_fail("����Ļû�и����أ��Ȼ����˵�ɡ�\n");

	time = time();

	if(time - me->query("changan_work") < 30)
		return notify_fail(sprintf(CYN "%s˵������ô������Ҳ��ȥ�ɵ������ˣ��Ȼ�������ɡ�\n" NOR,name()));
	if(me->query("age") > 22)
		me->set("changan_work",time);

	// Ӧ�ÿ��ԣ������ò���Ǯ�� by Find.
	if(me->query("jing") <= 0
	|| me->query("qi") <= 0
	)
		return notify_fail(sprintf(CYN"%sҡҡͷ˵������������ɫ���ƣ��������������ⲻ���á���\n"NOR,
	name()));

	if(arg == "plate")
		arg = "����";
	else if(arg == "bowl")
		arg = "��";

	message_vision(sprintf("$N%s������һ��%s�ܵ�����ϴ��������\n",
	( mapp(me->query_temp("armor"))
	&& !sizeof(keys(me->query_temp("armor"))) )?
	"��������":"��������",arg),me);

	me->start_busy(3);
	me->set_temp("changan_work",1);
	call_out("finish_work",3,me,arg);
	return 1;
}

void finish_work(object me,string what)
{
	object ob;
	int flag = 0,kee,gin;

	if( ((gin = me->query("jing")) < 20)
	|| ((kee = me->query("qi")) < 20) )
	{
		tell_object(me,what+"��ûϴ������Ѿ��۵ò����ˡ�\n");
		flag = 1;
	}

	me->receive_damage("qi",20);
	me->receive_damage("jing",20);
	me->delete_temp("changan_work");

	if(flag)
		return;

	tell_object(me,sprintf("�����˸���ͷ�������%sϴ���ˡ�\n",what));

	if(!living(me) || environment(me) != environment())
		return;

	ob = new(SILVER_OB);
	if(!ob->move(me))
	{
		flag = 1;
		ob->move(environment());
	}
	else
		flag = 0;

	message_vision(sprintf(CYN"$N��$n���ͷ˵������������Ĺ�Ǯ��\n"NOR,
	(flag)?"������ŵ����ˡ�":"��"),this_object(),me);
	return;
}
