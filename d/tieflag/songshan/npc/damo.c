 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name("��Ħ�����", ({ "damo", "master", "print", "damo print" }) );
    set("gender", "����");
    set("age", 99);
    set("long", "һ����Ħ�����̬�������������ƣ���Լ�ɼ�������һ����ɫ��ˮī���� ��\n");
    set("attitude", "peaceful");
    set("reward_npc", 1);
    set("difficulty", 40);
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("no_busy", 99);
    set("neili", 80000);
    set("max_neili", 80000);
    set("force_factor", 1000);
    set("combat_exp", 10000000);
    set("score", 200000);
    
    set("class", "shaolin");
    
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
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("������", 1, "��Ħʦ��");
        set("ranks",({"��ɮ",YEL"��ɮ"NOR,YEL"ʥɮ"NOR,HIY"����"NOR}));
    set("rank_levels",({230000,3200000,5187000,26244000}));
    setup();
}
int accept_fight(object me){
    return 0;
}
void attempt_apprentice(object me)
{
        if(me->query("class")=="shaolin"&&me->query("marks/����_��ڳɹ�")&&me->query("once_xman")<1)
                command("recruit " + me->query("id") );
} 
void recruit_apprentice(object ob){
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
} 
void init(){
    add_action("do_look","look");
} 
int do_look(string arg){
    object me;
    me = this_player();
    if (arg == "print" || arg == "damo" || arg =="master" || arg == "damo print"){
                if(me->query("marks/����_��ڳɹ�")) {
           message("vision", me->name() + "������˼�Ķ�����ǰ��ʯ�ڡ�\n", environment(me), me);
                tell_object(me, CYN"һ����Ħ�����̬�������������ƣ���Լ�ɼ�������һ����ɫ��ˮī����\n"NOR);
                return 1;
        } else {
                tell_object(me, "�����ɵ�һƬʯ�ڣ���ʲôҲ����������\n");
                return 1;
        }
    }
    return 0;
}       
