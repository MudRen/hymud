#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("西门玉", ({"ximen yu","ximen"}) );
        set("gender", "男性" );
        set("nickname", HIC"七月十五"NOR);
        set("title", "青龙会 分舵舵主");
        set("long", "一张很斯文，很和气，白白净净的脸，胡子修饰得干净而整齐。背负着
双手，施施然地踱着方步，不但脸带着微笑，眼睛也是笑眯眯地。他看
来就像是个特地来拜访朋友的秀才。\n");
        set("attitude", "friendly");
        set("class","beggar");
        set("age", 45);
        set("cor", 25);
        set("str",36);
        set("cps", 25);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("ill_boss",5);
        set("combat_exp", 4000000);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set("force", 3000);
        set("max_neili", 3000);
        set("force_factor", 100);
 	set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );
       
        set("no_busy",4);
        set("resistance/kee",40);
        set("resistance/gin",40+random(50));
        set("resistance/sen",40);     
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "西门玉看着躺在血泊中的高立和双双，冷笑道：谁背叛青龙会，这就是下场。嘿嘿。\n",
"西门玉冷笑吟道：七月中元日，地官降下，定人间善恶，道士于是日诵\n经，饿鬼囚徒，亦得解脱。\n",
        }) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/stone_5"); 
} 
void killed(object me){
        message_vision("$N不可置信般望着穿喉而过的银枪，喃喃道：怎么可能。。怎么可能，高立你 
明明。。已没有一点。。信心和勇气了。。。不会有。。\n", this_object()); 
        call_out("dead", 3, me);
        return;
} 
void dead(object me){
        object gao;
        if(present("gao li", environment()) && present("shuang shuang", environment())){
                gao = present("gao li", environment());
                this_object()->set_temp("last_damage_from",gao);        
                gao->do_leave(me);
        }
        this_object()->die();
}
/*
void die(){
        object *inv, ob, killer;
        int i;
        if(objectp(killer=query_temp("last_damage_from") ))
        if (killer->query("combat_exp")<4000000) {
                ::die();
                return;
                } 
// reason 1, people still get 5 color crystal quest
// reason 2, zombie exp is always high
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
           if(ob->query("name")== HIM"紫水晶"NOR) {
                        destruct(ob);
                }
        }
        ::die();
}
*/   
