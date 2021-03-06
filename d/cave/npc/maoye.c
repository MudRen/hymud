#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("毛野", ({"mao ye","mao"}) );
    set("gender", "男性" );
    set("nickname", BLU"奄奄一息"NOR);
    set("title", "青龙会 分舵护法");
    set("long", "毛战的双胞胎兄弟，与高立一战中身受重伤，枪挑一腿，奄奄一息，\n只好躺在这破小床上养伤。\n");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("per", 6);
        set("combat_exp", 2500000);
        set("eff_qi", 1000);
        set("qi",3000);
        set("no_heal",1);
        set("class","bandit");
        
        set("str",36);
        set("force",1000);
        set("max_neili", 1000);
        set("force_factor", 70);
        set("reward_npc", 1);
        set("difficulty", 3);
     set_skill("lamaism", 250);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 380);
        set_skill("sword", 120);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 280);
        set_skill("hand", 280);
        set_skill("cuff", 280);
        set_skill("yujiamu-quan", 380);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 320);
        set_skill("xue-dao", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");


if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
        set("chat_chance", 1);
        set("chat_msg", ({
        "毛野痛苦地在床上挣扎着，嘶叫着：高。。立！我作鬼也要报这断腿之仇！\n",
        "毛野的断腿不停地渗出鲜血，床上都几乎染成红色，令人触目惊心。\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/duanblade")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", random(3));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority")){
            message_vision("$N恨声道：拿命来！大爷送你上西天见高立！\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
   }
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->query_skill("iron-cloth")>200 
                                && this_object()->query_temp("weapon")) {
                                command("say 好硬功!待我的降龙十八掌来会你!");
                                command("unwield all");
                        } else if (enemy[i]->query_skill("iron-cloth")<200)
                                command ("wield blade");
                }
        }
} 
smart_busy() {
        this_object()->perform_action("blade.kuaidao");
}  
