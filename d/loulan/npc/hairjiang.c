 inherit NPC;
void create()
{
        set_name("��ͷ��ʦ��", ({ "hair oldman" }) );
        set("gender", "����" );
        set("age", 63);
        set("long", "һ���ڹ���С����������ͷʦ�����������۱��Ѿ��Եغ�������\n");
        set("combat_exp", 1000);
        set("str", 27);
        set("force", 200);
        set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ͷ��ʦ������˫�ۣ�����ظ��׷ɷ������������㷢��\n",
        }) );
        set("inquiry", ([
                "��ͷ" : "�ţ���ͷ������ȥ����������º����Ұ������ᡣ\n",
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
}   
