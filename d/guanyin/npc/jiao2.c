 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        
        object armor;
        set_name("焦劳", ({ "jiao lao" }) );
        set("gender", "男性");
        set("age", 45);
        set("title",WHT"海天双煞"NOR);
        set("nickname","天废");
        set("long",
"此人头颅、身躯，都是特别地大，两手两腿，却又细又短，像个六、七岁的小儿。\n"
);
          
        set("attitude", "friendly");
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",3);
        set("class","lama");
        set("no_busy",4);
        set("combat_exp", 3000000);        
        set("int", 30);
        set("cps", 60);
        set("spi", 30);
        set("cor",40);
        set("str",36);
        
        set("iron-cloth",150);
        set("force", 1000);
        set("max_neili",1000);
        set("force_factor", 80);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        

        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",70);
             
     		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        armor=new("/clone/misc/cloth");
        armor->set_name(WHT"天废衫"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
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
        if( id == "jiao hua" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$N笑道：对手厉害，咱兄弟俩一块儿上。\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
} 
