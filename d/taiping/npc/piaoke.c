 inherit NPC;
void create()
{
        set_name("�ϳ�����", ({ "buhua"}) );
        set("title","���ο�");
        set("gender", "����" );
        set("long", "����һλ�ʷ����ֵĴ��οͣ��ڽ�����ҲС���������ǡ�Ѫ���ھ֡��ĸ������ϳ�������\n");
        set("age",47);
        
        set("combat_exp", 6000000);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ϳ������������ô������Щˮ�������ۼң�����Ҫ���õ���Ѫū���\n",
        }) );
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        
        ]) );           

        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/whip")->wield();
}   
