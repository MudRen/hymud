#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("����",({"zhu yun","zhu"}));
        set("long","�������ᣬ����ͷ��üë���ѿ�ʼ���䣬����Ҳϸ����˿��\n");
        set("nickname", BLU"�������"NOR);
        set("gender","����");
        
        set("no_arrest",1);
        set("no_heal",1);
        
        set("age",22);
        set("int",22);
        set("str",40);
        set("cor",30);
        set("per",30);
        set("cps",20);
        set("jing",3000);
        set("max_jing",2500);
        set("eff_jing",2500);
        set("jing",2500);
        
        set("max_qi",5000);
        set("eff_qi",2500);
        set("qi",2500);  
        
        set("max_jing",2500);
        set("jing",2500);    
        set("eff_jing",2500);
        
        set("combat_exp",3000000);  
        set_temp("apply/damage",200);
        set_temp("apply/armor",200);
        
      	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );

        
        set("force",10000);
        set("max_neili",10000);
        set("force_factor",100);
        
        set("attitude", "friendly");
        
        set("chat_chance",1);     
        set("chat_msg",({
        "��������üͷ�������Ҹ�����Ӣ�ţ����ž��ޣ�����������ɽ��˻��Ҳ��������ǡ�����\n",
        }) );
        setup();
    if (!random(5)) add_money("thousand-cash", 1);
    carry_object(__DIR__"obj/whitecloth")->wear();
    if (!random(10)) carry_object(__DIR__"obj/zhuguo");
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int greeting(object ob)
{
 if (random(100)>20 )
        {
        if(NATURE_D->get_current_day_phase() == 1080) 
                {
                       if (present("zhuguo",this_object()))
                       {
                                                   message_vision(HIR"$NͻȻ���ҵؿ���������\n$N̾�˿����������ǳ�ҩ��ʱ���ˡ�\n\n"NOR,this_object(),ob);
                                                   command("eat zhuguo");
                                              return 1; 
                       }
                                                
                }
                else 
                {
                        command("sigh");
                        say ("����̧ͷ������һ�ۣ��̲�ס�ֿ���������\n");
                        return 1;
                }
        }
        else
                return 0;
}
       
