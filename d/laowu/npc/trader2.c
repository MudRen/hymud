 inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("�ض�����", ({ "guandong haoke", "haoke" }) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�Ӱ�ɽ��ˮ���Ĵ󺺣����´���һȺ�������ˡ�\n");
        set("combat_exp", 3200000);
        set("attitude", "aggrensive");
        set("class","knight");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ض��󺺺�ˬ�������Ц��\n",
        }) );
        
        set("force",1200);
        set("max_neili",1200);
        set("force_factor", 30);
              
        set_skill("unarmed", 580);
        set_skill("dodge", 580);
        
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/xuechang");
} 
