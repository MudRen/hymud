 // taolord.c
inherit NPC;
inherit F_MASTER;

#include <ansi.h> 
void create()
{
    set_name("���˷�", ({ "master ding", "master", "ding chengfeng" }) );
    set("nickname", HIG"�̺��˷�" NOR);
    set("gender", "����");
    set("age", 47);
    set("long","���˷�ԭ�������������ң�����С��ѧ���ó������ķ���\n"
        "���������ڴ˾��޳��ɽ�ħ֮����\n");
    
    set("combat_exp", 10000000);
    set("score", 20000); 
    set("class", "taoist"); 
    set("str", 60);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("reward_npc", 1);
        set("difficulty", 20); 
    set("force", 2000);
    set("max_neili", 1000);
    set("force_factor", 30);
//  set("fly_target",1);
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
        ]) ); 
    set("apprentice_available", 3);
    create_family("���幬", 5, "����");
    set("rank_nogen",1);
    set("ranks",({"��ʿ","С����","����","С��ʦ","��ʦ",YEL"����ʦ"NOR,YEL"������"NOR,
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
    
	setup();
    carry_object(__DIR__"obj/sword")->wield();
    carry_object(__DIR__"obj/robe")->wear();
    carry_object(__DIR__"obj/hat")->wear();
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
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing", "kill");
} 
void greeting(object me)
{
        object ob,*inv, ding;
        
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        
                
        if (me->query("class")=="taoist" 
                && me->query("gender")=="����" && 
                me->query("combat_exp")>1000000)        {
                
                inv = all_inventory(me);
                
                if  ( sizeof(inv) >= 15) 
                        return;
        
                if (present("ding",me)) return;
                
                message_vision(CYN"$N��$n˵���������Ϊʦ���꣬���մ���һ�����������ܹ��ʦ�š���\n"NOR,ob,me);
                ding= new(__DIR__"obj/ding_baby");
                if (me->query("combat_exp")>5000000) {
                        ding->set("name",RED"��ľ����"NOR);
                        ding->set_max_encumbrance(200);
                } else if (me->query("combat_exp")>3000000) {
                   ding->set("name",YEL"��ľ����"NOR);
                        ding->set_max_encumbrance(100);
                } else {
                        ding->set("name",HIC"��ľ����"NOR);
                        ding->set_max_encumbrance(50);
                }
                ding->move(me);
                message_vision("$N�ӻ���ȡ��һ��"+ding->name()+"�ݸ�$n��\n",ob,me);     
                return;
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
        if(id_class == "taoist" && userp(victim)&&player!=victim)
        {
            message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
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
             killer->set_temp("wanma/���˷�_ma", 1);
        }
        
        ::die(); 

}
