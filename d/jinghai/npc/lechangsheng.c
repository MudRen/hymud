inherit NPC;

void create()
{
        set_name("�ֳ���", ({ "le changsheng", "le", "changsheng" }) );
        set("gender", "����" );
        set("title","������");
        set("age", 38);
        set("attitude", "peaceful");

        set("long", "����һλ��ò��ª�����꺺�ӣ�һ�����ࡣ
û���˼���������Ц�ݣ�������
����������������ɱ��֮һ������\n");

        set("combat_exp", 4000000);
        set("str", 60);
        set("per", 15);
        set("max_qi",3500);
        set("qi",3500);
        set("max_jing",3500);
        set("jing",3500);
        set("max_sen",3500);
        set("sen",3500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("atman", 5000);
        set("max_atman", 5000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 300);

        set_skill("jingyiforce",300);
        set_skill("demon-blade",280);
        set_skill("literate",300);
        set_skill("unarmed",260);
        set_skill("dodge",280);
        set_skill("parry",280);
        set_skill("force",300);
        set_skill("doomsword",300);
        set_skill("chilian-shenzhang",300);
        set_skill("softsword",280);
        set_skill("nine-moon-sword",300);
        set_skill("luohua-jian",300);
        set_skill("sword",300);
        set_skill("feixian-sword",300);
        set_skill("bat-blade",300);
        set_skill("fengyu-piaoxiang",280);

        map_skill("force","jingyiforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","nine-moon-sword");
        map_skill("sword","nine-moon-sword");

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}

 

