 // beggar.c
inherit NPC; 
void create()
{
        set_name("����ؤ", ({ "old beggar","beggar" }) );
        set("gender", "����" );
        set("age", 63);
        set("long", "һ��������˪֮ɫ��������������ؤ��\n");
        set("combat_exp", 100000);
        set("str", 30);
        set("force", 500);
        set("max_neili", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ؤ˵�������ĵĴ�ү�ġ� ������л��ӵļ���Ǯ�ɡ�\n",
                "����ؤ������ش��˸���Ƿ��Ҫ�����ұ���̫��϶�Ҳȥ��ɽ����
ɱ����Щ�߹ٶ�ԡ�\n",
                (: random_move :)
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
} 
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"������С������뿪��\n");
        return 0;
}
 
