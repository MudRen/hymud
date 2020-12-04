#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("血头陀", ({"xue toutuo","toutuo"}) );
        set("gender", "男性" );
        set("nickname", HIR"噬人狼"NOR);
        set("long", "一个看来就象是个古洪荒时的野蛮人，嘴角似乎还带着未干的血迹。\n");
        set("attitude", "friendly");
/*      set("max_jing", 600);
        set("max_qi", 600);
        set("max_jing", 600); */
        set("age", 20+random(10));
    set("str", 30+random(20));
        set("cor", 25);
        set("cps", 15);
        set("combat_exp", random(500000)+600000);
    set("force_factor", 20+random(100));
    set("max_neili", 300);
    set("force", 500+random(500));
        create_family("狼山", 4, "弟子");
        set_skill("blade", 70+random(10));
        set_skill("parry", 70+random(10));
        set_skill("dodge", 70+random(10));
        set_skill("move", 70+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
                "血头陀舔了舔嘴唇：好几天都没吃到新鲜的人肉了！\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/pifeng")->wear();
        carry_object(__DIR__"obj/wolfblade")->wield(); 
        add_money("gold", random(6));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "wolfmount")
        {
                message_vision("$N冷冷的看着你：“想上狼山，你没有机会了。”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else
        {
                message_vision("$N阴阴笑道：＂老弟，没带什么肥羊孝敬爷爷？＂\n",this_object());
                return;
        }
        return;
}     
