 inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
    set_name(HIR"烈火孽龙"NOR, ({ "dragon lord", "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 200);
        set("reward_npc", 1);
        set("difficulty", 40);
        
        
        set("long", 
"这是一条全身赤红，吸天地之间的火气而长大的孽龙！
它全身散发着赤红色的火焰\n");
        
    set("str", 50+random(20));
        set("cor", 52);
        set("cps", 22);
        set("no_curse",1);
        set("max_qi", 330000);
        set("max_jing", 320000);
        set("max_neili", 320000);
        set("neili", 320000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(80));
        set("chat_msg_combat", ({
        (: big_blowing :)
        }) ); 
        set("combat_exp", 2000000+random(1000000));
                set("bellicosity", 3000 );
        
    set_temp("apply/attack", 200+random(400));
    set_temp("apply/damage",200+random(200));
        set_temp("apply/armor", 340+random(500)); 

           set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
       set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

       set_skill("dragon", 1600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
 }) );
        
        setup();
//    carry_object("/obj/money/thousand-cash")->set_amount(5);
    carry_object(__DIR__"obj/book")->set_amount(1);
}
int big_blowing() 
{
remove_call_out("hurting");
message_vision( HIR "\n\n$N从黑水里深深地吸入一口火气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n"NOR,
this_object());
call_out("hurting",random(10)+2);  
        return 1;
} 
int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n$N吐出一股炽可焚金的火焰．．整个天地似乎都被燃烧着！！！\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_fire");
        if(dam <0) dam = 0;
        inv[i]->receive_wound("qi",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
void die()
{
        object book;
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(!me->query("m_success/孽龙"))
        {
                me->set("m_success/孽龙",1);
                me->add("combat_exp",50000);
                me->add("score",500);
                tell_object(me,WHT"\n恭喜你，你的名字将在武林中传颂。\n"NOR);
                tell_object(me,WHT"你完成了屠龙任务,你的评价上升了!!!\n\n"NOR);
        }
        ::die();
}     
