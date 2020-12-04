 // fat_bandit.c
inherit NPC;
void call_for_help();
void create()
{
        set_name("����������", ({ "bandit" }) );
        set("gender", "����");
        set("age", 36);
        set("long",
                "��һ��ְ����֣�Բ�����������������������й�µµ��ת��תȥ��\n");
        set("combat_exp", 500);
        set("score", 80);
        set("attitude", "friendly");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "\n���������˴�У��������ϵ�Ǯͨͨ��������\n",
                "\n�������������ﲻǬ��������������\n",
                (: call_for_help :),
        }) );
 set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);

        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("coin", 50);
} 
void call_for_help()
{
        object ob; 
        if( query("called_help") || present("bandit chief", environment()) ) return;
        set("called_help", 1);
        command("say ����ģ�����צ��̫Ӳ....");
        say("���������˴�У��ϴ��ϴ��ֵܳŲ�ס����\n");
        ob = new(__DIR__"bandit_chief");
        ob->move(environment());
        ob->start_help();
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
        if (ob->query("class") != "bandit")
        {
                message_vision("$N��������������������ֵ��ǣ�������ڣ���\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N������Ц�����ֵܽ����ֵ������ҽ��᣿\n", this_object() );
        }
        return;
}     