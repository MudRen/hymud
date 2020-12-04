 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void smart_fight();
int leave();
void create()
{
    set_name("�˹���ʦ", ({ "master xing", "master", "xing" }) ); 
    set("gender", "����");
    set("nickname", HIY "���ޱ�"NOR);
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3); 
    set("resistance/kee",30);
    set("resistance/sen",30);   
    set("resistance/gin",30);
    
    set("int", 30);
    set("spi", 30);
    set("con", 30);
    set("cps", 30);
    set("cor", 50);
    set("agi",25); 
   
    set("fly_target",1);
    set("atman", 1000);
    set("max_atman", 1000);
    set("neili", 1200);
    set("max_neili", 1200);
    set("force_factor", 90);
    set("mana", 2000);
    set("max_mana", 2000);
     
    set("combat_exp", 8000000); 
    set_temp("apply/armor", 280);
    set_temp("apply/damage", 200);
    set("score", 9000); 
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
    set("inquiry", ([
        "leave" : (: leave :),
                ]));
    create_family("�˹�����", 3, "ס��");
    set("rank_nogen",1);
    set("ranks",({"ɮ��","��ʦ","�޺�","���","��ɮ",YEL"��ɮ"NOR,YEL"ʥɮ"NOR,HIY"����"NOR})); 
    setup();
    carry_object(__DIR__"obj/buddha_staff")->wield();
    carry_object("/clone/misc/cloth")->wear(); 
} 
void attempt_apprentice(object ob)
{
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
    if (ob->query("once_menpai/bonze") && ob->query("class")!="bonze") {
                command("shake");
                command("say ʩ�������޳���û�����֮�ġ�\n");
                return;
        }
    if(ob->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), ob);
                return;
        }
    if( (string)ob->query("gender") != "����" )
        command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
    else if(ob->query_temp("marks/ye")){
        ob->set("class","bonze");
        command("say ���ڰ��Ƴ����ķ��ϣ��Ҿ�����Ϊͽ�ɣ�");
        command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
    }
    else if(ob->query_temp("marks/lady")){
        ob->set("class","bonze");
        command("say �����㲻��������������Ϊ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�");
        command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
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
int leave() {
        if (this_player()->query("class")!="bonze") return 0;
        message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����ŵ���ͨ�����ķ��ǵ��Ӳ���ʹ�á�\n"NOR,this_object(),this_player());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
        who->perform_action("staff.longxianyuye"); 
        return;
}        
