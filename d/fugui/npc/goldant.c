#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"金蚂蚁"NOR, ({ "gold ant", "ant" }) );
        set("long",
                "他身上穿着件金光闪闪的衣服，若不是脸上生着胡须，眼角有了皱纹，\n无论谁都会将他看成个五六岁的小孩子。\n");
        set("chat_chance",2);
        set("chat_msg", ({
                "金蚂蚁露出一种心弛神往的神色，喃喃道：“自古宝剑赠于英雄，想\n我老金纵横天下多年，却连那把不死之剑都无法得到，实在是不甘心啊。”\n",
                "金蚂蚁喃喃道：“华山的老太婆子会用什么剑，只有我才配得上她的宝剑。”\n",
                "金蚂蚁道：“我称手的寒玉剑不知被哪个泼皮偷走了。”\n"
                        })  ); 
        set("combat_exp", 300000+ random (100000));
        set("max_jing",1000);
        set("max_qi",2000);
        set("max_jing",1000);
        set("int",40);
        set("str",20);
        set("cor",30);
        
        set_skill("unarmed",100);
        set_skill("kongshoudao",100);
        map_skill("unarmed","kongshoudao");
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance_combat",25);
        set("chat_msg_combat",  ({
                        (:perform_action,"unarmed.yaozhan":),
                }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        int combat_exp,pot,score;
        if (ob->query("name")==HIG "长生剑"NOR) 
        {
                if( this_player()->query_temp("marks/红蚂蚁") && this_player()->query_temp("marks/白蚂蚁") &&this_player()->query_temp("marks/银蚂蚁") )
           {
                        if( !this_player()->query("m_success/巧过蚂蚁"))
                        {
                                this_player()->set("m_success/巧过蚂蚁",1);
                                combat_exp = 500 + random(500);
                                pot = 200 + random(200);
                                score = 100 + random(100);
                                tell_object(who,HIW"你被奖励了：\n\t\t" +
                                chinese_number(combat_exp) + "点实战经验\n\t\t"+
                                chinese_number(pot) + "点潜能\n\t\t" +
                                chinese_number(score) + "点评价\n" +NOR);
                                this_player()->add("combat_exp",combat_exp);
                                this_player()->add("potential",pot);
                                this_player()->add("score",score);
                        }
                        this_player()->delete_temp("marks/红蚂蚁");
                        this_player()->delete_temp("marks/白蚂蚁");
                        this_player()->delete_temp("marks/银蚂蚁");                     
                        write("金蚂蚁仰天长笑道：“好好好，既然你送我如此重宝，怎能再拦着你呢？”\n");
                        return 1;
                }
                command("thank "+this_player()->query("id"));
        }
        if (ob->query("name")==HIG "凝碧剑"NOR) 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/goldant",1);
                write("金蚂蚁呵呵笑道：“你送我如此重宝，我就不再拦你了。”\n");
                return 1;
        }
        if (ob->query("name")=="寒玉短剑") 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/goldant",1);
                write("金蚂蚁红红脸，笑道：“真是多谢了！想我金蚂蚁，居然被人偷了剑。 承蒙找回兵器，\n我就不再拦你了。”\n");
                return 1;
        }
        write("金蚂蚁摇了摇头，嘿嘿一笑道：“这种破铜烂铁，随便找找都是一箩筐。”\n");
        return 0;
}  
                                
