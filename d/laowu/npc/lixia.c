 // keeper.c
inherit NPC;
string mark_you();
void create()
{
        set_name("��ϼ", ({ "lixia" }) );
        set("gender", "Ů��" );
        set("age", 24);
        set("per",5);
        set("long",
                
"���Ů�˿�������ʮ�����ˣ���������׳�����Σ�����ã�������\n");
        set("combat_exp", 1);
        set("chat_chance", 1);
        set("chat_msg", ({
"��ϼ˵�������Ұ����ƽ��ƾ�����ģ�\n",
        }) ); 
        set("attitude", "friendly");
        setup();
}
int accept_object(object who, object ob)
{
        int val; 
        val = ob->value();
        if( !val )
                return 0;
        if( val >= 100000 ) 
        {
        say( "��ϼ˵������λ" + RANK_D->query_respect(who)
                + "����ȥ���ӣ�����ը������⣩������\n");
        who->set("marks/��ϼ",1);
        return 1;
        }
        return 0;
} 
