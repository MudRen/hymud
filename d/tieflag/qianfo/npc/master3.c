 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("�����ʦ", ({"master ding", "master", "ding" }) ); 
    set("gender", "����");
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3);
//  set("str", 40);
    set("reward_npc", 1);
        set("difficulty", 5);
    set("int", 30);
    set("spi", 30);
    set("con", 30);
    set("spi", 30);
    set("con", 30);
    set("cps", 30);
    set("cor", 20);
    set("atman", 300);
    set("max_atman", 300);
    set("neili", 800);
    set("max_neili", 800);
    set("force_factor", 5);
    set("mana", 300);
    set("max_mana", 300);
    set("combat_exp", 1200000);
    set("score", 9000);
    set_skill("unarmed", 100);
    set_skill("force", 100);
    set_skill("dodge", 100);
        set_skill("unarmed", 200);
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
 
    create_family("�˹�����", 4, "��ʦ");
    set("rank_nogen",1);
    set("student_title","�׼ҵ���");
    setup();
    carry_object(__DIR__"obj/staff")->wield();
    carry_object("/clone/misc/cloth")->wear();
}  
void attempt_apprentice(object ob)
{
              
    if (ob->query("once_menpai/bonze")&& ob->query("class")!="bonze") {
                command("shake");
                command("say ʩ�������޳���û�����֮�ġ�\n");
                return;
        }
    if(ob->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), ob);
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
    ob->set("class","bonze");
    command("say �����ӷ����գ����գ�");
    command("recruit " + ob->query("id") );
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
int leave() {
        if (this_player()->query("class")!="bonze") return 0;
        message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����ŵ���ͨ�����ķ��ǵ��Ӳ���ʹ�á�\n"NOR,this_object(),this_player());
        return 1;
}  
