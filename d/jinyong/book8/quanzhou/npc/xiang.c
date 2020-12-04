// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();
int ask_me();

void create()
{
	set_name("������", ({ "xiang wentian", "xiang"}));
	set("nickname", HIR "��������" NOR );
	set("gender", "����");
	set("title", "������̹�����ʹ");
	set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
	set("age", 45);
	set("shen_type", -1);
	
	set("str", 21);
	set("per", 28);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);
	set("inquiry", ([
		"����ͤ"     : "�����ˣ���ɱ��\n",
		"��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
		"ɱ��������" : (: ask_kill() :),
		"������"     : (: ask_me() :),
	]));
	set("qi", 14000);
	set("max_qi", 14000);
	set("jing", 21000);
	set("max_jing", 21000);
	set("neili", 23500);
	set("max_neili", 23500);
	set("jiali", 350);
	
	set("combat_exp", 6500000);
	set("score", 0);
	
	set_skill("force", 310);
	set_skill("hunyuan-yiqi", 310);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 310);
	set_skill("finger", 310);
	set_skill("strike", 310);
	set_skill("hand", 310);
	set_skill("claw", 310);
	set_skill("parry", 310);
	set_skill("nianhua-zhi", 310);
	set_skill("sanhua-zhang", 310);
	set_skill("fengyun-shou", 310);
	set_skill("longzhua-gong", 310);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 200);
	set_temp("apply/attack", 200);
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
	create_family("�������", 2, "������ʹ");
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_kill()
{
	object ob,me = this_player();
	
	command("tell "+this_player()->query("id")+" ��Ҫȥɱ�������ܣ�\n");
	message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����\n" NOR,this_player());
	ob=new("/d/heimuya/npc/obj/card4");
	ob->move(me);
	tell_object(me,"������ӻ�������һ����������������ϡ�\n");
	return 1;
}

int ask_me()
{
	int i;
	object ob = this_object();
	object me = this_player();

  	if(((int)me->query("jinyong/book8")>=6))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),me);
		return 1;	
	}
	if(objectp(present("dizi", environment(me))))
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(me) +"�����ȴ�����Ⱥ�߹��ɣ�\n",this_object(),me);
		return 1;
	}	
	
	if((int)me->query("jinyong/book8")==5) {
		message_vision(HIC "$N��$n˵����������������ʮ�ꡣ\n" NOR,ob,me);
		message_vision(HIC "�ֽ��Ҳ������������÷ׯ��������ȥ��ȡ�\n" NOR,ob,me);
		i = random(1600);
		me->set("jinyong/book8",6);
		me->add("combat_exp",i+18000);
		me->add("potential",i*14);
		me->add("mpgx",10);
		me->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (me,"��Ӯ����"+chinese_number(i+18000)+"�㾭��"+
		           chinese_number(i*14)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		me->save();
	call_out("leavet",1);
		return 1;
	}
	message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(me) +"�����ǻ���һ��ƷƷ�裬���������ɣ�\n",this_object(),me);
	return 1;
}

void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}
