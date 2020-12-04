 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("文士", ({ "wen shi", "zhen zhen"}) );
    set("gender", "男性" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "他平卧在雪地上，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的。鼻息间似乎已没有气息，不知道还有没有救。\n"
        );
    set("max_jing", 3000);
    set("max_qi", 3000);
    set("max_sen", 3000);
    set("eff_jing", 30);
    set("eff_qi", 30);
    set("eff_sen", 30);
    set("jing", 3000);
    set("qi", 3000);
    set("sen", 3000);
    set("max_neili", 3000);
    set("neili", 3000); 
    set("combat_exp", 9999999);
         set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("disable_type", HIR "<昏迷不醒>"NOR); 
        set("cured", 0);
        set("answered", 0);
    setup();
    carry_object("/clone/misc/cloth")->wear();
    
        this_object()->disable_player("<昏迷不醒>");
    this_object()->set_temp("is_unconcious",1); 
} 
void init(){
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) { 
                call_out("do_leave", 120);
        } 
        if(find_call_out("do_selfcure") == -1 && !query("cured")) {
                call_out("do_selfcure", 30);
        }
} 
void do_selfcure(){
        if(query("cured")) {
                return;
        }
        this_object()->enable_player();
        message_vision("$N的手臂缓缓地动了一下。\n", this_object());
        message_vision("$N努力地鼓着最后的精力，站立了起来。虽然站的不稳，但他是站立着的。\n",
                        this_object());
        set("long", 
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n"
        );
        set("cured", 1);
}
void do_leave(){
   if(environment(this_object())->query("meishan")) {
                message_vision("\n$N拖着沉重的步伐缓缓离去，雪地上留下一溜深深的足迹。\n", this_object());
                destruct(this_object());
        }
} 
int Cured(object me){
        if(!query("cured") && !me->query("marks/killed_mei")) {
                message_vision("$N极为困难的挣扎着坐了起来，定定地望着$n道：“你知道我是谁吗。” 
（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ）\n", 
                                this_object(), me);     
                set("long", 
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n"
                );
                add_action("do_answer", "answer");
                set("cured", 1);
                this_object()->enable_player();
                remove_call_out("do_leave");
                call_out("do_leave", 60);
        } else {
                message_vision("$N微微一笑道：“多谢救命之恩。”\n", me);
                message_vision("\n$N拖着沉重的步伐缓缓离去，雪地上留下一溜深深的足迹。\n", this_object());
                destruct(this_object());
        }
} 
int do_answer(string arg) {
        object me;
        me = this_player();
        if(!arg || (arg != "yes" && arg != "no")) {
                return 0;
        }
        if(query("answered")){
                return 0;
        }
        if(arg == "yes") {
                message_vision("$N微微一笑道：“阁下就是七妙神君。”\n", me);
                message_vision("$N道：“好！既然如此，阁下一定也知道到哪里找我。今日一别，它日必当重报。”\n",
                                this_object());
                me->set("marks/梅山民", 1);
           do_leave();
        } else if(arg == "no") {
                message_vision("$N神色茫然地摇了摇头。\n", me);
//              if(me->query("title") == "普通百姓") {
                        message_vision("$N注视着$n，笑容自嘴边漾开。$N说道：“你如愿跟随着我，可到风云城外竹林中找我”\n", this_object(), me);
                        tell_object(me, this_object()->name() + "又道：“入竹林，行一步，推开竹丛（ｐｕｓｈ　ｂａｍｂｏｏ）向东北行，然后敲门即可。”\n");
                        me->set("marks/梅山民", 3);
                        do_leave();
//              } else {
//                      message_vision("$N道：“在下七妙神君，它日有缘定当重谢。”\n", this_object());
//                      me->set("marks/梅山民", 2);
//                      do_leave();
//              }
        }
        return 1;
} 
void die(){
        object me;
        if(objectp(me=query_temp("last_damage_from") )) {
                me->set("marks/killed_mei", 1);
        } 
        ::die();
} 
