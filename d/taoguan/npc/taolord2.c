 // taolord.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int marriage();
int leave();
void create()
{
    set_name( "������" , ({ "master ding", "master" }) );
    set("nickname",HIB "��հ���" NOR);
    set("gender", "Ů��");
    set("age", 46);
    set("long",
        "�������Ƕ��˷��ʦ�ã�Ҳ�Ƕ��˷�������á�����������ʱ�������������\n"
        "�����������������ɱ�˰�����󵽴˳��ҡ�\n"); 
    set("combat_exp", 10000000);
    set("score", 200000);
    set("reward_npc", 1);
        set("difficulty", 35); 
    set("class", "taoist"); 
    set("str", 20);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("force", 2000);
    set("max_neili", 1000);
    set("force_factor", 30); 
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
    set("inquiry", ([
        "�����ķ�": 
        "�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
        "���幬": 
        "�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n",
         "leave" : (: leave :),
        ]) ); 
    set("apprentice_available", 3);
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "drainerbolt" :),
        (: cast_spell, "invocation" :),
            }) ); 
    create_family("���幬", 6, "Ů����");
    set("rank_nogen",1);
    set("ranks",({"����","��ͯ","����","ɢ��","�ɹ�",YEL"��Ů"NOR,YEL"������"NOR,
                      HIY"����"NOR})); 
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
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 20); 
    setup(); 
    carry_object(__DIR__"obj/sword2")->wield();
    carry_object(__DIR__"obj/robe2")->wear();
    carry_object(__DIR__"obj/hat2")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
} 

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
    add("apprentice_availavble", -1);
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
        id_class=victim->query("gender");
        id=victim->query("id");
        if(id_class == "Ů��"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n��Цһ����ƶ������õľ�����ѹŮ��֮ͽ��\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy())  player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
   if (this_player()->query("class")!="taoist") return 0;
        message_vision(CYN"$N���������������Ų��⴫���������˿ɲ�Ҫ��ڡ�\n"NOR, this_object(),this_player());
        return 1;
}  
int marriage () {
        if (this_player()->query("once_menpai/sanqing")){
                message_vision(CYN"$N�����������ˣ��������޵���ĪҪ��Ů�鳤��\n"NOR,this_object());
                message_vision(CYN"$N�ֵ�������ִ��Ϊ��Ҫ��ɽ��Ҳ������ǿ��ֻ������һ������ͷ���ѣ��мǣ�\n"NOR, this_object());
                this_player()->delete("once_sanqing");
                return 1;
        }
        return 0;
}  
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/ɱ������", 1);
        }
        
        ::die(); 

}
