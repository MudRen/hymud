 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("ʯ����", ({ "shi guanyin","guanyin" }) );
    set("nickname", HIG"������פ"NOR );
    set("gender", "Ů��" );
    set("age", 25);
    set("int", 30);
    set("str",60);
    set("per", 30);
    set("agi",100);
    set("apprentice_available", 50);
    set("ranks",({"����","Сħ","��ħ","��ħ","��ħ","����","Ԫ��","������"}));
    set("rank_nogen",1);
    set("fly_target",1);
    set("long",
        "ʯ�����������������ǽ��˲�������ģ���Ϊ����������ȫ��ռ����
���ǵ����������кܶ��˶����á�������������Ů�ӵ����������ǹ�����
������˫�۾������������ᡣ�кܶ��˶����á���ɽ����������Ů��ü��
�������������ʵĴ�ɽҲ��������ü����Լ��
"
        );
    set("force_factor", 400);
    set("chat_chance", 1);
    set("chat_msg", ({
        "ʯ������������......�㲻�����ϣ���\n",
            "ʯ����Ц��Ц���ֵ��������֪��������ʲô�ط�����\n",
            "ʯ�����۹�ͻȻ���ʣ��������������֪����Ϊ�λ�����������\n",
               }) );
       set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
	set("agi",25);
        set("int",30);
        set("combat_exp", 99999999);
        set_skill("unarmed", 100);
        set_skill("blade", 350);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.taixubaihuan" :),
                (: perform_action, "unarmed.yaozhan" :),
        }) );
        set("pubmaster",1);
	set_skill("kongshoudao", 500);
	set_skill("bat-blade", 530);
	set_skill("ghosty-force", 500);
	set_skill("ghosty-steps", 500);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "bat-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "bat-blade");
        map_skill("dodge", "ghosty-steps");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
    set("combat_exp", 99999999);
    set("inquiry", ([
        "�޻�" : (: kill_him :),
        "�����" : (: kill_him :),
        "���" : (: kill_him :),
        "���ʮ����" : (: kill_him :),
        "�Ϲ���" : (: kill_him :), 
        ]));
    
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
        add("apprentice_availavble", -1);
}  
int kill_him()
{
        object me;
        me = this_player();
        command("say �������Ѿ�֪���ҵ������ˣ��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int accept_object(object who, object ob)
{
   	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
	{
	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}
        if(ob->query("name")!="���ʳ���") return 0;
        if(!who->query("���_quest3"))
        {
                message_vision("ʯ����������ü������ѵ����������ġ�������\n",who);
                return 0;
        }
        message_vision("ʯ������������������������Σ���ɫ��ò�ͣ���ƺ���������ࡣ����\n",who);
        call_out("give_saki",5,who);
        return 1;
} 
int give_saki(object who)
{
        object saki;
                
        if(environment(who)!=environment()) return 0;
    message_vision(HIY"ʯ����ͻȻ��ȻһЦ����һҹ���ް��ն����������ͷ���λ"+ RANK_D->query_respect(who) +"����ƿ���
������������ū�ұ��������ˡ�\n"NOR,who);
        saki=new(__DIR__"obj/saki");
        saki->move(who);
        who->set("���_quest4","�ɹ�");
        
        return 1;
}     
int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}