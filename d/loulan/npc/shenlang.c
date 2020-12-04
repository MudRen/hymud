#include <ansi.h>
inherit NPC;
int give_mission();
void create()
{
        set_name("沈浪", ({ "shen lang","shen" }) );
        set("gender", "男性" );
        set("title", "情侠" );
        set("nickname", HIC"仗剑江湖载酒行"NOR );
        set("long",
                "一个剑眉星目的英俊少年，嘴角微微向上，不笑时也带着三分笑意，神情\n虽然懒散，但那种对什么事都满不在乎的味道，却说不出的令人喜欢。 \n"
                );
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("class", "emei");
        set("difficulty", 20);
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                (:perform_action,"sword.tianrenheyi":),
                (:perform_action,"dodge.luoyeqiufeng":),
        }));
        set("age", 23);
        set("str", 100);
        set("cps", 100);
        set("int", 100);
        set("per", 100);
        set("cor", 40);
        set("agi", 80);
        set("combat_exp", 8000000);
        set("force", 8000);
        set("max_force", 8000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force_factor", 200);
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set("chat_chance", 2);
        set("inquiry",([
           "朱七七" : (: give_mission :),
                ]) );
        set("chat_msg", ({
                "沈浪叹了口气，喃喃自语：七七，你在哪里？ \n",
                }));
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
      set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",300);
	set_skill("feixian-sword",350);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
 set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );               
        setup(); 
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
int give_mission()
{
        object me,jade;
        object ob;
        me=this_player();
        
        if (ob=present("bai feifei", environment(this_object())))
        {
                message_vision("$N扭过脸看着$n，叹了口气，默然无语。\n",this_object(),ob);
        }
        else if( userp(me) && me->query_temp("marks/chai_notify_bai"))
        {
                if(!me->query_temp("marks/chai_get_jade"))
                {
                        command("consider");
                        message_vision("$N突然转过头，目光如炬看着$n，突然微微一笑：你不是方心骑......",this_object(),me);
                        message_vision("$N掏出一块玉璧，笑道：英雄，请把这玉璧交给七七，她自然知道我一切无恙。\n",this_object());
                        jade = new(__DIR__"obj/jade");
                   jade->move(me);
                        me->set_temp("marks/chai_get_jade",1);
                }
                else
                {
                        message_vision("$N笑道：这位英雄，可曾见到七七，她一切可好？\n",this_object());
                }
        }
        else
        {
                message_vision("$N脸上露出一丝甜甜的微笑：七七，她是个很怪的女孩子......\n",this_object());
        }
        return 1;
} 
int accept_object(object me, object obj)
{       
        object npc;
        object book;
        object *inv;
        int i;
        int j;
        j = 0;
        npc = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="方心骑" && (int)inv[i]->query("equipped"))
                        {
                                j = 1;
                        }
                }
        }
        if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "樟木镶金箱" && j == 1)
        {
                message_vision(HIY"$N神色凝重看着箱子中的白飞飞，长长叹了口气．．．．\n"NOR,npc);
                message_vision(HIY"$N掏出一本绢册，肃然道：这是我父＂九州王＂沈天君毕生心血，你可以参详一下！\n"NOR,npc);
                book = new(__DIR__"obj/book2");
                if (book) book->move(me);
           if (!me->query("m_success/楼兰孽缘"))
                {
                        me->add("score",300);
                        me->set("m_success/楼兰孽缘");
                }
                call_out("leave",2,me);
                return 1;
        }
        else
                return notify_fail("沈浪摇头微笑，默然不语。\n");       
} 
void leave(object me)
{
        object ob;
        if (living(this_object()) && environment(me) == environment())
        {
                message_vision(HIY"$N霍然长身而起，背起白飞飞，苦笑了声道：不能再装了，我这就去解救七七\n和王怜花，他日有幸，必能重逢！\n"NOR,this_object(),me);
                message_vision(HIY"长啸声中，$N纵身离去！\n"NOR,this_object());
                destruct(this_object());
        }
        remove_call_out("leave");
} 
