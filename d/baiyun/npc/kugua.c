 inherit NPC;
void create()
{
        set_name("��ϴ�ʦ", ({ "kugua dashi","kugua" }) );
        set("gender", "����" );
        set("class", "shaolin");
        set("age", 52);
        set("str", 26);
        set("cor", 14);
        set("cps", 29);
        set("int", 25);
        set("long", "һ����ò�������ü���׵��Ϻ��С���Ȼ��ϴ�ʦ��������������ĳ���ȴΪ\n������˫�������������Ƶ���ի�����������¡�\n");
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ϴ�ʦ����ն��̨���˼�Ȧ����ɫ�������԰ף���������������ս��������\n",
        }) );
        set("attitude", "friendly");
        set("max_neili", 500);
        set("force", 500);
        set("force_factor", 5);
        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say �������գ����������Ѹߣ���ͨ�����ʩ������Ц��\n");
        return 0;
}       
