 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
    set_name("�λ���ʦ", ({ "master can", "master", "can" }) ); 
    set("gender", "����");
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3);
    set("reward_npc", 1);
    set("difficulty", 5);
    set("int", 30);
    set("spi", 30);
    set("con", 30); 
    set("fly_target",1);
    set("atman", 300);
    set("max_atman", 300);
    set("neili", 1000);
    set("max_neili", 1000);
    set("force_factor", 5);
    set("mana", 300);
    set("max_mana", 300); 
    set("combat_exp", 1000000);
    set("score", 9000); 
    set("inquiry", ([
        "���" : (: ask_for_join :),
        "����" : (: ask_for_join :),
        "apprentice" : (: ask_for_join :),
        ]) ); 
    set_skill("staff", 120);
     set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("dodge", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 300);
	set_skill("buddhism", 300);
        set_skill("jin-gang", 350);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);         
    
    
    create_family("�˹�����", 4, "ס��"); 
    setup(); 
    carry_object(__DIR__"obj/staff")->wield();
    carry_object("/clone/misc/cloth")->wear(); 
}  
string ask_for_join()
{
    object me; 
    me = this_player();
            if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
                command("shake");
                command("say ʩ�������޳���û�����֮�ġ�\n");
                return (string)me;
        }
   if(me->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), me);
                return (string)me;
        }       
    if( (string)me->query("class")=="bonze" )
        return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
    if( (string)me->query("gender") != "����" )
        return "�����ӷ�Ůʩ�����������������㵽����ȥ��Ȱɡ�\n"; 
    me->set_temp("pending/join_bonze", 1);
    return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n"
        ;
} 
int do_kneel()
{
    string *prename =
        ({ "��", "��", "Բ", "��", "��", "��",
           "��", "��", "��", "��" });
    string name, new_name; 
    if( !this_player()->query_temp("pending/join_bonze") ) return 0;
    message_vision(
        HIC "$N˫�ֺ�ʮ�����������ع���������\n\n"
        "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ���������£�\n\n"NOR,
        this_player(), this_object() );
    name = this_player()->query("name");
    new_name = prename[random(sizeof(prename))] + name[0..1];
    command("say �ӽ�������ķ�������" + new_name + "��");
    command("smile");
    this_player()->delete_temp("pending/join_bonze");
    this_player()->set("name", new_name);
    this_player()->set("class", "bonze"); 
    return 1;
} 
void attempt_apprentice(object ob)
{
    if(ob->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), ob);
                return;
     }
    if (ob->query("once_menpai/bonze")) {
                command("shake");
                command("say ʩ�������޳���û�����֮�ġ�\n");
                return;
        }
    
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ���ɽ����Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
    }
} 
void do_recruit(object ob)
{
    if( (string)ob->query("gender") != "����" )
        command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
    else if( (string)ob->query("class") != "bonze" )
        command("say �����ӷ�ʩ��Ը����ţ����ȵ�С����ȳ��ҡ�");
    else {
        command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id") );
    }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) ) {
        add("apprentice_availavble", -1);
        return 1;
    }
} 
int accept_fight(object me)
{
    if( (string)me->query("class")=="bonze" )
        command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
    else
        command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�"); 
    return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
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
        if(id_class == "bonze"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ��������ӷ�,����������������ȴҲ���������꣬ʩ�����ˣ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}   
