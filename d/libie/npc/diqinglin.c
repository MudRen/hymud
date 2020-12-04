#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("狄青麟", ({ "di qinglin","di","qinglin" }) );
        set("long",
                "一身雪白的衣裳，一尘不染；一张苍白清秀的脸上，总是带着冷冷淡淡的
的表情。这就是视功名富贵如尘土、却把名马美人视如生命的狄小侯爷。\n"); 
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 20);
        set("age",27);
        set("str", 100);
        set("cor",50);
        set("agi",50);
        set("cps",75);
        set("con",70);
        set("title", HIY"世袭一等侯"NOR); 
        set("combat_exp", 3000000+random(1000000));
        set("max_neili",2000);
        set("force",2000);
        set("force_factor",50);
         
        set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 50);
        set("combat_exp", 9800000);
        set("score", 180000);

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
"狄青麟轻轻抖了下一尘不染的雪白绸衣，嘴角突然泛起一种冷酷的笑意。”\n"
}) );

        setup(); 
        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
        carry_object(__DIR__"obj/letter2");
} 
void init()
{
                if( !query_heart_beat(this_object()) ) set_heart_beat(1);
//              ::init();
} 
void heart_beat()
{
        object di,yang,room,ying;
        int rival;
        
        ::heart_beat();
        di=this_object();
        room=environment();
        yang=present("yang zheng",room);
        if(query("yang_die"))
        {
                ying=present("ying wuwu",room);
                di->start_call_out( (: call_other, di, "kill_ying" ,di,ying:), 3);
                delete("yang_die");
        }
        if(rival=query("begin_rival"))
        {
                if((rival==4)||(rival==3))
                        command("nod");
                if(rival==2)
                        command("say 只要你能用你手里的兵器打败我，镖银就是你的，我的命也是你的，你都可以带走。");
                if(rival==1)
                {
                   di->kill_ob(yang);
                        yang->kill_ob(di);
                        call_out("do_busy",5,di);
                        delete("begin_rival");
                } 
                yang->add("begin_rival",-1);
        } 
        
        
        if (objectp(yang))
        if (di->is_fighting(yang))
        if (random(3)==1&&!yang->query_busy()&&query("do_busy"))
        {
                message_vision(RED"\n$N刀尖一转，刺在了$n左臂的曲池穴上，$n只觉左半身发麻，动也不能动了。\n"NOR,di,yang);
                yang->start_busy(200);
        }
} 
int do_busy(object di)
{
        di->set("do_busy",1);
        return 1;
} 
int kill_ying(object di,object ying)
{
        object room,who;
        
        room=environment(); 
        if(objectp(ying))
        {
                message_vision(CYN"$N信步走到$n身后，什么话也没说，突然反手一刀，由$n
背后刺入$p的心脏。\n"NOR,di,ying);
                who=ying->query("busy_object");
                message_vision(CYN"$N露出一种古怪恐惧的眼神，倒在$n身旁，用尽最后一丝内力，
为$n解开穴道。\n"NOR,ying,who);
                who->start_busy(1);
                ying->die();
                call_out("kill_who",3,di,who);
                return 1;
        }
        return 0;
} 
int kill_who(object di, object who)
{
        message_vision(HIY"$N对$n微笑道：“我说过，只要能够胜过我，什么你都可以拿去。”\n"NOR,di,who);
        di->kill_ob(who);
        who->kill_ob(di);
        return 1;
}
        
void die()
{
        object yang,room,me,yangcorpse,ying;
         
        room=environment();
        
        yang=present("yang zheng",room);
        ying=present("ying wuwu",room);
        if(objectp(yang))
        {
                yang->set("killed_di",1);
                ying->set("sad_leave",1);
        }
        else
                if(me=room->query("结局人物"))
        {
                if (me->query("libie/离别钩_杀死狄青麟")!=1 
                && me->query("libie/离别钩_杀死狄青麟")!=2) {
                        me->add("score",200);
                        me->add("potential",200);
                        me->add("combat_exp",10000);
                }
                me->set("libie/离别钩_杀死狄青麟",1);
                
        }
        ::die();
}  
int return_home(object home)
{
        home=environment();
        if(!present("yang zheng",home))
   {
                destruct(this_object());
                home->delete("结局人物");
        }
        return 1;
}  
