 inherit NPC;
int direct();
void create()
{
        set_name("������", ({ "wurong" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long",
                "һ��ȫ����۵�Ů���ӣ���\n");
        set("combat_exp", 1800000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "������ָ�ż���������㣮������Ĳ����ߣ�����\n",
                "�����ݺߵ�����ԭһ��죬����İ��ң���\n",
        }) );
        set("inquiry", ([
                "ʯ����" : (: direct :),
                "master guanyin" : (: direct :) 
        ])); 
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yaozhan" :),
            }) ); 
    set_skill("unarmed", 100);
    set_skill("blade", 150);
    set_skill("force", 100);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("kongshoudao", 120);
    set_skill("ghosty-force", 150);
    set_skill("ghosty-steps", 150); 
    map_skill("unarmed", "kongshoudao");
    map_skill("blade", "wind-blade");
    map_skill("force", "ghosty-force");
    map_skill("parry", "wind-blade");
    map_skill("dodge", "ghosty-steps"); 
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth")->wear(); 
} 
int direct()
{
        object me;
        object room;
        me = this_player();
        message_vision("$N��$n��Цһ�����������ʦ����
���Ҿͳ�ȫ�㣡��\n",this_object(),me);
        room = load_object("/d/guanyin/mirror");
        message_vision("$N����һ�ɣ������˲����ˣ�\n",me);
        me->move(room); 
        if(!me->query("m_success/�ɼ�ʯ����"))
        {
                me->set("m_success/�ɼ�ʯ����",1);
                me->add("score",50); 
        } 
        return 1;
}      
