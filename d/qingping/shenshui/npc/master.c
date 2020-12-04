 //XXDER
inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h>
void create()
{
    set_name("��ˮ����", ({ "master shenshui", "master", "shenshui" }) );
    set("nickname", HIB"ˮĸ����"NOR);
    set("gender", "Ů��");
    set("class", "shenshui");
    set("age", 33);
    set("long",
        "һλ���ϴ�����ɳ����Ů�����ڵ����ϣ�����Ȼ�������������ݣ�ȴ���Ըо�����"
        "�Ǿ��ѵ����ʺ;���Ͷ���ĳ�����ϡ�\n");
    set("attitude", "peaceful");
    set("class", "shenshui");
    set("apprentice_available", 2);
    
    create_family("��ˮ��", 11, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��Ů","��Ů","����Ů","��",MAG"�ɼ�"NOR,HIM"ʥ��"NOR,
                      HIR"������"NOR}));
    set("reward_npc", 1);
        set("difficulty", 30);
    set("inquiry", ([
        "leave" : (: leave :),
                ]));  
        
    set("int", 28);
    set("spi", 26);
    set("per", 30);
    set("cps", 30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu"  :),
  //      (: perform_action, "unarmed.suicidal" :),
            }) );
  set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
    set("force_factor", 60); 
    set("combat_exp", 25000000);
    set("score", random(90000)); 
    set_skill("unarmed", 150);
    set_skill("sword", 150);
    set_skill("force", 180);
    set_skill("parry", 140);
    set_skill("dodge", 140);
    set_skill("literate", 140);
    set_skill("move",200);
set("pubmaster",1);

        set_temp("apply/defense", 100);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
    set_skill("nine-moon-steps", 580);
    set_skill("nine-moon-claw", 500);
    set_skill("nine-moon-force", 550);
    set_skill("nine-moon-sword", 500); 
    map_skill("dodge", "nine-moon-steps");
    map_skill("unarmed", "nine-moon-claw");
    map_skill("force", "nine-moon-force");
    map_skill("sword", "nine-moon-sword");  

    setup();
    carry_object(__DIR__"obj/ghostyboots")->wear();
    carry_object(__DIR__"obj/ghostycloth")->wear();
    carry_object(__DIR__"obj/ghostygirth")->wear();
    carry_object(__DIR__"obj/ghostyribbon")->wear();
} 
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
} 

void init()
{
	object ob;
        ::init();
        add_action("do_killing", "kill");
                if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",3 , ob);
        }
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="shenshui") return 0;
        message_vision(CYN"$N��Ц��һ����\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����߿��ԣ����Ӵ˲����ڽ�����ʹ�þ����񹦡�\n"NOR,this_object(),this_player());
        return 1;
} 
void punish_betray(object ob)
{
        if( ( ob->query("once_shenshui")) && ( (ob->query("class"))!= "shenshui"))
          {      
                tell_object(ob, YEL"\nˮĸ����������Ц���������Ȼ�г����ţ��Ͳ������б��ŵ��书����\n"NOR);              
                message("vision", "ˮĸ������"+ ob->name() +"��Ц������"+ ob->name() + "�� ���Ȼ�г����ţ��Ͳ������б��ŵ��书��\n", environment(ob), ob);
           tell_object(ob, HIW"ˮĸ������һ�һ֧ţë��ϸС�ķ�����������̨��\n"NOR);              
                message("vision", HIW"ˮĸ��������"+ ob->name() +"��һ����һ֧ţë��ϸС�ķ��룡\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("nine-moon-claw",1)) ob->delete_skill("nine-moon-claw");
                if (ob->query_skill("nine-moon-force",1)) ob->delete_skill("nine-moon-force");
                if (ob->query_skill("nine-moon-steps",1)) ob->delete_skill("nine-moon-steps");
                if (ob->query_skill("nine-moon-sword",1)) ob->delete_skill("nine-moon-sword");
                tell_object(ob, HIR"��ֻ��Ѫ��һ���������书ȫʧ����\n"NOR);
                ob->start_busy(10);
                ob->delete("once_shenshui");
  
          }
} 

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


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

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
