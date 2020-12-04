 inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h> 
void create()
{
    set_name("����", ({ "master tieshao", "master","tieshao" }) );
    set("gender", "����" );
    set("nickname", HIG "���鵶��"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("cor",55);
    set("str",100);
    set("ill_boss",5);
    set("class","legend");      
    set("apprentice_available", 50);
    create_family("��ѩɽׯ", 1, "ׯ��");
    set("rank_nogen",1);
    set("ranks",({"��ͯ","С��","����","����","����",WHT"����"NOR,WHT"��ʥ"NOR,HIW"����"NOR}));
    set("long",
        "���ٴ�ʮ���꿪ʼ�ͺͰ���ѩ����������������˵����ϱڣ�\n"
        "�����޵С���������������ʢ֮ʱ���ֺ�Ȼ�˳������������ڴˡ�\n"
        );
    set("inquiry", ([
        "leave" : (: leave :),
                ]));
    set("force_factor", 150);
    set("max_atman", 300);
    set("atman", 300);
    set("max_neili", 1500);
    set("force", 1500);
    set("max_mana", 300);
    set("mana", 300);
    set("fly_target",1);
    set("combat_exp", 39999999);
    set("score", 90000);
      set("qi", 99000);
    set("max_qi", 99000);
    set("jing", 98000);
    set("max_jing", 98000);
    set("neili", 93500);
    set("max_neili", 93500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 350);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("meihua-shou", 500);
	set_skill("shortsong-blade", 530);
	set_skill("qidaoforce", 550);
	set_skill("fall-steps", 500);

	map_skill("unarmed", "meihua-shou");
        map_skill("blade", "shortsong-blade");
        map_skill("force", "qidaoforce");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "blade.duangechangmeng" :),
        }) );

set("pubmaster",1);
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/mblade")->wield();
}  

int accept_fight(object me)
{
    object xiaocui;
    if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    {   
        command("smile");
        command("say ������С�����ɡ�");
        return 0;
    }
    else
        command("sigh");
    command("���������ĴӴ������վ���������������е���ɰ����");
    command("wield wangblade");
    command("say �룡");
    call_out("do_unwie", 3);
    return 1;
}
int do_unwie()
{
    if( !this_object()->is_fighting())
    {
//      command("unwield wangblade");
        message_vision("$N����豭ǳ�һ�ڣ���������������ѩ���һ�ۣ�����������ϡ�\n", this_object());
        command("smile");
        return 1;
    }
    else
        call_out("do_unwie", 3);
} 
void init()
{       
        object me;
        add_action("do_killing", "kill");
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        if( interactive(me = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",5 , me);
        }
        if (me->query_temp("marks/tie_ask") && !me->query("marks/��ɽ����")) {
                message_vision(HIY"$N�ʣ��ҽ���������ô���ˣ�\n"NOR,this_object());
                return;
                }
        if (me->query("combat_exp")>3200000 && me->query("class")=="legend" 
                && !me->query("marks/��ɽѧ��") && !me->query("marks/��ɽ����") 
                && !me->query_temp("marks/tie_ask")&&userp(me)) {
                remove_call_out("greeting");
                add_action("do_accept", "accept");
                me->set_temp("tie_in_ask",1);
                call_out("greeting", 1, me);
    }
            
} 
int greeting(object me)
{
    message_vision(HIY"\n$N����$nһ��˵�����������ѧ��ҵ���гɣ�������һ���������㡣��accept yes/no��\n" NOR, this_object(), me);
    return 1;
}  
int do_accept(string arg)
{
        string name;
        if (!this_player()->query_temp("tie_in_ask"))
                return notify_fail("ʲô��\n");
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("��Ҫ����ʲô��\n");
        if( arg == "yes") {
                this_player()->set_temp("marks/tie_ask",1);
                message_vision(CYN "$N˵��������ǰС��·����ɽ����������ɮ��ɽ�����ƣ��������˼����������ˡ�\n"NOR,this_object());
                message_vision(CYN"��˵�⼸��ɮ�˺ų�[�������]���������š�\n"NOR,this_object());
                message_vision(CYN"$N˵�����Ҵ�Ϊʦ��һ�ˣ������Ǹϻ�����ȥ��\n"NOR,this_object());
        }
        else 
                command("sigh");
        this_player()->delete_temp("tie_in_ask");
        return 1;
} 
int accept_object(object who, object ob)
{
        object gletter;
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if(ob->query("money_id") )
{	if(who->query_skill("unarmed",1)<30)
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
        if(!who->query("marks/��ɮ1") || !who->query("marks/��ɮ2") ||!who->query("marks/��ɮ3")) return 0; 
        if( ob->query("id")!="yellow bead" ) return 0;
        message_vision(CYN"$N��Ц�����ã��ã���ͽ�ܣ���\n"NOR,this_object());
        who->set("marks/��ѩ����",1);
        message_vision(CYN"$N˵��Ϊʦ���ڰ�����ľ���������(heal)�����㡣\n",this_object());
        message_vision(CYN"$N˵:Ϊʦ����һ�£���ɽӵ��ɽׯ��ׯ����Ϊʦ������ѣ���������Ҵ�������\n"NOR,this_object());
        message_vision(CYN"ѩ�������һЦ˵��������������ʺá�\n"NOR,this_object());
        who->set("marks/��ɽ����",1);
        gletter = new(__DIR__"obj/gletter");
        gletter ->move(this_player());
        return 1;
} 
int do_killing(string arg)
{
    object player, victim, weapon;
    string name, id, id_class;
    if(!arg) return 0;
    player = this_player();
    if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
    {
        name = victim->name();
        if( name == "ѩ���")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N����Ƥ�����г��һ��ɱ�����˵����µ��������С�\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "����")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N����Ƥ�����г��һ��ɱ�����˵����µ��������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "legend"&& userp(victim)&&player!=victim)
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N����Ƥ�����г��һ��ɱ�����˵����µ��������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
               
        return 0;
    }
    return 0;           
}  
int leave() {
        if (this_player()->query("class")!="legend") return 0;
        message_vision(CYN"$N�����˸���־���Ҳ���ǿ�����¡�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵��ֻ�Ǿ����ķ��ǵ��Ӳ���ʹ�ã��̸赶���ľ�������Ҳ��᲻���ˡ�\n"NOR,this_object(),this_player());
        return 1;
}     
void punish_betray(object me)
{
        if( ( me->query("tiexue_once")==1) && ( (me->query("class"))!= "legend"))
          {      
                tell_object(me, YEL"\n���ٿ������Ȼһ��:�������ˣ�����һ�����֣����ѱ��Ҷ�ȥ��������ѧ�Ͳ��������ˣ���\n"NOR);                  
                message("vision", YEL"���ٶ�"+ me->name() +"̾������"+ me->name() + "�� ���ȱ�������,�����书��\n"NOR, environment(me), me);
                tell_object(me, HIW"ѩ���һ��ָ�������������ߴ�Ѩ����\n"NOR);              
                message("vision", HIW"ѩ���һ��ָ�����"+ me->name() +"�������ߴ�Ѩ����\n"NOR, environment(me), me);
              if (me->query_skill("dormancy",1)>100) me->delete_skill("dormancy");
              if ( me->query("max_neili")<650 )
              	  me->set("max_neili",0);
              else
              me->add("max_neili",-650);
//              me->add("max_qi",-650);    �����,����650��������ֹ��650����Ѫ
                tell_object(me, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                me->set("tiexue_once",2);
                me->unconcious();
          }
}  


int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
