#include <ansi.h>
inherit NPC;
void wake();
int cured(); 
void create()
{       set_name("小虎子", ({ "xiao huzi", "huzi" }) );
        set("long",                "他是一个年纪很轻的捕快，但已经浑身是血，奄奄一息了，\n不过似乎还可以救治（ｈｅａｌ），你真希望他在咽气之前能告诉你谁是凶手。\n");
        set("attitude", "heroism");
        set("age", 17);
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("con", 1);
        set("jing", 100);
        set("qi", 100);
        set("jing", 100);
        set("eff_jing", 100);
        set("eff_qi", 100);
        set("eff_jing", 100);
        set("title", "捕快");
        set("disable_type", HIR "<昏迷不醒>"NOR);
        set("combat_exp", random(10000)); 
        set_skill("unarmed", 70+random(100));
        set_skill("staff", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1); 
        setup();
                this_object()->disable_player(" <昏迷不醒>");
                this_object()->set_temp("is_unconcious",1);
                set_temp("block_msg/all", 1);
} 
void init()
{
    ::init();
        if(!this_player()->query_temp("libie/离别钩_发现尸体")) {
                call_out("die", 1, this_object());
    } else {
            call_out("die", 60, this_object());
    }
}
 
void heart_beat()
{
        object ob,me,room;
         
        room=environment();
        ob=this_object();
        me=ob->query("救人者");
        if(living(ob))
        if(present(me,room))
        {       
                
                if(!me->query_temp("libie/离别钩_救小虎子"))
                        {
                        me->set_temp("libie/离别钩_救小虎子", 1);
                message("vision",HIR"\n浑身浴血的小虎子哇的喷出一大口鲜血，大喝道：杨大哥快走。。 大哥快走啊！\n言罢小虎子又昏了过去。\n"NOR, me);
                        ob->disable_player(" <昏迷不醒>");
                        ob->set_temp("is_unconcious",1);
                        }
                else    {
                        message_vision(HIR"小虎子悠悠醒转，又吐出口淤血，紧握住$N的手挣扎道：\n"NOR, me);
                if( (me->query("combat_exp") > 800000))
                                {
                                message_vision(HIR"这位" + RANK_D->query_respect(me) + "，杨大哥危急，悦来，快去...悦..来..\n"NOR, me);
                                me->set("libie/离别钩_小虎子的警告", 1);
                                }
                        else    message("vision",HIR"多谢这位" + RANK_D->query_respect(me) + "了...你...真是...好人...但是...\n"NOR, me);
                        if( !me->query("libie/离别钩一"))
                                {
                                me->set("libie/离别钩一",1);
                                me->add("score", 100);
                    me->add("combat_exp", 500);
                                }
                        ob->die();
                        }
        }
        else ob->unconcious();
        ::heart_beat();
}     
