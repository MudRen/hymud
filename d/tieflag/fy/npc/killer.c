 // zombie.c
#include <ansi.h> 
inherit NPC; 
void do_bite(); 
void create()
{
        set_name("��ò��ͨ��İ����", ({ "figure" }) );
        set("long",
"����ֵ�ɱ�֡�ʲô������ɾ�ֻ�������ģ�ר������ɱ�ˡ�\n");
        set("attitude", "heroism");
        set("str", 100);
        set("agi", 300);
        set("hired_killer", 1);
set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
        setup();
        carry_object(__DIR__"obj/killerpai");
        carry_object(__DIR__"obj/killersword")->wield();
} 
void init()
{
        remove_call_out("hunting");
        call_out("hunting",1);
}
void  hunting()
{
        object  hirer, targ;
        string  target;
                hirer = this_object()->query("possessed");
                target = query("haunttar");
                if(objectp(targ = present(target, environment()))
                && !this_object()->is_fighting() && living(targ)){
                        if( targ == this_object()) return;
                        if(userp(targ) && (int)targ->query("combat_exp") < 2000)
                                {
                                        if( hirer)
                                   message_vision("$Nָ��$n˵�������־�����ɫ�����ң��ټ���\n",this_object(),targ);
                                        set_leader(0);
                                        call_out("destkiller",1);
                                        return ;
                                
                                }
                        message_vision(HIR "$N��$n��ȵ������˻����������������������վ�����ļɳ����ϵ�ù�ɣ�\n"NOR,this_object(), targ);
                        this_object()->kill_ob(targ);
                        this_object()->set_leader(targ);
                        targ->kill_ob(this_object());
                }
                else{
                        if( !this_object()->is_fighting() && hirer ) this_object()->set_leader(hirer);
                }                       
        return ;
}
int accept_fight(object me)
{
        return 0;
} 
void destkiller()
{
destruct(this_object());
return ;
}    
