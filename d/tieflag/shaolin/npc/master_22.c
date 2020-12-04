 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
int kill_him();
int jian(); 
void create()
{
    set_name("Բ��", ({ "master yuan", "master"}) );
    set("nickname", HIG "ãΪ" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("reward_npc", 1);
        set("difficulty", 1);
    
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cor",20);
    set("str",30);
    set("cps",80);
    set("attitude","friendly");
    set("max_neili", 500);
    set("neili", 500);
    set("long","���ֵڶ�ʮ������ʦ������ר�Ŵ��ڶ����׼ҵ����书��\n");
    create_family("������", 22, "����");
    set("student_title","�׼ҵ���");
        
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "staff.hequhecong" :),
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    set("combat_exp", 500000);
    set_skill("move", 90);
    set_skill("dodge", 90);
    set_skill("force", 90);
    set_skill("literate", 120);
    set_skill("unarmed",90);
    set_skill("shaolin-shenfa",90);
    set_skill("jingang-quan",90);
    set_skill("yizhi-chan",110);
    set_skill("damo-jian",90);
    set_skill("hunyuan-yiqi",90);
    set_skill("staff",90);
    set_skill("parry",90);
    set_skill("pudu-zhang",90);
    set_skill("blade", 90);
    set_skill("xiuluo-dao",90);
    set_skill("tiexue-hammer",90);
    set_skill("hammer",90);
    map_skill("hammer","tiexue-hammer");
    map_skill("blade", "xiuluo-dao");
    map_skill("staff","pudu-zhang");
    map_skill("parry","pudu-zhang");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("force", "yijinjing");
    map_skill("unarmed", "jingang-quan");
    set("inquiry", ([
                "������": (: jian()  :),
                "master": (: jian()  :),
        ]) );
    setup();
    carry_object(__DIR__"obj/monk22_cloth")->wear();
    carry_object(__DIR__"obj/staff")->wield(); 
} 
void attempt_apprentice(object me)
{
    if(me->query_temp("won_master_kong"))
    {
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
int accept_fight(object me)
{
        if((me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id")) || 
        me->query_temp("won_master_kong"))
        {
        if (me->query("combat_exp")<150000) {
                command("say ͽ����ѧ�䲻�ܺø���Զ����\n");    
                return 0;
                }
        command("say �ã���Ӯ���ң���Ϳ���ȥ�Ҷ����и������ʦ���ˣ�\n");
        return 1;
        }
        else
        {
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
        }
}
void win_enemy(object loser)
{
    command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
} 
void lose_enemy(object winner)
{
    command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
    winner->set_temp("won_master_yuan",1);
} 
void init() {
        ::init();
        add_action("do_killing", "kill");
        add_action("do_answer","answer");
}  
int jian() {
        object me;
        me=this_player();
        command("say �������....��....����ʲô���𣿣�answer��");
        me->set_temp("shaolin/ask_yuan",1);
        return 1;
} 
int do_answer(string arg)
{
        if(arg == "��Ҫ��" || arg =="emergency") {
                if (!this_player()->query_temp("shaolin/ask_yuan")) {
                        command("say ��Ҫ�£�ʩ�����ڸ�ƶɮ˵��ô��");
                        return 1;
                }
                command("say �ã�������Ժ�򱱣���ȥ�ɣ�\n");
                this_player()->delete_temp("shaolin/ask_yuan");         
                this_player()->set_temp("see_fangzhang",1);
                return 1;
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
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ��������ӷ�,�����徲֮��,�������ɱ��?ʩ����ˡ���ĵ����ˣ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}      
