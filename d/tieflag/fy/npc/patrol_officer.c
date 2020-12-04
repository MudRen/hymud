 // jianu.c
#include <ansi.h> 
inherit NPC; 
void create()
{ 
        set_name("Ѳ���ڹ�", ({ "patrolling officer" }) );
        set("long","���ܹܷ��Ƴ�����ΰ�,ר�žв��������˵Ĵ�ͽ��\n");
        set("attitude", "heroism");
//      set("vendetta_mark", "authority");
        set("class","fighter");
        set("str", 70+random(30));
        set("cor", 40);
        set("cps", 25);
        set("combat_exp", 3000000+random(3000000));
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luohualiushui" :),
        }) );
        set_skill("unarmed", 200+random(100));
        set_skill("sword", 200+random(50));
        set_skill("parry", 200+random(100));
        set_skill("dodge", 200+random(100));
        set_skill("move", 600+random(100));
        set_skill("doomsteps",160);
        set_skill("changquan",200);
        set_skill("lonely-sword",300);
        map_skill("sword","lonely-sword");
        map_skill("unarmed","changquan");
        map_skill("dodge","doomsteps");
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);
        setup();
        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}   
int heal_up()
{
        if( environment() && !is_fighting() ) {
           call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
                HIW + name() + "�ȵ�����ʲô�����ٿ�����һ��ץ������\n"
                + name() + "һת�������ǵ��뿪�ˡ�\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}     
