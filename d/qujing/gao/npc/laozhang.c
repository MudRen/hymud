//Cracked by Roath

inherit NPC;

void create()
{
       set_name("����", ({"lao zhang", "zhang", "lao"}));
       set("title", "���կ�ܼ�");
       
set("long","���������կ������չ��������Ĺܼ�,��������ޱ�,һ�ֵ��������ѵ�.\n");
       set("gender", "����");
       set("age", 37);
   set("str", 30);
       set("attitude", "aggressive");
       set_skill("blade",380);
        set_skill("parry", 80);
   set_skill("dodge", 80);
   set_skill("unarmed", 80);

       set("max_qi", 700);
   set("bellicosity", 5000);
       set("max_jing", 600);
       set("neili", 350);
       set("max_neili", 300);
       set("force_factor", 20);
       set("combat_exp", 750000);
       set("combat_exp", 750000);
setup();
carry_object("/d/obj/weapon/blade/yanblade")->wield();
carry_object("/d/obj/armor/jinjia")->wear();
add_money("gold", 5);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "���źȵ�����������" + RANK_D->query_rude(ob) +
"���ҿ��㲻����ˣ�\n");
}
