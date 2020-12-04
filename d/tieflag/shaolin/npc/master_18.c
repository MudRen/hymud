 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("һ��", ({ "master yi", "master"}) );
    set("nickname", HIM "����"NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("reward_npc", 1);
        set("difficulty", 5);
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",60);
//    set("str",20+random(20));
    set("cor",30);
    set("attitude","friendly");
    set("max_neili", 1100);
    set("neili", 1100);
set("jing", 4000);
	set("max_jing", 4000);

	set("qi", 14000);
	set("max_qi", 12000);
	set("neili", 14000);
	set("max_neili", 15000);
	set("jiali", 90);
    set("long","���ֵ�ʮ�˴����ϣ�ר�Ŵ��ڶ��ֽ���书��\n"     );
    create_family("������", 18, "����");
    set("student_title","���");
    set("combat_exp", 1300000);
   set_skill("force", 251);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "ranmu-daofa");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 200);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("yijinjing", 301);
	set_skill("ranmu-daofa", 300);
	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 190);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 190);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 190);
	set_skill("zui-gun", 190);
	set_skill("buddhism", 200);
	map_skill("blade", "ranmu-daofa");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "blade.huo" :),
                (: perform_action, "blade.fenxin" :),
                (: perform_action, "blade.fentian" :),
                            }) );
    setup();
    carry_object(__DIR__"obj/bigdan.c");
    carry_object(__DIR__"obj/monk20_cloth")->wear(); 
	carry_object("/d/shaolin/obj/jgdao")->wield();
} 
void attempt_apprentice(object me)
{
    if((me->query("gender") != "����")||(me-> query("marry"))){
                command("say ���ֲ��շ������ˡ�����\n");
                return;
    }
    if(me->query_temp("won_master_di")){
                command("smile");
        command("recruit " + me->query("id") );
        return;
    } else {
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
    int gin, kee, sen, sgin, skee, ssen;
    if(is_fighting())
    {
        command("say �����ӷ�\n");
        return 0;
    }
    if(me->query("family/family_name") == query("family/family_name"))
        if(( me->query("family/master_id") == query("id")) ||
           me->query_temp("won_master_di")) {
            command("say �ã���Ӯ���ң���Ϳ���ȥ�Ҷ����и������ʦ���ˣ�\n");
        }else if (me->query("class") == "shaolin") {
                command("say �����ӷ�ƶɮ�书��΢��ʩ�����������顣\n");
        } else {
            command("shake");
            return 0;
        }
    else command("say �����ӷ�ƶɮ�书��΢��ʩ�����������顣\n");
    //Recover to full when fight
    gin = (int) query("max_jing");
    kee = (int) query("max_qi");
    sen = (int) query("max_sen");
    sgin = (int) query("eff_jing");
    skee = (int) query("eff_qi");
    ssen = (int) query("eff_sen");
    if(sgin < gin || skee < kee || ssen < sen){
        message_vision("$N��ʣ�µ�"HIR"�󻹵�"NOR"�Ե�ǬǬ������\n"
                       HIR "$N��������һ�������˹���ҩ��������\n"NOR,
                       this_object());
    }
    set("eff_jing",gin);
    set("eff_qi",kee);
    set("eff_sen",sen);
    set("jing", gin);
    set("qi", kee);
    set("sen", sen);
    return 1;
} 
void win_enemy(object loser)
{
    if(loser->query("family/family_name") == query("family/family_name"))
        command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
    else command("say �����ӷ�\n");
} 
void lose_enemy(object winner)
{
    if(winner->query("family/master_id") == query("id")) {
        command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
        winner->set_temp("won_master_yi",1);
        }
    else command("say �����ӷ�\n");
        
} 
void check_answer(object me)
{ 
        if (objectp(me))
        {
                me->delete_temp("inask");
                if (present(me,environment(this_object())))
                {
                        message_vision("$N��ĥ����÷֦����$n̾���������㻹δ������\n",this_object(),me);
                }
        }
} 
int accept_object(object who, object ob)
{
        if (ob->name() == "���ϵ�÷֦"){
                if(who->query("marks/����_��ڳɹ�")) {
                        message_vision("$N����ӹ�÷֦����ϸ�ۿ���һ�������̧ͷ���˿�$n��������ʧ��Ե��\n", 
                                        this_object(), who);
                        message_vision("�����������������㼴�������ĵ��޹ҡ��ҷ�ȱ���\n", this_object());
                        return 1;
                }
                if (who->query("marks/����_��_÷֦") && !who->query("marks/����_��_л����")&& who->query("class")=="shaolin"){
                        message_vision("$N����ӹ�÷֦����ϸ�ۿ���һ�����\n",this_object());
            message_vision("$N���󽣾�������÷֦�ϿڵĽ��Ʊ���һ�н����� \n\n",this_object());
                        message_vision("$nֻ������һ�н�������ƽƽ������Ȼ�����������һ�� 
�紵÷֦����$N����������ͣ�����ݷ�����һ��������𶯡� \n\n",this_object(),who);
                        message_vision("$N�ֳ�÷֦������΢Ц����$n��������������򣿡�(answer yes/no) \n",this_object(),who);
                        add_action("do_answer","answer");
                        who->set_temp("inask",1);
                        call_out("check_answer",120,who);
                } else {
                        message_vision("����÷֦�ĶϿڽ��ۣ�$N�����̧��ͷ���Ե�˵����ƣ��ͱ��ˡ� 
���ҷ�ȱ�����$N̾��������һ����������ֻ�л������������\n ",this_object());
                }
                return 1;
        }
        return 0;
}
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (arg != "yes" && arg != "no")
        {
                return notify_fail("��ֻ�ɴ�yes/no \n");
        }
        if (!me->query_temp("inask"))
        {
                return 0;
        }
        remove_call_out("check_answer");
        me->delete_temp("inask");
        if (arg == "yes")
        {
                message_vision("$n˵�����˽�������ף����ӽ��մ��۽硣�� 
$Nҡҡͷ����������һ��֮ѧ������һ�����˽�Ҳ��ֹ�ڴ��ˡ��� ",this_object(),me); 
        }else
        {
                message_vision("$n˵�����˽����������������޶ۣ���δ�������򡣡� \n $N˫�ƺ�ʮ���̵����������ӷ𣡡�\n\n ",this_object(),me);
                message_vision("$N��$n˵������������ʮ��������Ħ�ã��õľ��Ǵ��С��˽�һ�������� 
��̫ʦ�壬ǰ��Ħ��ס���޸���ʦ��Ȼ��������ɮ�������������ƴ˽��� 
����Ҳ���޴�̸�𡣡�\n\n",this_object(),me);
                message_vision("$N����һ�أ��ֶ�$n˵�������㽣����Ϊ�Ѿ���ѷ��ʦ����֪�˽�֮�в��������Ը 
����������ս��ʮ������ (accept yes/no)\n",this_object(),me );
                add_action("do_accept","accept");
                me->set_temp("inaccept",1);
                call_out("check_accept",120,me);
        }
        return 1;
}
void check_accept(object me)
{
        if (objectp(me))
        {
                me->delete_temp("inaccept");
                if (present(me,environment(this_object())))
                {
                        message_vision("$N��$n̾�������������ǲ�Ը������Ҳ������ǿ����ȥ�ɣ���\n",this_object(),me);
                        me->delete("marks/����_��_÷֦");
                }
        }
}
int do_accept(string arg)
{
        object me,meizhi;
        me = this_player();
        if (arg != "yes" && arg != "no")
        {
                return notify_fail("��ֻ�ɴ�yes/no \n");
        }
        if (!me->query_temp("inaccept"))
        {
                return 0;
        }
        remove_call_out("check_accept");
        me->delete_temp("inaccept");
        if (arg == "yes")
        {
                message_vision("$N��÷֦����$n�������������ݴ���ʮ����ȥ��ɽׯ��սл���壬�� 
����ȥ������������һ���ľ����㻹Ҫ�ӽ����򡣡�\n",this_object(),me );
                meizhi = new("d/shaolin/obj/meizhi");
                meizhi->move(me);
        me->delete("marks/����_��_÷֦");
        me->set("marks/����_��_��ʮ��",1);
        }else
        {
                message_vision("$Nҡҡͷ������˵���� \n",this_object());
                me->delete("marks/����_��_÷֦");
        }
        return 1;
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
