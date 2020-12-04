 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("卫天鹰", ({ "wei tianying", "wei"}) );
        set("gender", "男性" );
        set("age", 34);
        set("per", 35);
        set("agi",30);
        set("int",30);
        set("class","legend");
        set("attitude","friendly");
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor",30);
        set("nickname", HIR"魔刀"NOR);
        set("title", "青龙会 十二煞");
        set("long","一身黑衣，鹰爪般干枯的手紧紧握着把刀，嘴角不时露出嘲弄的笑容。\n");
        set("combat_exp", 2900000);
        
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
                "卫天鹰嘴角露出残酷的冷笑，嘿嘿道：一块破布，就叫这帮蠢猪连钱\n带命送上门来，真是有趣。\n",
                "卫天鹰嘿嘿冷笑道：天上白玉京，现在趴在地上跟烂泥一样，幺妹，\n还不进去宰了他。\n",
        }) );
        set("inquiry",([
        "孔雀图"  :"嘿嘿。。这个么不能说，不能说。。\n",
        "design"  :"嘿嘿。。这个么不能说，不能说。。\n",
        "白玉京"  :"什么天上白玉京，碰到我卫天鹰不还是地上一堆烂泥。。哈哈。。\n",
        "bai"  :"什么天上白玉京，碰到我卫天鹰不还是地上一堆烂泥。。哈哈。。\n",
        "袁紫霞"  :"幺妹最近好象有点怪。。。莫非。。。\n",
        "yuan"  :"幺妹最近好象有点怪。。。莫非。。。\n",
                ]) ); 
        setup();
        carry_object(__DIR__"obj/black_cloth")->wear();
        carry_object(__DIR__"obj/long_blade")->wield();
        add_money("gold", 5);
} 
void init()
{
        object ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
} 
int greeting(object ob)
{       
        object room;
        object hotel;
        room = find_object("/d/chenxiang/fyyard");
        if(!objectp(room)) room = load_object("/d/chenxiang/fyyard");
        hotel = find_object("/d/chenxiang/tingfengge");
        if(!objectp(hotel)) hotel = load_object("/d/chenxiang/tingfengge");
        
        if (room == environment(this_object()) && ob->query_temp("marks/longlife_getmap"))  
        {
                message_vision("$N阴阴的笑着：杀了我的手下，偷了我的珠宝。胆子不小啊！\n",this_object());
           this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
                return 1; 
        }
        if( hotel == environment(this_object()) && ob->query_temp("marks/longlife_getmap") ) {
                this_object()->remove_all_killer();
                ob->remove_all_killer();
        }
        return 0;
}   
