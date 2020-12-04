 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","ʱ","��","��","��","��","��","��","��","��","ʷ"});
        set_name("һ"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        create_family("������", 18, "����");
        set("long", "���Ƕ����µĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(300000)+2000000);
        set("attitude", "friendly");
        set("neili",500);
        set("max_neili",500);
        set("cps",80);
        set_skill("hammer", 70+random(100));
        set_skill("tiexue-hammer",random(100)+150);
        set_skill("dodge",200);
        set_skill("move",180);
        set_skill("force",200);
        set_skill("shaolin-shenfa",150);
        set_skill("jingang-quan",150);
        map_skill("unarmed","jingang-quan");
        map_skill("dodge","shaolin-shenfa");
        map_skill("hammer", "tiexue-hammer");
        map_skill("parry","tiexue-hammer");
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵������ʱ���˰ɣ�\n",
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                name()+"Ц�����ڶ�������Ұ��\n",
                (: perform_action, "hammer.fanbei" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("force_factor",40);
   setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}
void init()
{
        add_action("do_get","get");
        ::init();
} 
/*int do_get(string arg)
{
string what;
if(!arg) return 0;
if(sscanf(arg,"%s",what) !=1) return 0;
if(what== "all" || what== "gu" )
{
message_vision("$N��$n���һ�����󵨣����Ҵ����¶��������⣡\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}*/ 
int do_get(string arg)
{
if(!arg) return 0;
message_vision("$N��$n˵�������ﲻҪ�����Ҷ���\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}       