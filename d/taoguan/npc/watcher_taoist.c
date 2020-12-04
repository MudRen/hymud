 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("���羰�ĵ���", ({ "wandering taoist" }) );
        set("gender", "Ů��");
        set("age", 32);
        set("long",
"һ���пɶ��ĵ��ã���һ���ɫ�ĵ��ۣ��������յ��ں��Ͽ��羰��\n"
);
        set("combat_exp", 21000);
        set("score", 200);
        set("class", "taoist");
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����": 
"�ڹ����ƾ��ˣ�����ɢɢ�ģ�������Ǹ��õط�����\n",
        ]) );

        create_family("���幬", 7, "����"); 
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
        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25); 
        setup(); 
        add_money("coin", 10);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear(); 
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N����$n�ȵ����ѵó���ɢɢ�ģ���Ȼ������С�ӻ�������!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
