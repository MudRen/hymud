 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("胖公子", ({ "fat man", "man" }) );
        set("gender", "男性" );
        set("age", 32);
        set("str", 30);
        set("int", 40);
        set("cor", 40);
        set("cps", 1);
    set("long",
"凉棚下坐着个人，这个人不但胖，而且胖得奇蠢无比，不但蠢，而且蠢得俗
不可耐，看起来简直就像是块活动的肥猪肉，穿着打扮却像是个暴发户，好像
恨不得把全副家当都带出来，好像生怕别人不知道他有钱。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
  set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        

         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
                "胖公子愁眉苦脸的叹着气，道：“再这么样瘦下去，怎么得了呢？”\n",
                "胖公子忽然长长叹了口气，道：“我知道最近我一定又瘦了，而且瘦了不少。”\n",  
                "胖公子用一双又白又嫩，保养得极好的手，拿起一个馒头，带着种充满爱怜
的表情，看着馒头里夹着的五花肉，然后一口咬下去。\n",
                "胖公子袖子闪了闪，不知怎么的，一只飞过的苍蝇掉在地上。\n",
        }));

        setup();
        carry_object(__DIR__"obj/fatcloth")->wear();
        carry_object(__DIR__"obj/chickbone");
//        carry_object("/obj/armor/boots")->wear();
        carry_object("/d/feitian/npc/blackblade")->wield();
        carry_object(__DIR__"obj/mantou");
} 
void init(){
   ::init();
        add_action("do_look", "look");
        add_action("do_kill", "kill");
} 
int do_look(string arg) {
        if(arg == "fat man" || arg == "man"){
                write("凉棚下坐着个人，这个人不但胖，而且胖得奇蠢无比，不但蠢，而且蠢得俗\n");
                write("不可耐，看起来简直就像是块活动的肥猪肉，穿着打扮却像是个暴发户，好像\n");
                write("恨不得把全副家当都带出来，好像生怕别人不知道他有钱。\n");
                write("他看起来约三十多岁。\n");
                write("他长的"+WHT"心宽体胖"NOR+"，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
                write("他精神饱满，正处于巅峰状态。\n");
                write("他身穿"+BLU"绸缎袍"NOR+"(Silk cloth)\n");
                return 1;
        }
        return 0;
        
} 
int accept_object(object me, object ob){
        if(ob->query("food_remaining")){
                message_vision("$N接过" + ob->name()+"仔细的吃了进去，然后满意的叹了口气。\n", this_object());
                if(ob->query("name") == YEL"叫花子鸡"NOR){
                        message_vision("$N幽幽的叹了口气道：“\n", this_object());
                }
                return 1;
        }
        if(ob->query("name") == "黑棋子" || ob->query("name") == "白棋子" ){
                if (ob->query("id") == "go piece"){
                message_vision("$N用白嫩的手接过"+ob->query("name")+"点头叹道：“不错，不错，中原的暗器也算见识了一番。\n",
                                this_object());
                message_vision("既然你这么有心,不教你几手也过意不去。”\n", me);        
                me->set("free_learn/perception", 1);
                return 1;
                }
                return 0;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/perception")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$N笑眯眯的对$n说道：“你一天能吃五只鸡吗？那叫花子鸡的味道真不错。“\n", 
                        this_object(), ob);
        else 
        message_vision("$N打了个饱嗝，笑眯眯的对$n说道：“在下是文人，只爱琴棋书画，不谈刀剑之事“。\n", 
                        this_object(), ob);             
                return 0;
    }
} 
int do_kill(string arg) {
        if(arg == "fat man" || arg == "man"){
        message_vision("$N同情地看了$n一眼说，你忘了先问一下我是谁了。\n",this_object(),this_player());
        message_vision("$N郑重地告诉$n：“我叫"+HIW"唐胖"NOR+"，唐老鸭的"+HIW"唐"NOR+"，胖子的"+HIW"胖"NOR+"。。。！\n"NOR,this_object(),this_player());
        message_vision("唐胖耸了耸肩,不知哪儿来的一根鸡骨头“啪“地打在$N的肩井穴上。\n",this_player());
        this_player()->start_busy(1);
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());  
        return 1;
        }
        return 0;
}   
int wieldblade()
{
command("unwield all");
command("wield blade");
perform_action("blade.banlanwushi");
command("unwield blade");
command("wield bone");
return 1;
}