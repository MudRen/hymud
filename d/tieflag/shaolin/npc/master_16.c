 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("�޻�", ({ "master wu", "master"}) );
    set("nickname", HIM "��ɮ"NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("age", 29);
    set("per", 55);
    set("int",30);
    set("attitude","friendly");
    set("max_neili", 1500);
    set("neili", 1500);
    set("cps",60);
    set("long", " ���°��࣬һ����Ⱦ���������ϵ�΢ЦҲ�г���֮��\n");
    create_family("������", 16, "��ʦ");
    set("reward_npc", 1);
    set("difficulty", 10);   
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.qiankun" :)
            }) );
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"����һ��һ���Ϊ��ʦ��衣����\n",
            name()+"�������������ˣ������Ҿ�˵����Ψһ���ƻ�����ƻ��ľ����㡣\n"
            }) );
   set("jing", 38000);
	set("max_jing", 38000);
	set("qi", 38000);
	set("max_qi", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 90);
	set("age", 80);
	set("shen_type", 1);
	set("shen", 100000);
	set("str", 150);
	set("int", 50);
	set("con", 50);
	set("dex", 150);
	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 150);
	set("combat_exp", 9800000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 300);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

set_skill("weituo-zhang", 380);
set_skill("shaolin-tantui", 380);
set_skill("jingang-zhang", 380);
set_skill("jimie-zhua", 380);
set_skill("duoluoye-zhi", 380);
set_skill("mohe-zhi", 380);
set_skill("boluomi-shou", 380);
	set_skill("banruo-zhang", 380);
	set_skill("cibei-dao", 380);
	set_skill("damo-jian", 380);
	set_skill("fengyun-shou", 380);
	set_skill("fumo-jian", 380);
	set_skill("hunyuan-yiqi", 380);
	set_skill("jingang-quan", 380);
	set_skill("longzhua-gong", 380);
	set_skill("luohan-quan", 380);
	set_skill("nianhua-zhi", 380);
	set_skill("pudu-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 380);
	set_skill("weituo-gun", 380);
	set_skill("wuchang-zhang", 380);
	set_skill("xiuluo-dao", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yijinjing", 380);
	set_skill("yizhi-chan", 380);
	set_skill("zui-gun", 380);
	set_skill("weituo-chu", 380);
	set_skill("ranmu-daofa", 380);
	set_skill("wuying-jian", 380);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );

    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear();
} 
void attempt_apprentice(object me)
{
    command("shake");
    command("say �ҳ����������⣬�㻹��ȥ�ҷ��ɰɡ�\n");
}
void init()
{
    if(this_player()->query_temp("��һ��ˮ"))
        call_out("confess",13+random(3),this_player());
        ::init();
} 
int confess(object me)
{
    me->delete_temp("��һ��ˮ");
    command("say ������ʲô��֪���ˡ�����\n");
    command("say ����������û�ҡ�����\n");
    message_vision("$N˵�գ��ԶϾ����������ĵ��ڵ��ϡ�����\n",this_object());
    if(!me->query("m_success/��ƽ���ַ粨"))
    {
        me->set("m_success/��ƽ���ַ粨",1);
        me->add("score",500);
    }
    this_object()->die();
}  
int accept_object(object who, object ob)
{
        string msg;
        
        if(ob->query("name")!="���ʳ���") return 0;
        if (who->query("���_quest2")=="�ɹ�")
        {
                msg=HIG"�޻��ٺ���Ц���������Ϲ���Ǽһﶼ������˭�����Һ���ĸ�׵İ�ҵ��
����������Ҳ��������\n"NOR;
                who->set("���_quest3","�ɹ�");
        }
        else
                msg=HIM"�޻�ü���������Цһ����������������Ϲ�һͬ�ϻ�Ȫ�ɡ���\n"NOR;
        message_vision(msg,who);
        kill_ob(who);
        return 0;
}       
