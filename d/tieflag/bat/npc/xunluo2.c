#include <ansi.h>
inherit NPC;
void create()
{ 
        set_name("Ѳ������", ({ "xunluo shiwei", "shiwei"}) );
        set("long", "����һλ����ר�ŵ���Ѳ��֮���������\n");
//      set("attitude", "aggressive");
        set("class","bat");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
//      set("str", 20+random(20));
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 300000+random(200000));
        set_skill("bat-blade", 80+random(100));
        set_skill("blade", 80+random(100));
        set_skill("parry", 80+random(100));
        set_skill("dodge", 80+random(100));
        set_skill("dodge", 80+random(100));

        map_skill("parry"  , "bat-blade");
        map_skill("blade"  , "bat-blade");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
        (: perform_action, "dodge.huanyinqianchong" :),
        }) ); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangdao")->wield();
} 
void init()
{
        object ob;
        if( interactive(this_player()) && !is_fighting() && this_player()->query("class")!="bat") {
 message_vision("\n$N��Ȼ��$n��ɭɭһЦ���Ҵ�������������������ô��\n",
this_object(),this_player());
        kill_ob(this_player());
        }
        ::init();
}    
