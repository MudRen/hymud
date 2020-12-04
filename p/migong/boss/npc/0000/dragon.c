inherit BOSS;
#include <ansi.h>
int big_blowing();
int hurting();
void create()
{
        set_name(HIR"烈火孽龙"NOR, ({ "dragon lord", "dragon" }) );
        set("vendetta_mark","dragon");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        
        set("long", 
"这是一条全身赤红，吸天地之间的火气而长大的孽龙！
它全身散发着赤红色的火焰\n");
        
        set("str", 100+random(20));
        set("con", 52);
        set("dex", 20);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("resistance/qi",40);
        set("no_curse",1);
        set("max_qi", 90000);
        set("max_jing", 90000);
        set("neili", 90000);
        set("max_neili", 90000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 9000000);
        set("bellicosity", 3000 );
        
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",100);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",800);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
(: big_blowing :),
	(: big_blowing :),
 }) );


  set("bonus", random(1000)+500);
        setup();
}
void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
int big_blowing() 
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n$N"HIR"深深地吸入一口火气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n"NOR,
        this_object());
        hurting();
        start_busy(3+random(2));
} 
int hurting()
{
        int i;
        int dam;
        object *inv;
        
        message_vision( HIR "\n\n$N"+HIR"吐出一股炽可焚金的火焰．．整个天地似乎都被燃烧着！！！\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = (random(2000)+1000) * (1 - inv[i]->query_temp("apply/reduce_fire"));
        if(dam <0) dam = 0;
        inv[i]->receive_wound("qi",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
