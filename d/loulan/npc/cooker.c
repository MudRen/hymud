 inherit NPC;
void create()
{
        set_name("����", ({ "cooker" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һ�������Ͻ��ǻʹ����ŷ��Ĵ���������������ץ��¥���ع������ղˡ�\n");
        set("combat_exp", 1000000);
        set("force", 500);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force_factor", 12);
        set_temp("apply/attack", 150);
        set_temp("apply/dodge",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������䤱���æ�����������㣬��ζ���硣����\n",
        }) );
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
