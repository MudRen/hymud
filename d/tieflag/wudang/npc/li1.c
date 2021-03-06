 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack(); 
void create()
{
        set_name("李治华", ({ "li zhihua" }) );
        set("gender", "男性");
        set("age", 25);
        set("title",HIY"真武门人"NOR);
        set("nickname",HIG"绵绵不绝"NOR);
        set("long",
"一个英俊的少年，身着白衣，迎风而立，手里一柄长剑，分量不轻。
相传李氏兄妹是真武大帝的关门弟子，一手太极剑法当世无敌，所欠只
是火候而已。双剑合璧，曾困死了点苍派第七代掌门人天南剑容。曾有
人向西门吹雪请教破李氏兄妹剑阵之法，西门苦思三日，答曰：以武技
论，此阵无懈可击，唯有凭无上真力才能破阵而出。\n\n"
);
          
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty",1);
        set("class","wudang");
        
        set("combat_exp", 1600000);        
        set("int", 30);
        set("cps", 60);
        set("spi", 30);
        set("fle",50);
        set("per",40);
        set("str",40);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
          
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 70);
        
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
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        set_max_encumbrance(800000);
        setup(); 
        carry_object(__DIR__"obj/heavysword")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
void init()
{
        object ob;
        ::init();
        add_action("do_killing","kill");
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen; 
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li ehua" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$N喝道：强敌来犯,联手御敌,布两仪剑阵！\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}  
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("zombie-bolt");
                   return;
                }               
        }
        who->smart_attack();
        return;
} 
smart_attack() {
        if (this_object()->query_temp("weapon"))
                this_object()->perform_action("sword.chanzijue");       
                else this_object()->perform_action("unarmed.nianzijue");        
        return;
        }
