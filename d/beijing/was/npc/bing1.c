inherit NPC;
void create()
{
        set_name("�ɹŹٱ�", ({ "guan bing", "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long", "�ɹ����������¾�����һ����\n"
                   "���׳���������ࡣ\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("dex", 20);
        set("combat_exp", 20000);
        set("shen_type", 1);
        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("club", 140);
        set_skill("force", 140);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);
                set("max_qi", 1000);
        set("max_jing", 1500);
        set("max_neili", 1800);
        set("neili", 1800);
        setup();
        carry_object(__DIR__"obj/spear")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}
